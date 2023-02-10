import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
#IEX
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    id = session["user_id"]
    """Show portfolio of stocks"""
    portofolio = db.execute(
        "select symbol, name, price, sum(shares) as shares from purchased_stock where user_id = ? group by symbol", id)
    saldo = db.execute("select * from users where id = ?", id)[0]
    print(saldo)
    return render_template("index.html", portofolio=portofolio, balance=saldo)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    id = session["user_id"]
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        elif lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 400)
        elif not request.form.get("shares"):
            return apology("must provide whole number of shares", 400)

        current_symbol = lookup(request.form.get("symbol"))
        print(current_symbol)
        shares = request.form.get("shares")
        if ("-" in shares) or (shares.isalpha() == True) or ("." in shares):
            return apology("must provide whole number of shares", 400)

        balance = db.execute("SELECT cash FROM users WHERE id = ?", id)[0]
        print(balance)
        cash = float(balance["cash"])
        current_price = current_symbol["price"]
        bill = current_price * int(shares)

        if bill < float(cash):
            new_cash = cash - bill
            # bill = float(bill)
            db.execute("UPDATE users set cash = ? WHERE id = ?", new_cash, id)
            db.execute("insert into trx (type, user_id, symbol, name, shares, price) values ('BUY', ?, ?, ?, ?, ?)",
                         id, current_symbol["symbol"], current_symbol["name"], shares, -abs(bill))

            # check and update purchased stocks if necessary
            existing = db.execute("select * from purchased_stock where user_id = ? and symbol = ?", id, current_symbol["symbol"])
            if len(existing) > 0:
                old_shares = db.execute("select shares from purchased_stock where user_id = ? and symbol = ?",
                                        id, current_symbol["symbol"])[0]
                new_shares = old_shares["shares"] + int(shares)
                db.execute("update purchased_stock set shares = ? where user_id = ? and symbol = ?",
                             new_shares, id, current_symbol["symbol"])
            elif len(existing) == 0:
                db.execute("insert into purchased_stock (user_id, symbol, name, shares, price) values (?, ?, ?, ?, ?)",
                             id, current_symbol["symbol"], current_symbol["name"], shares, bill)
            flash('stock was sucessfully bought')
            return redirect("/")
        else:
            return apology("not enough cash", 403)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    id = session["user_id"]

    history = db.execute("SELECT * FROM trx where user_id = ?", id)
    # name = lookup(history[0]["symbol"])
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        else:
            symbol = request.form.get("symbol")
            print(symbol)
            symbol_lookup_result = lookup(symbol)
            print(symbol_lookup_result)
            if not symbol_lookup_result:
                return apology("Invalid symbol", 400)
            # print(symbol_lookup_result)
            return render_template("quoted.html", symbols=symbol_lookup_result)
            # print(symbols)
    # return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    session.clear()
    """Register user"""
    # access form data
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("must provide username", 400)
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        username = request.form.get("username")
        password = request.form.get("password")
        password_repeat = request.form.get("confirmation")

        hash = generate_password_hash(password)
        if len(rows) == 1:
            return apology("username already taken")
        if password == password_repeat:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

            # get the newly registered user info and store in session

            registered_user = db.execute("select * from users where username = ?", username)
            session["user_id"] = registered_user[0]["id"]
            flash('You were successfully registered')
            return redirect("/")
        else:
            return apology("must provide matching password", 400)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    id = session["user_id"]

    if request.method == "GET":
        symbols = db.execute("Select * from purchased_stock where user_id = ?", id)
        if len(symbols) == 0:
            return apology("nothing to sell", 400)
        else:
            return render_template("sell.html", symbols=symbols)

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
        elif lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 403)
        elif not request.form.get("shares"):
            return apology("must provide number of shares", 400)

        symbol_to_sell = lookup(request.form.get("symbol"))
        shares = request.form.get("shares")

        # check for valid shares input
        if ("-" in shares) or (shares.isalpha() == True) or ("." in shares):
            return apology("must provide whole number of shares", 400)

        # check for remaining balance
        balance = db.execute("SELECT cash FROM users WHERE id = ?", id)[0]

        # get price per share
        price_per_share = symbol_to_sell["price"]

        # calculate cashback
        cashback = price_per_share * int(shares) + float(balance["cash"])

        # updare user's balance
        db.execute("update users set cash = ? where id = ?", cashback, id)

        # update history
        sold_shares = -abs(int(shares))
        db.execute("insert into trx (type, user_id, symbol, name, shares, price) values('SELL', ?, ?, ?, ?, ?)",
                     id, symbol_to_sell["symbol"], symbol_to_sell["name"], sold_shares, price_per_share * abs(int(sold_shares)))

        # update stock shares
        current_stock = db.execute("select * from purchased_stock where user_id = ? and symbol = ?",
                                   id, symbol_to_sell["symbol"])

        if len(current_stock) > 0:
            old_shares = db.execute("select shares from purchased_stock where user_id = ? and symbol = ?",
                                    id, symbol_to_sell["symbol"])[0]
            old_price = db.execute("select price from purchased_stock where user_id = ? and symbol = ?",
                                   id, symbol_to_sell["symbol"])[0]
            new_shares = old_shares["shares"] - int(shares)
            new_price = old_price["price"] - float(symbol_to_sell["price"] * int(shares))
            print("new shares", new_shares)
            if new_shares < 0:
                return apology("not enough shares", 400)
            elif new_shares == 0:
                db.execute("delete from purchased_stock where user_id = ? and symbol = ?", id, symbol_to_sell["symbol"])
                flash("Sucessfully sold")
                return redirect("/")
            else:
                db.execute("update purchased_stock set shares = ?, price = ? where user_id = ? and symbol = ?",
                           new_shares, new_price, id, symbol_to_sell["symbol"])
                flash("Sucessfully sold")
                return redirect("/")
        else:
            return apology("nothing to sell", 400)

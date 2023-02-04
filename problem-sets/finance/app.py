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
    """Show portfolio of stocks"""

    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    id = session["user_id"]
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
        elif lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 403)
        elif not request.form.get("shares"):
            return apology("must provide number of shares", 403)

        current_symbol = lookup(request.form.get("symbol"))
        shares = request.form.get("shares")
        balance = db.execute("SELECT cash FROM users WHERE id = ?", id)[0]
        print(balance)
        cash = float(balance["cash"])
        current_price = current_symbol["price"]
        bill = current_price * int(shares)

        if bill < float(cash):
            new_cash = cash - bill
            #bill = float(bill)
            db.execute("UPDATE users set cash = ? WHERE id = ?", new_cash, id)
            db.execute("insert into trx (user_id, symbol, shares, price) values (?, ?, ?, ?)", id, current_symbol["symbol"], shares, bill)
            return render_template("index.html", symbols = current_symbol, shares = shares, bill = bill, new_cash = new_cash)
        else:
            return apology("not enough cash", 403)
    return render_template("buy.html")

    #return apology("TODO")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
        else:
            symbol = request.form.get("symbol")
            symbol_lookup_result = lookup(symbol)
            if symbol_lookup_result == None:
                return apology("Invalid symbol", 403)
            print(symbol_lookup_result)
            return render_template("quoted.html", symbols = symbol_lookup_result)
            # print(symbols)
    return render_template("quote.html")


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
        if len(rows)==1:
            return apology("username already taken", 400)

        if password == password_repeat:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
        else:
            return apology("must provide matching password", 400)
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    id = session["user_id"]

    if request.method == "GET":
        symbols = db.execute("Select symbol from trx where user_id = ?", id)

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
        elif lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 403)
        elif not request.form.get("shares"):
            return apology("must provide number of shares", 403)

        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

    return apology("TODO")

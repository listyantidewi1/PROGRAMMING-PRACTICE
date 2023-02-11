from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import login_required, login_admin_required, apology

# configure application

app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///masakapa.sqlite")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
def index():
    return apology("Final project belum dikerjain?", 403)


@app.route("/member")
@login_required
def member_dashboard():
    return apology("Member dashboard beum dikerjain?", 403)

@app.route("/member/add")
@login_required
def add():
    return apology("Member dashboard beum dikerjain?", 403)

@app.route("/member/profile")
@login_required
def profile():
    return apology("Member dashboard beum dikerjain?", 403)

@app.route("/admin")
@login_admin_required
def admin_dashboard():
    n_users = db.execute("select count(id) as n_users from users where role = 'member'")
    n_recipes = db.execute("select count(id) as n_recipes from recipes")
    n_ingr = db.execute("select count(id) as n_ingr from ingredients")
    n_ori = db.execute("select count(id) as n_ori from origins")
    n_cat = db.execute("select count(id) as n_cat from categories")
    n_unit = db.execute("select count(id) as n_unit from units")
    return render_template("admin.html", users = n_users[0], recipes=n_recipes[0], ingredients = n_ingr[0], origins=n_ori[0], categories=n_cat[0], unit =n_unit[0])

@app.route("/admin/recipes", methods=["GET", "POST"])
@login_admin_required
def recipes():
    return apology("Admin dashboard belum dikerjain?", 403)

@app.route("/admin/units", methods=["GET", "POST"])
@login_admin_required
def units():
    return apology("Bagian units belum dikerjain?", 403)

@app.route("/admin/ingredients", methods=["GET", "POST"])
@login_admin_required
def ingredients():
    return apology("Bagian ingredients belum dikerjain?", 403)

@app.route("/admin/origins", methods=["GET", "POST"])
@login_admin_required
def origins():
    return apology("Bagian origins belum dikerjain?", 403)

@app.route("/admin/categories", methods=["GET", "POST"])
@login_admin_required
def categories():

    return apology("Bagian categories belum dikerjain?", 403)

@app.route("/admin/users", methods=["GET", "POST"])
@login_admin_required
def users():
    return apology("Bagian users belum dikerjain?", 403)

@app.route("/admin/profile", methods=["GET", "POST"])
@login_admin_required
def admin_profile():
    return apology("Bagian profile belum dikerjain?", 403)

@app.route("/register", methods=["GET", "POST"])
def register():
    session.clear()

    if request.method=="POST":
        if not request.form.get("username"):
            return apology("belum ngisi username?", 400)
        elif not request.form.get("password"):
            return apology("belum ngisi password?", 400)
        elif not request.form.get("email"):
            return apology("belum ngisi email?", 400)
        elif not request.form.get("name"):
            return apology("belum ngisi nama?", 400)

        rows = db.execute("select * from users where username = ? or email = ?", request.form.get("username"), request.form.get("email"))

        username = request.form.get("username")
        name = request.form.get("name")
        password = request.form.get("password")
        email = request.form.get("email")
        password_repeat = request.form.get("confirmation")

        hash = generate_password_hash(password)
        if len(rows) == 1:
            return apology("Gak pilih username yang lain?")
        if password == password_repeat:
            db.execute("insert into users (username, name, password, email, role) values (?, ?, ?, ?, ?)", username, name, hash, email, "member")

        #store in session

            registered_user = db.execute("select * from users where username = ?", username)
            session["user_id"] = registered_user[0]["id"]
            session["role"] = registered_user[0]["role"]
            flash("You were sucessfully registered")
            return redirect("/")
        else:
            return apology("Konfirmasi password nggak sama?", 400)
    else:
        return render_template("register.html")

   # return apology("Fitur register beum dikerjain?", 403)

@app.route("/login", methods=["GET", "POST"])
def login():
    session.clear()
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("belum ngisi username?", 403)
        elif not request.form.get("password"):
            return apology("belum ngisi password", 403)

        rows = db.execute("SELECT * from users where username = ?", request.form.get("username"))
        if len(rows) != 1 or not check_password_hash(rows[0]["password"], request.form.get("password")):
            return apology("Password/username salah?", 403)
        elif len(rows) == 1:
            if rows[0]["role"] == "member":
                session["user_id"] = rows[0]["id"]
                session["role"] = rows[0]["role"]
                return redirect("/")
            elif rows[0]["role"] == "admin":
                session["user_id"] = rows[0]["id"]
                session["role"] = rows[0]["role"]
                return redirect("/admin")
            else:
                return render_template("login.html")
    else:
        return render_template("login.html")


   # return apology("Fitur login beum dikerjain?", 403)

@app.route("/logout")
def logout():
    session.clear
    return redirect("/login")
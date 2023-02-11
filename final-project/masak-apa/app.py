from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import login_required, apology

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
def member_dashboard():
    return apology("Member dashboard beum dikerjain?", 403)

@app.route("/member/add")
def add():
    return apology("Member dashboard beum dikerjain?", 403)

@app.route("/member/profile")
def profile():
    return apology("Member dashboard beum dikerjain?", 403)

@app.route("/admin")
def admin_dashboard():
    return apology("Admin dashboard beum dikerjain?", 403)

@app.route("/admin/add/recipe")
def admin_add_recipe():
    return apology("Admin dashboard beum dikerjain?", 403)

# @app.route("/admin/add/unit")

# @app.route("/admin/add/ingredient")

# @app.route("/admin/add/origin")

# @app.route("/admin/add/category")

# @app.route("/admin/user")

# @app.route("/admin/profile")

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
    

    return apology("Fitur login beum dikerjain?", 403)

@app.route("/logout")
def logout():
    session.clear
    return redirect("/login.html")
from cs50 import SQL
import os
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from werkzeug.utils import secure_filename

from helpers import login_required, login_admin_required, apology

# configure application

UPLOAD_FOLDER = '/path/to/the/uploads'
ALLOWED_EXTENSIONS = {'png', 'jpg', 'jpeg', 'gif'}

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///masakapa.sqlite")

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

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
    #name = session["name"]
    id = session["user_id"]
    n_users = db.execute("select count(id) as n_users from users where role = 'member'")
    n_recipes = db.execute("select count(id) as n_recipes from recipes")
    n_ingr = db.execute("select count(id) as n_ingr from ingredients")
    n_ori = db.execute("select count(id) as n_ori from origins")
    n_cat = db.execute("select count(id) as n_cat from categories")
    n_unit = db.execute("select count(id) as n_unit from units")
    name = db.execute("select name from users where id = ?", id)
    return render_template("admin.html", users = n_users[0], recipes=n_recipes[0], ingredients = n_ingr[0], origins=n_ori[0], categories=n_cat[0], unit =n_unit[0], name=name[0])

@app.route("/admin/recipes", methods=["GET", "POST"])
@login_admin_required
def recipes():
    return apology("Admin dashboard belum dikerjain?", 403)

@app.route("/admin/units", methods=["GET", "POST"])
@login_admin_required
def units():
    if request.method == "GET":
        units = db.execute("select id, name from units")
        return render_template("units.html", units = units)
    elif request.method == "POST":
        if not request.form("unit"):
            return apology("Unit belum diisi?", 400)
        else:
            unit = request.form.get("unit")
            db.execute("insert into units (name) values(?)", unit)
            return redirect("/admin/units")

@app.route("/admin/units/<id>/edit", methods=["GET", "POST"])
@login_admin_required
def units_edit(id):
    if request.method == "GET":
        unit = db.execute("select * from units where id = ?", id)[0]
        print(unit)
        return render_template("units_edit.html", unit = unit)
    elif request.method == "POST":
        unit = request.form.get("unit")
        print(unit)
        db.execute("update units set name = ? where id = ?", unit, id)
        flash("The measurement unit has been successfully edited")
        return redirect("/admin/units")

@app.route("/admin/units/<id>/delete", methods=["GET"])
@login_admin_required
def units_delete(id):
    db.execute("delete from units where id = ?", id)
    flash("The measurement unit has been successfully deleted")
    return redirect("/admin/units")

@app.route("/admin/ingredients", methods=["GET", "POST"])
@login_admin_required
def ingredients():
    return apology("Bagian ingredients belum dikerjain?", 403)

@app.route("/admin/origins", methods=["GET", "POST"])
@login_admin_required
def origins():
    if request.method=="GET":
        origins = db.execute("select id, origin from origins")
        return render_template("origins.html", origins = origins)
    elif request.method=="POST":
        if not request.form.get("origin"):
            return apology("origin belum diisi", 400)
        else:
            neworigin = request.form.get("origin")
            db.execute("insert into origins (origin) values(?)", neworigin)
            return redirect("/admin/origins")
    #return apology("Bagian origins belum dikerjain?", 403)

@app.route("/admin/origins/<id>/edit", methods=["GET", "POST"])
@login_admin_required
def origins_edit(id):
    if request.method == "GET":
        origin = db.execute("select * from origins where id = ?", id)[0]
        print(origin)
        return render_template("origins_edit.html", origins=origin)
    elif request.method == "POST":
        origin = request.form.get("origin")
        print(origin)
        db.execute("update origins set origin = ? where id = ?", origin, id)
        flash("The ingredient origin has been sucessfully edited")
        return redirect("/admin/origins")

@app.route("/admin/origins/<id>/delete", methods=["GET"])
@login_admin_required
def origins_delete(id):
    db.execute("delete from origins where id = ?", id)
    flash("The ingredient origin has been successfully deleted")
    return redirect("/admin/origins")

@app.route("/admin/categories", methods=["GET", "POST"])
@login_admin_required
def categories():
    if request.method=="GET":
        cat = db.execute("select id, category from categories")
        return render_template("categories.html", categories=cat)
    elif request.method=="POST":
        if not request.form.get("category"):
            return apology("Category belum diisi?", 400)
        else:
            newcat = request.form.get("category")
            db.execute("insert into categories (category) values (?)", newcat)
            return redirect("/admin/categories")
    #return apology("Bagian categories belum dikerjain?", 403)

@app.route("/admin/categories/<id>/edit", methods=["GET", "POST"])
@login_admin_required
def categories_edit(id):
    if request.method == "GET":
        cat = db.execute("select * from categories where id = ?", id)[0]
        print(cat)
        return render_template("categories_edit.html", categories=cat)
    elif request.method == "POST":
        category = request.form.get("category")
        print(category)
        db.execute("update categories set category = ? where id = ?", category, id)
        flash("The category has been successfully edited")
        return redirect("/admin/categories")

@app.route("/admin/categories/<id>/delete", methods=["GET"])
@login_admin_required
def categories_delete(id):
    db.execute("delete from categories where id = ?", id)
    flash("The category has been successfully deleted")
    return redirect("/admin/categories")

@app.route("/admin/users", methods=["GET"])
@login_admin_required
def users():
    users = db.execute("select id, name, username, email from users where role = 'member'")
    return render_template("users.html", users = users)

    #return apology("Bagian users belum dikerjain?", 403)

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
            session["name"] = registered_user[0]["name"]
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
                session["name"] = rows[0]["name"]
                flash("You were sucessfully logged in")
                return redirect("/")
            elif rows[0]["role"] == "admin":
                session["user_id"] = rows[0]["id"]
                session["role"] = rows[0]["role"]
                session["name"] = rows[0]["name"]
                flash("You were sucessfully logged in")
                return redirect("/admin")
            else:
                return render_template("login.html")
    else:
        return render_template("login.html")


   # return apology("Fitur login beum dikerjain?", 403)

@app.route("/logout")
def logout():
    session.clear
    return redirect("/")
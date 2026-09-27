// topological sort

#include<stdio.h>
#define max 10

int main(){
    int a[max][max],indegree[max];
    int queue[max], front = 0, rear = -1;
    int n, i, j, count = 0;

    printf("Enter the no. of vertices :");
    scanf("%d",&n);

    if(n>10 || n<=0){
        printf("\nInvalid no. vertices you can take vertices upto %d ",max);
        return 0;
    }

    printf("\nEnter graph :\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            a[i][j] = 0;
            if(i==j){
                continue;
            }else{
                printf("Is there is an edge between v%d and v%d (1=Yes & 0=No) :",i+1,j+1);
                scanf("%d",&a[i][j]);
            }
        }
    }
    for(i=0; i<n; i++){ // this for loop is to find indegrees of vertices
        indegree[i] = 0;
        for(j=0; j<n; j++){
            if(a[j][i] == 1){
                indegree[i]++;
            }
        }
    }
    for(i=0; i<n; i++){ // Insert all indegree-0 vertices into queue
        if(indegree[i]==0){
            queue[++rear] = i;
        }
    }
    while(front<=rear){
        int u = queue[front++];
        printf("v%d ",u+1);
        count++;

        for(j=0; j<n; j++){ // this for is to reduce the indgree of neigbour vertex
            if(a[u][j] == 1){
                indegree[j]--;
                if(indegree[j]==0){
                    queue[++rear] = j;
                }
            }
        }
    }
    if(count != n){
        printf("graph contains a cycle , so topological sort is not possible");
        return -1;
    }
    return 0;
}

1. Create a Flask application with the following static routes:
i) /
ii) /about
iii) /contact
Display an appropriate message on each webpage.
====>
from flask import Flask
app = Flask(__name__)
@app.route("/")
def home():
    return "we are on home page"

@app.route("/about")
def about():
    return "we are on about page"

@app.route("/contact")
def contact():
    return "we are on contact page"

if __name__ == "__main__":
    app.run(debug=True)
==========================================================================================================================================
2. Create a dynamic URL route using an integer parameter:
/student/<int:roll_no>/<name>
The route should accept the student’s roll number and name through the URL and display the student details in a structured format.
===>
from flask import Flask
app = Flask(__name__)

@app.route('/student/<int:roll_no>/<name>')
def student(roll_no, name):
    return f"""
    <h2>Student Details</h2>
    <p>Roll No: {roll_no}</p>
    <p>Name: {name}</p>
    """
if __name__ == '__main__':
    app.run(debug=True)
Browser URL:
http://127.0.0.1:5000/student/101/Raj
==========================================================================================================================================
3. Create a Flask application that stores an employee’s details (Employee ID, Name, Department, Basic Salary) in predefined variables, calculates HRA (20%), DA (12%), TA (8%), PF (10%), Gross Salary and Net Salary, and displays a salary slip on the home page.
gross_salary = basic_salary + hra + da + ta
net_salary = gross_salary - pf
====>
from flask import Flask
app = Flask(__name__)

@app.route('/')
def salary():
    emp_id = 101
    name = "Raj"
    department = "IT"
    basic_salary = 30000

    hra = basic_salary * 20 / 100
    da = basic_salary * 12 / 100
    ta = basic_salary * 8 / 100
    pf = basic_salary * 10 / 100

    gross_salary = basic_salary + hra + da + ta
    net_salary = gross_salary - pf

    return f"""
    <h2>Employee Salary Slip</h2>
    Employee ID: {emp_id}<br>
    Name: {name}<br>
    Department: {department}<br>
    Basic Salary: ₹{basic_salary}<br>
    HRA: ₹{hra}<br>
    DA: ₹{da}<br>
    TA: ₹{ta}<br>
    PF: ₹{pf}<br>
    Gross Salary: ₹{gross_salary}<br>
    Net Salary: ₹{net_salary}
    """

if __name__ == '__main__':
    app.run(debug=True)

URL
http://127.0.0.1:5000/
==========================================================================================================================================
4. Create a Flask application to develop a dynamic product information page using URL routing. Create a dynamic URL route
/product/<product_name>/<int:price>/<category>
that accepts product details through the URL and displays the product name, price, category, discount amount(10%), GST (18%), and final price after calculation on the webpage. Test the application by accessing the URL with different product values through the browser and verify the output.
===>
from flask import Flask
app = Flask(__name__)

@app.route("/product/<product_name>/<int:price>/<category>")
def product(product_name, price, category):

    discount = price * 10 / 100
    discounted_price = price - discount

    gst = discounted_price * 18 / 100
    final_price = discounted_price + gst

    return f"""
    <h2>Product Information</h2>
    <p>Product Name: {product_name}</p>
    <p>Original Price: ₹{price}</p>
    <p>Category: {category}</p>
    <p>Discount (10%): ₹{discount}</p>
    <p>GST (18%): ₹{gst}</p>
    <p>Final Price: ₹{final_price}</p>
    """
if __name__ == "__main__":
    app.run(debug=True)
URL
http://127.0.0.1:5000/product/Laptop/50000/Electronics
==========================================================================================================================================
5. Create a Flask application with the following files:
* base.html
* home.html
* employees.html
* department.html
Create employee data and use Jinja2 loops to display the records. Use conditional statements to categorize employees as Fresher, Experienced, or Senior based on experience. Use template inheritance and create a CSS file in static/css. Verify the application in the browser.
Folder structure
project/
│
├── app.py
│
├── templates/
│   ├── base.html
│   ├── home.html
│   ├── employees.html
│   └── department.html
│
└── static/
    └── css/
        └── style.css
=====>
#app.py
from flask import Flask, render_template
app = Flask(__name__)

employees = [
    {"name": "Raj", "department": "IT", "experience": 1},
    {"name": "Amit", "department": "HR", "experience": 3},
    {"name": "Sneha", "department": "Finance", "experience": 7}
]

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/employees")
def employee_page():
    return render_template("employees.html", employees=employees)

@app.route("/department")
def department():
    return render_template("department.html")

if __name__ == "__main__":
    app.run(debug=True)

---------------------
#templates/base.html
<!DOCTYPE html>
<html>
<head>
    <title>{% block title %}Employee System{% endblock %}</title>
    <link rel="stylesheet" href="{{ url_for('static', filename='css/style.css') }}">
</head>

<body>

<header>
    <h1>Employee Management System</h1>
    <nav>
        <a href="{{ url_for('home') }}">Home</a>
        <a href="{{ url_for('employee_page') }}">Employees</a>
        <a href="{{ url_for('department') }}">Department</a>
    </nav>
</header>
<hr>
<main>
    {% block content %}
    {% endblock %}
</main>
<hr>
<footer>
    <p>&copy; 2026 Employee Management System</p>
</footer>
</body>
</html>

------------------------
#templates/home.html
{% extends "base.html" %}

{% block title %}Home{% endblock %}

{% block content %}
<h2>Welcome to Employee Management System</h2>
{% endblock %}

----------------------
#templates/employees.html
{% extends "base.html" %}

{% block title %}Employees{% endblock %}

{% block content %}

<h2>Employee Records</h2>

{% for employee in employees %}

<p>
    <b>Name:</b> {{ employee.name }}<br>
    <b>Department:</b> {{ employee.department }}<br>
    <b>Experience:</b> {{ employee.experience }} years<br>
    <b>Category:</b>

    {% if employee.experience < 2 %}
        Fresher
    {% elif employee.experience < 5 %}
        Experienced
    {% else %}
        Senior
    {% endif %}
</p>
<hr>
{% endfor %}
{% endblock %}

-------------------------
#templates/department.html
{% extends "base.html" %}

{% block title %}Department{% endblock %}

{% block content %}

<h2>Departments</h2>
<ul>
    <li>IT</li>
    <li>HR</li>
    <li>Finance</li>
</ul>
{% endblock %}

--------------------------
#static/css/style.css
body {
    font-family: Arial;
    text-align: center;
    background-color: #f2f2f2;
}

h1 {
    color: darkblue;
}

a {
    margin: 10px;
    text-decoration: none;
}

URLs
http://127.0.0.1:5000/
http://127.0.0.1:5000/employees
http://127.0.0.1:5000/department

====================================================================================================================================================
6.Display Student Information using Jinja2 ,Create a Flask application with the following templates: base.html, home.html, student html .Create student data containing name, roll number, and course in app.py. Pass the data to student.html using Jinja2 variables and display the student information. Use template inheritance and create a CSS file in the static/CSS folder. Verify the output in the browser.
Folder structure
project/
├── app.py
├── templates/
│   ├── base.html
│   ├── home.html
│   └── student.html
└── static/
    └── css/
        └── style.css
====>
#app.py
from flask import Flask, render_template
app = Flask(__name__)

student = {
    "name": "Raj",
    "roll_no": 101,
    "course": "B.Sc Computer Science"
}

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/student")
def student_page():
    return render_template("student.html", student=student)

if __name__ == "__main__":
    app.run(debug=True)

------------------------
#template/base.html
<!DOCTYPE html>
<html>

<head>
    <title>{% block title %}Student System{% endblock %}</title>

    <link rel="stylesheet"
          href="{{ url_for('static', filename='css/style.css') }}">
</head>

<body>
<header>
    <h1>Student Management System</h1>
    <nav>
        <a href="{{ url_for('home') }}">Home</a>
        <a href="{{ url_for('student_page') }}">Students</a>
    </nav>
</header>
<hr>
<main>
    {% block content %}
    {% endblock %}
</main>
<hr>
<footer>
    <p>&copy; 2026 Student Management System</p>
</footer>
</body>
</html>

-------------------------------
#template/home.html
{% extends "base.html" %}

{% block title %}Home{% endblock %}

{% block content %}

<h2>Welcome to Student Management System</h2>
<a href="{{ url_for('student_page') }}">View Student</a>

{% endblock %}

----------------------------------
#template/student.html
{% extends "base.html" %}

{% block title %}Student{% endblock %}

{% block content %}

<h2>Student Information</h2>

<p>Name: {{ student.name }}</p>
<p>Roll No: {{ student.roll_no }}</p>
<p>Course: {{ student.course }}</p>

{% endblock %}

---------------------------
#template/style.css
body {
    font-family: Arial;
    text-align: center;
}

h1 {
    color: blue;
}
URL
http://127.0.0.1:5000/student
====================================================================================================================================================
7. Display HTML Template using Flask ,Create a Flask application with the following structure: templates/home.html Create a home.html template and display a ‘ welcome’ message using the render_template() function. Verify the output in the browser.
Structure
project/
├── app.py
└── templates/
    └── home.html
======>
#app.py
from flask import Flask, render_template
app = Flask(__name__)

@app.route("/")
def home():
    return render_template("home.html")

if __name__ == "__main__":
    app.run(debug=True)

--------------------------
#templates/home.html
<!DOCTYPE html>
<html>
<head>
    <title>Home</title>
</head>

<body>
<h1>Welcome to Flask Application</h1>
</body>
</html>

URL
http://127.0.0.1:5000/
========================================================================================================================================================
8. Display Course List using Jinja2 Loop, Create a Flask application with the following templates: base.html, home.html, courses.html, Create a list of five courses in app.py. Use a Jinja2 for loop to display the courses in courses.html. Use template inheritance and create a CSS file in the static/CSS folder. Verify the output in the browser.
Folder Structure
project/
│
├── app.py
│
├── templates/
│   ├── base.html
│   ├── home.html
│   └── courses.html
│
└── static/
    └── css/
        └── style.css
====>
#app.py 
from flask import Flask, render_template
app = Flask(__name__)

courses = [
    "Python",
    "Java",
    "Web Technology",
    "Data Science",
    "Android Development"
]

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/courses")
def course_page():
    return render_template("courses.html", courses=courses)

if __name__ == "__main__":
    app.run(debug=True)

-------------------------------
#templates/base.html
<!DOCTYPE html>
<html>
<head>
    <title>{% block title %}Course System{% endblock %}</title>
    <link rel="stylesheet"
          href="{{ url_for('static', filename='css/style.css') }}">
</head>

<body>
<header>
    <h1>Course Management System</h1>
    <nav>
        <a href="{{ url_for('home') }}">Home</a> |
        <a href="{{ url_for('course_page') }}">Courses</a>
    </nav>
</header>
<hr>
{% block content %}
{% endblock %}
<hr>

<footer>
    <p>&copy; 2026 Course Management System</p>
</footer>

</body>
</html>

---------------------------
#templates/home.html
{% extends "base.html" %}

{% block title %}Home{% endblock %}

{% block content %}

<h2>Welcome</h2>

<a href="{{ url_for('course_page') }}">View Courses</a>

{% endblock %}

-----------------------------
#templates/courses.html
{% extends "base.html" %}

{% block title %}Courses{% endblock %}

{% block content %}

<h2>Course List</h2>

<ul>

{% for course in courses %}

    <li>{{ course }}</li>

{% endfor %}

</ul>

{% endblock %}

------------------------------
#static/css/style.css
body {
    font-family: Arial;
    text-align: center;
    background-color: #f2f2f2;
}

header {
    background-color: lightblue;
    padding: 15px;
}

footer {
    background-color: lightgray;
    padding: 10px;
}

a {
    margin: 10px;
    text-decoration: none;
}

URLs
http://127.0.0.1:5000/
http://127.0.0.1:5000/courses
========================================================================================================================================================
9. Student Result using Jinja2 Conditional Statements ,Create a Flask application with the following templates:base.html,home.html,result.html .Create student name and percentage in app.py. Use Jinja2 conditional statements to display the result as Distinction, First Class, Second Class, Pass, or Fail according to the percentage. Use template inheritance and create a CSS file in the static/CSS folder. Verify the output in the browser.
Folder Structure
project/
│
├── app.py
│
├── templates/
│   ├── base.html
│   ├── home.html
│   └── result.html
│
└── static/
    └── css/
        └── style.css
=====>
#app.py
from flask import Flask, render_template
app = Flask(__name__)

student_name = "Raj"
percentage = 82

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/result")
def result():
    return render_template(
        "result.html",
        student_name=student_name,
        percentage=percentage
    )

if __name__ == "__main__":
    app.run(debug=True)

------------------------------
#templates/base.html
<!DOCTYPE html>
<html>
<head>
    <title>{% block title %}Student Result{% endblock %}</title>
    <link rel="stylesheet"
          href="{{ url_for('static', filename='css/style.css') }}">
</head>

<body>
<header>
    <h1>Student Result System</h1>
    <nav>
        <a href="{{ url_for('home') }}">Home</a> |
        <a href="{{ url_for('result') }}">Result</a>
    </nav>
</header>

<hr>

{% block content %}
{% endblock %}

<hr>

<footer>
    <p>&copy; 2026 Student Result System</p>
</footer>

</body>
</html>

----------------------------------
#templates/home.html
{% extends "base.html" %}

{% block title %}Home{% endblock %}

{% block content %}

<h2>Welcome to Result System</h2>

<a href="{{ url_for('result') }}">View Result</a>

{% endblock %}

------------------------------
#templates/result.html
{% extends "base.html" %}

{% block title %}Result{% endblock %}

{% block content %}

<h2>Student Result</h2>

<p>Name: {{ student_name }}</p>

<p>Percentage: {{ percentage }}%</p>

{% if percentage >= 75 %}

    <h3>Distinction</h3>

{% elif percentage >= 60 %}

    <h3>First Class</h3>

{% elif percentage >= 50 %}

------------------------------
#static/css/style.css
body {
    font-family: Arial;
    text-align: center;
}

header {
    background-color: lightblue;
    padding: 15px;
}

footer {
    background-color: lightgray;
    padding: 10px;
}

h1 {
    color: darkblue;
}

URLs
http://127.0.0.1:5000/
http://127.0.0.1:5000/result
========================================================================================================================================================
10. Apply CSS Styling using Static Folder . Create a Flask application with the following structure: templates/home.html and static/CSS/style.css .Create a home.html template and apply CSS styling using the style.css file in the static/CSS folder. Apply simple styling to the heading, paragraph, background, and text alignment. Verify the output in the browser.
Folder Structure
project/
│
├── app.py
│
├── templates/
│   └── home.html
│
└── static/
    └── CSS/
        └── style.css
====>
#app.py
from flask import Flask, render_template
app = Flask(__name__)

@app.route("/")
def home():
    return render_template("home.html")

if __name__ == "__main__":
    app.run(debug=True)

---------------------------------
#templates/home.html
<!DOCTYPE html>
<html>
<head>
    <title>Flask Application</title>
    <link rel="stylesheet"
          href="{{ url_for('static', filename='CSS/style.css') }}">
</head>
<body>
<h1>Flask Application</h1>
<h2>Welcome to Flask</h2>
<p>This page uses CSS from the static folder.</p>
</body>
</html>

-----------------------------
#static/CSS/style.css
body {
    background-color: lightgray;
    text-align: center;
    font-family: Arial;
}

h1 {
    color: darkblue;
}

p {
    color: black;
    font-size: 20px;
}
URL
http://127.0.0.1:5000/
========================================================================================================================================================
11. Product List using Jinja2 Loop and Conditional Statements Create a Flask application with the following templates:base.html,home.html,products.html .Create product data containing product name, price, and availability in app.py. Use a Jinja2 for loop to display the products and conditional statements to display Available or Out of Stock. Use template inheritance and create a CSS file in the static/CSS folder. Verify the output in the browser.
Folder Structure
project/
│
├── app.py
│
├── templates/
│   ├── base.html
│   ├── home.html
│   └── products.html
│
└── static/
    └── css/
        └── style.css
==========>
#app.py
from flask import Flask, render_template
app = Flask(__name__)

products = [
    {"name": "Laptop", "price": 50000, "available": True},
    {"name": "Mobile", "price": 20000, "available": True},
    {"name": "Headphones", "price": 2000, "available": False},
    {"name": "Mouse", "price": 800, "available": True}
]

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/products")
def product_page():
    return render_template("products.html", products=products)

if __name__ == "__main__":
    app.run(debug=True)

----------------------------
#templates/base.html
<!DOCTYPE html>
<html>
<head>
    <title>{% block title %}Product System{% endblock %}</title>
    <link rel="stylesheet"
          href="{{ url_for('static', filename='css/style.css') }}">
</head>

<body>
<header>
    <h1>Product Management System</h1>
    <nav>
        <a href="{{ url_for('home') }}">Home</a> |
        <a href="{{ url_for('product_page') }}">Products</a>
    </nav>
</header>

<hr>
{% block content %}
{% endblock %}
<hr>
<footer>
    <p>&copy; 2026 Product Management System</p>
</footer>

</body>
</html>

---------------------------
#templates/home.html
{% extends "base.html" %}
{% block title %}Home{% endblock %}
{% block content %}

<h2>Welcome</h2>
<a href="{{ url_for('product_page') }}">View Products</a>
{% endblock %}

---------------------------
#templates/products.html
{% extends "base.html" %}

{% block title %}Products{% endblock %}

{% block content %}

<h2>Product List</h2>

{% for product in products %}
<p>
    <b>Product:</b> {{ product.name }}<br>
    <b>Price:</b> ₹{{ product.price }}<br>
    <b>Status:</b>
    {% if product.available %}
        Available
    {% else %}
        Out of Stock
    {% endif %}
</p>

<hr>
{% endfor %}
{% endblock %}

----------------------------
#static/css/style.css
body {
    font-family: Arial;
    text-align: center;
    background-color: #f5f5f5;
}

header {
    background-color: lightblue;
    padding: 15px;
}

footer {
    background-color: lightgray;
    padding: 10px;
}

URLs
http://127.0.0.1:5000/
http://127.0.0.1:5000/products
========================================================================================================================================================
12. Create a Flask Employee Information Form containing Employee ID, Employee Name, Department, and Designation. Accept the form data using the POST method and display the submitted information on the web page.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── employee.html
====>
#app.py
from flask import Flask, render_template, request
app = Flask(__name__)

@app.route("/employee", methods=["GET", "POST"])
def employee():

    if request.method == "POST":
        emp_id = request.form["emp_id"]
        name = request.form["name"]
        department = request.form["department"]
        designation = request.form["designation"]

        return render_template(
            "employee.html",
            emp_id=emp_id,
            name=name,
            department=department,
            designation=designation,
            submitted=True
        )
    return render_template("employee.html", submitted=False)

if __name__ == "__main__":
    app.run(debug=True)

-------------------------------
#templates/employee.html
<!DOCTYPE html>
<html>
<head>
    <title>Employee Form</title>
</head>
<body>
<h1>Employee Management System</h1>
<h2>Employee Information Form</h2>
<form method="POST">
    Employee ID:
    <input type="text" name="emp_id"><br><br>

    Employee Name:
    <input type="text" name="name"><br><br>

    Department:
    <input type="text" name="department"><br><br>

    Designation:
    <input type="text" name="designation"><br><br>

    <button type="submit">Submit</button>
</form>

{% if submitted %}
<h2>Submitted Information</h2>
<p>Employee ID: {{ emp_id }}</p>
<p>Name: {{ name }}</p>
<p>Department: {{ department }}</p>
<p>Designation: {{ designation }}</p>
{% endif %}

</body>
</html>

URL
http://127.0.0.1:5000/employee
========================================================================================================================================================
13. Create a Flask Contact Form containing Name, Email, Subject, and Message. Check whether all fields are filled and display an appropriate flash message.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── contact.html
======>
#app.py
from flask import Flask, render_template, request, flash

app = Flask(__name__)
app.secret_key = "12345"

@app.route("/contact", methods=["GET", "POST"])
def contact():
    if request.method == "POST":
        name = request.form["name"]
        email = request.form["email"]
        subject = request.form["subject"]
        message = request.form["message"]

        if name and email and subject and message:
            flash("Form submitted successfully!")
        else:
            flash("Please fill all the fields.")

    return render_template("contact.html")

if __name__ == "__main__":
    app.run(debug=True)

-----------------------------
#templates/contact.html
<!DOCTYPE html>
<html>
<head>
    <title>Contact Form</title>
</head>
<body>
<h2>Contact Form</h2>

{% with messages = get_flashed_messages() %}
    {% if messages %}
        {% for message in messages %}
            <p>{{ message }}</p>
        {% endfor %}
    {% endif %}
{% endwith %}

<form method="POST">
    Name:
    <input type="text" name="name"><br><br>

    Email:
    <input type="email" name="email"><br><br>

    Subject:
    <input type="text" name="subject"><br><br>

    Message:
    <textarea name="message"></textarea><br><br>

    <input type="submit" value="Submit">
</form>
</body>
</html>

URL
http://127.0.0.1:5000/contact
========================================================================================================================================================
14. Create a Flask Event Registration Form containing Participant Name, Mobile Number, and Event Name. Provide three event options and display the submitted information using a flash message.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── event.html
=====>
#app.py
from flask import Flask, render_template, request, flash

app = Flask(__name__)
app.secret_key = "12345"

@app.route("/event", methods=["GET", "POST"])
def event():
    if request.method == "POST":
        name = request.form["name"]
        mobile = request.form["mobile"]
        event_name = request.form["event_name"]

        if name and mobile and event_name:
            flash(f"Name: {name}, Mobile: {mobile}, Event: {event_name}")
        else:
            flash("Please fill all the fields.")

    return render_template("event.html")

if __name__ == "__main__":
    app.run(debug=True)

------------------------------
#templates/event.html
<!DOCTYPE html>
<html>
<head>
    <title>Event Registration</title>
</head>
<body>
<h2>Event Registration Form</h2>
{% with messages = get_flashed_messages() %}
    {% if messages %}
        {% for message in messages %}
            <p>{{ message }}</p>
        {% endfor %}
    {% endif %}
{% endwith %}

<form method="POST">
    Participant Name:
    <input type="text" name="name"><br><br>

    Mobile Number:
    <input type="text" name="mobile"><br><br>

    Event Name:

    <select name="event_name">
        <option value="">Select Event</option>
        <option value="Coding Competition">Coding Competition</option>
        <option value="Quiz Competition">Quiz Competition</option>
        <option value="Sports Event">Sports Event</option>
    </select>

    <br><br>

    <input type="submit" value="Register">
</form>
</body>
</html>
URL
http://127.0.0.1:5000/event
========================================================================================================================================================
15. Create a Flask Electricity Bill Form containing Consumer Name, Consumer Number, and Units Consumed. Calculate the electricity bill according to different unit slabs and display the total bill.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── electricity.html
=====>
#app.py
from flask import Flask, render_template, request
app = Flask(__name__)

@app.route("/electricity", methods=["GET", "POST"])
def electricity():
    if request.method == "POST":
        name = request.form["name"]
        number = request.form["number"]
        units = int(request.form["units"])

        return render_template("electricity.html",
                               name=name,
                               number=number,
                               units=units,
                               submitted=True)

    return render_template("electricity.html", submitted=False)

if __name__ == "__main__":
    app.run(debug=True)

--------------------------------
#templates/electricity.html
<!DOCTYPE html>
<html>
<head>
    <title>Electricity Bill</title>
</head>

<body>
<h2>Electricity Bill Form</h2>

<form method="POST">
    Consumer Name:
    <input type="text" name="name"><br><br>

    Consumer Number:
    <input type="text" name="number"><br><br>

    Units Consumed:
    <input type="number" name="units"><br><br>

    <input type="submit" value="Calculate Bill">
</form>

{% if submitted %}

<h2>Electricity Bill</h2>

<p>Consumer Name: {{ name }}</p>
<p>Consumer Number: {{ number }}</p>
<p>Units Consumed: {{ units }}</p>

{% if units <= 100 %}

<p>Total Bill: ₹{{ units * 2 }}</p>

{% elif units <= 200 %}

<p>Total Bill: ₹{{ (100 * 2) + ((units - 100) * 3) }}</p>

{% else %}

<p>Total Bill: ₹{{ (100 * 2) + (100 * 3) + ((units - 200) * 5) }}</p>

{% endif %}

{% endif %}

</body>
</html>
Unit Slabs
0–100 units     → ₹2 per unit
101–200 units   → ₹3 per unit
Above 200 units → ₹5 per unit
URL
http://127.0.0.1:5000/electricity
========================================================================================================================================================
16. Create a Flask Age Calculator Form that accepts a person’s Name and Date of Birth. Calculate and display the person's age on the result page. Display an appropriate flash message if the required input is missing.
Folder Structure
project/
│
├── app.py
│
└── templates/
    ├── age.html
    └── result.html
======>
#app.py
from flask import Flask, render_template, request, flash
from datetime import datetime

app = Flask(__name__)
app.secret_key = "12345"

@app.route("/age", methods=["GET", "POST"])
def age():
    if request.method == "POST":
        name = request.form["name"]
        dob = request.form["dob"]

        if not name or not dob:
            flash("Please enter Name and Date of Birth.")
            return render_template("age.html")

        dob = datetime.strptime(dob, "%Y-%m-%d").date()
        today = datetime.today().date()

        age = today.year - dob.year

        if (today.month, today.day) < (dob.month, dob.day):
            age -= 1

        return render_template("result.html", name=name, age=age)

    return render_template("age.html")

if __name__ == "__main__":
    app.run(debug=True)

-------------------------
templates/age.html
<!DOCTYPE html>
<html>
<head>
    <title>Age Calculator</title>
</head>

<body>
<h2>Age Calculator</h2>

{% with messages = get_flashed_messages() %}
    {% if messages %}
        {% for message in messages %}
            <p>{{ message }}</p>
        {% endfor %}
    {% endif %}
{% endwith %}

<form method="POST">
    Name:
    <input type="text" name="name"><br><br>

    Date of Birth:
    <input type="date" name="dob"><br><br>

    <input type="submit" value="Calculate Age">
</form>
</body>
</html>

-----------------------------
#templates/result.html
<!DOCTYPE html>
<html>
<head>
    <title>Age Result</title>
</head>

<body>

<h2>Age Result</h2>

<p>Name: {{ name }}</p>

<p>Age: {{ age }} years</p>

</body>
</html>
URL
http://127.0.0.1:5000/age
========================================================================================================================================================
17. Create a Flask Temperature Conversion Form that accepts a temperature value and allows the user to select Celsius to Fahrenheit or Fahrenheit to Celsius. Perform the selected conversion and display the result.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── temperature.html
=====>
#app.py
from flask import Flask, render_template, request
app = Flask(__name__)

@app.route("/temperature", methods=["GET", "POST"])
def temperature():

    result = None

    if request.method == "POST":
        value = float(request.form["value"])
        conversion = request.form["conversion"]

        if conversion == "CtoF":
            result = (value * 9 / 5) + 32
        else:
            result = (value - 32) * 5 / 9

    return render_template("temperature.html", result=result)

if __name__ == "__main__":
    app.run(debug=True)

------------------------------
#templates/temperature.html
<!DOCTYPE html>
<html>
<head>
    <title>Temperature Conversion</title>
</head>

<body>

<h2>Temperature Conversion</h2>

<form method="POST">
    Temperature:
    <input type="number" step="any" name="value"><br><br>

    Conversion:

    <select name="conversion">
        <option value="CtoF">Celsius to Fahrenheit</option>
        <option value="FtoC">Fahrenheit to Celsius</option>
    </select>

    <br><br>

    <input type="submit" value="Convert">
</form>

{% if result is not none %}

<h3>Result: {{ result }}</h3>

{% endif %}

</body>
</html>
URL
http://127.0.0.1:5000/temperature
========================================================================================================================================================
18. Create a Flask Student Attendance Form containing Student Name, Total Working Days, and Days Present. Calculate the attendance percentage and display whether the student is Eligible or Not Eligible based on a minimum attendance requirement of 75%. Display appropriate flash messages.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── attendance.html
=======>
#app.py
from flask import Flask, render_template, request, flash

app = Flask(__name__)
app.secret_key = "12345"

@app.route("/attendance", methods=["GET", "POST"])
def attendance():
    if request.method == "POST":

        name = request.form["name"]
        working_days = request.form["working_days"]
        present_days = request.form["present_days"]

        if not name or not working_days or not present_days:
            flash("Please fill all the fields.")
            return render_template("attendance.html")

        working_days = int(working_days)
        present_days = int(present_days)

        percentage = (present_days / working_days) * 100

        if percentage >= 75:
            status = "Eligible"
            flash("Student is Eligible.")
        else:
            status = "Not Eligible"
            flash("Student is Not Eligible.")

        return render_template("attendance.html",
                               name=name,
                               percentage=percentage,
                               status=status)

    return render_template("attendance.html")

if __name__ == "__main__":
    app.run(debug=True)

-----------------------------------
#templates/attendance.html
<!DOCTYPE html>
<html>
<head>
    <title>Student Attendance</title>
</head>

<body>

<h2>Student Attendance Form</h2>

{% with messages = get_flashed_messages() %}
    {% if messages %}
        {% for message in messages %}
            <p>{{ message }}</p>
        {% endfor %}
    {% endif %}
{% endwith %}

<form method="POST">
    Student Name:
    <input type="text" name="name"><br><br>

    Total Working Days:
    <input type="number" name="working_days"><br><br>

    Days Present:
    <input type="number" name="present_days"><br><br>

    <input type="submit" value="Check Attendance">
</form>

{% if percentage is defined %}

<h3>Student Name: {{ name }}</h3>

<p>Attendance Percentage: {{ percentage }}%</p>

<p>Status: {{ status }}</p>

{% endif %}

</body>
</html>
URL
http://127.0.0.1:5000/attendance
Minimum attendance required: 75%
Attendance Percentage = (Days Present / Total Working Days) × 100
========================================================================================================================================================
19. Create a Flask Restaurant Order Form containing Customer Name, Food Item,Quantity, and Price. Calculate the subtotal, apply a 5% service charge, add 18% GST,and display the final bill. Validate the input fields and display appropriate flash messages for invalid input.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── order.html
======>
#app.py
from flask import Flask, render_template, request, flash

app = Flask(__name__)
app.secret_key = "12345"

@app.route("/order", methods=["GET", "POST"])
def order():
    if request.method == "POST":

        name = request.form["name"]
        food = request.form["food"]
        quantity = request.form["quantity"]
        price = request.form["price"]

        if not name or not food or not quantity or not price:
            flash("Please fill all the fields.")
            return render_template("order.html")

        quantity = int(quantity)
        price = float(price)

        if quantity <= 0 or price <= 0:
            flash("Quantity and Price must be greater than 0.")
            return render_template("order.html")

        subtotal = quantity * price
        service_charge = subtotal * 0.05
        gst = (subtotal + service_charge) * 0.18
        total = subtotal + service_charge + gst

        return render_template("order.html",
                               name=name,
                               food=food,
                               quantity=quantity,
                               price=price,
                               subtotal=subtotal,
                               service_charge=service_charge,
                               gst=gst,
                               total=total,
                               submitted=True)

    return render_template("order.html", submitted=False)

if __name__ == "__main__":
    app.run(debug=True)

------------------------------
#templates/order.html
<!DOCTYPE html>
<html>
<head>
    <title>Restaurant Order</title>
</head>

<body>

<h2>Restaurant Order Form</h2>

{% with messages = get_flashed_messages() %}
    {% if messages %}
        {% for message in messages %}
            <p>{{ message }}</p>
        {% endfor %}
    {% endif %}
{% endwith %}

<form method="POST">
    Customer Name:
    <input type="text" name="name"><br><br>

    Food Item:
    <input type="text" name="food"><br><br>

    Quantity:
    <input type="number" name="quantity"><br><br>

    Price:
    <input type="number" step="any" name="price"><br><br>

    <input type="submit" value="Calculate Bill">
</form>

{% if submitted %}

<h2>Final Bill</h2>

<p>Customer Name: {{ name }}</p>
<p>Food Item: {{ food }}</p>
<p>Quantity: {{ quantity }}</p>
<p>Price: ₹{{ price }}</p>

<p>Subtotal: ₹{{ subtotal }}</p>
<p>Service Charge (5%): ₹{{ service_charge }}</p>
<p>GST (18%): ₹{{ gst }}</p>

<h3>Final Bill: ₹{{ total }}</h3>

{% endif %}

</body>
</html>
URL
http://127.0.0.1:5000/order
Calculation:
Subtotal = Quantity × Price
Service Charge = 5% of Subtotal
GST = 18% of (Subtotal + Service Charge)
Final Bill = Subtotal + Service Charge + GST
========================================================================================================================================================
20. Develop a Flask-based Student Management System using SQLite that creates a database with a student table containing id, name, age, and course fields, allows users to insert new student records, and displays all student records on the home page.
Folder Structure
project/
│
├── app.py
└── templates/
    └── index.html
======>
#app.py
from flask import Flask, render_template, request
import sqlite3

app = Flask(__name__)

def create_database():
    conn = sqlite3.connect("students.db")
    cursor = conn.cursor()

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS student (
            id INTEGER PRIMARY KEY,
            name TEXT,
            age INTEGER,
            course TEXT
        )
    """)

    conn.commit()
    conn.close()

@app.route("/", methods=["GET", "POST"])
def home():

    conn = sqlite3.connect("students.db")
    cursor = conn.cursor()

    if request.method == "POST":
        id = request.form["id"]
        name = request.form["name"]
        age = request.form["age"]
        course = request.form["course"]

        cursor.execute(
            "INSERT INTO student (id, name, age, course) VALUES (?, ?, ?, ?)",
            (id, name, age, course)
        )

        conn.commit()

    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    return render_template("index.html", students=students)

if __name__ == "__main__":
    create_database()
    app.run(debug=True)

----------------------
#templates/index.html
<!DOCTYPE html>
<html>
<head>
    <title>Student Management System</title>
</head>

<body>

<h2>Student Management System</h2>

<form method="POST">
    ID:
    <input type="number" name="id"><br><br>

    Name:
    <input type="text" name="name"><br><br>

    Age:
    <input type="number" name="age"><br><br>

    Course:
    <input type="text" name="course"><br><br>

    <input type="submit" value="Add Student">
</form>

<h2>Student Records</h2>

<table border="1">
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Age</th>
        <th>Course</th>
    </tr>
    {% for student in students %}
    <tr>
        <td>{{ student[0] }}</td>
        <td>{{ student[1] }}</td>
        <td>{{ student[2] }}</td>
        <td>{{ student[3] }}</td>
    </tr>
    {% endfor %}
</table>

</body>
</html>
URL
http://127.0.0.1:5000/
Database
When you run the application, SQLite automatically creates:
students.db
The student table contains:
id | name | age | course
========================================================================================================================================================
21. Develop a complete Flask-based Student Management System using SQLite.
Implement all CRUD operations:
● Create
● Read
● Update
● Delete
Display all records in an HTML table and verify each database operation on the web browser.
Folder Structure
project/
│
├── app.py
│
└── templates/
    └── index.html
=====>
#app.py
from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

def create_database():
    conn = sqlite3.connect("students.db")
    cursor = conn.cursor()

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS student (
            id INTEGER PRIMARY KEY,
            name TEXT,
            age INTEGER,
            course TEXT
        )
    """)

    conn.commit()
    conn.close()

@app.route("/", methods=["GET", "POST"])
def home():

    conn = sqlite3.connect("students.db")
    cursor = conn.cursor()

    if request.method == "POST":
        id = request.form["id"]
        name = request.form["name"]
        age = request.form["age"]
        course = request.form["course"]

        cursor.execute(
            "INSERT INTO student VALUES (?, ?, ?, ?)",
            (id, name, age, course)
        )
        conn.commit()
        conn.close()
        return redirect("/")

    cursor.execute("SELECT * FROM student")
    students = cursor.fetchall()

    conn.close()

    return render_template("index.html", students=students)

@app.route("/update/<int:id>", methods=["GET", "POST"])
def update(id):

    conn = sqlite3.connect("students.db")
    cursor = conn.cursor()

    if request.method == "POST":
        name = request.form["name"]
        age = request.form["age"]
        course = request.form["course"]

        cursor.execute("""
            UPDATE student
            SET name = ?, age = ?, course = ?
            WHERE id = ?
        """, (name, age, course, id))

        conn.commit()
        conn.close()

        return redirect("/")

    cursor.execute("SELECT * FROM student WHERE id = ?", (id,))
    student = cursor.fetchone()

    conn.close()

    return render_template("index.html",
                           students=[],
                           edit_student=student)

@app.route("/delete/<int:id>")
def delete(id):

    conn = sqlite3.connect("students.db")
    cursor = conn.cursor()

    cursor.execute("DELETE FROM student WHERE id = ?", (id,))

    conn.commit()
    conn.close()

    return redirect("/")

if __name__ == "__main__":
    create_database()
    app.run(debug=True)

----------------------------
#templates/index.html
<!DOCTYPE html>
<html>
<head>
    <title>Student Management System</title>
</head>

<body>

<h2>Student Management System</h2>

{% if edit_student %}

<h3>Update Student</h3>

<form method="POST" action="/update/{{ edit_student[0] }}">
    Name:
    <input type="text" name="name" value="{{ edit_student[1] }}"><br><br>

    Age:
    <input type="number" name="age" value="{{ edit_student[2] }}"><br><br>

    Course:
    <input type="text" name="course" value="{{ edit_student[3] }}"><br><br>

    <input type="submit" value="Update">
</form>

{% else %}

<h3>Add Student</h3>

<form method="POST">
    ID:
    <input type="number" name="id"><br><br>

    Name:
    <input type="text" name="name"><br><br>

    Age:
    <input type="number" name="age"><br><br>

    Course:
    <input type="text" name="course"><br><br>

    <input type="submit" value="Add Student">
</form>

{% endif %}

<h3>Student Records</h3>

<table border="1">
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Age</th>
        <th>Course</th>
        <th>Action</th>
    </tr>
    {% for student in students %}
    <tr>
        <td>{{ student[0] }}</td>
        <td>{{ student[1] }}</td>
        <td>{{ student[2] }}</td>
        <td>{{ student[3] }}</td>

        <td>
            <a href="/update/{{ student[0] }}">Edit</a>
            |
            <a href="/delete/{{ student[0] }}">Delete</a>
        </td>
    </tr>
    {% endfor %}
</table>

</body>
</html>
URL
http://127.0.0.1:5000/
CRUD Operations
Create → Add Student button
Read   → Student Records table
Update → Edit link
Delete → Delete link

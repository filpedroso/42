from flask import Flask, request, render_template, redirect, url_for
import mysql.connector
from mysql.connector import Error
import requests
import schedule
import time
import threading
from datetime import datetime



app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/students')
def students():
    try:
        connection = mysql.connector.connect(**db_config)
        cursor = connection.cursor(dictionary=True)
        cursor.execute("SELECT * FROM Students")
        students = cursor.fetchall()
    except Error as e:
        print(f"Error: {e}")
        students = []
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()
    return render_template('students.html', students=students)

@app.route('/manual_event', methods=['GET', 'POST'])
def manual_event():
    if request.method == 'POST':
        event_name = request.form['event_name']
        event_description = request.form['event_description']
        date_time = datetime.strptime(request.form['date_time'], '%Y-%m-%d %H:%M:%S')
        student_ids = request.form.getlist('student_ids')
        student_ids = [int(sid) for sid in student_ids]

        create_manual_event(event_name, event_description, date_time, student_ids)
        return redirect(url_for('index'))

    try:
        connection = mysql.connector.connect(**db_config)
        cursor = connection.cursor(dictionary=True)
        cursor.execute("SELECT id, name FROM Students")
        students = cursor.fetchall()
    except Error as e:
        print(f"Error: {e}")
        students = []
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()

    return render_template('manual_event.html', students=students)

if __name__ == '__main__':
    app.run(debug=True)

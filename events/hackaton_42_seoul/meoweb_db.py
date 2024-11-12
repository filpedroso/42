import requests
import mysql.connector
from mysql.connector import Error
import schedule
import time
from datetime import datetime

# Dict object with database connection details
db_config = {
    'host': 'localhost',
    'user': 'your_db_user',
    'password': 'your_db_password',
    'database': 'your_db_name'
}


# 42 mock API details
api_base_url = "https://api.intra.42.fr"
access_token = "42_born_to_code"

# function to fetch student data in json object
def get_student_data():
    headers = {"Authorization": f"Bearer {access_token}"}
    response = requests.get(f"{api_base_url}/v2/campus/campus_id/users", headers=headers)
    response.raise_for_status()
    return response.json()

# update meoweb's database
def update_database(student_data):
    try:
        connection = mysql.connector.connect(**db_config)
        cursor = connection.cursor()

        for student in student_data:
            student_query = """
                INSERT INTO Students (id, name, intra_username, intra_profile, slack)
                VALUES (%s, %s, %s, %s, %s)
                ON DUPLICATE KEY UPDATE name=%s, intra_profile=%s, slack=%s
            """
            student_values = (
                student['id'],
                student['name'],
                student['login'],
                student['url'],
                student.get('slack', ''),
                student['name'],
                student['url'],
                student.get('slack', '')
            )
            cursor.execute(student_query, student_values)

            # fetch and update whiskers using relationships field
            connection_query = f"{api_base_url}/v2/users/{student['id']}/relationships"
            conn_response = requests.get(connection_query, headers=headers)
            conn_response.raise_for_status()
            connections = conn_response.json()

            for connection in connections:
                whisker_query = """
                    INSERT INTO Whiskers (student1_id, student2_id)
                    VALUES (%s, %s)
                    ON DUPLICATE KEY UPDATE student1_id=student1_id
                """
                whisker_values = (
                    student['id'],
                    connection['user']['id']
                )
                cursor.execute(whisker_query, whisker_values)

        connection.commit()
    except Error as e:
        print(f"Error: {e}")
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()

# function to create a manual event
def create_manual_event(event_name, event_description, date_time, student_ids):
    try:
        connection = mysql.connector.connect(**db_config)
        cursor = connection.cursor()

        manual_event_query = """
            INSERT INTO ManualEvents (name, description, date_time)
            VALUES (%s, %s, %s)
        """
        cursor.execute(manual_event_query, (event_name, event_description, date_time))
        event_id = cursor.lastrowid

        for student_id in student_ids:
            participant_query = """
                INSERT INTO EventParticipants (event_id, student_id)
                VALUES (%s, %s)
            """
            cursor.execute(participant_query, (event_id, student_id))

        connection.commit()
    except Error as e:
        print(f"Error: {e}")
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()

# function to be scheduled
def scheduled_task():
    student_data = get_student_data()
    update_database(student_data)

# Schedule the task every 10 seconds
schedule.every(10).seconds.do(scheduled_task)

# function to run the scheduler in a separate thread
def run_scheduler():
    while True:
        schedule.run_pending()
        time.sleep(1)

# start the scheduler thread
scheduler_thread = threading.Thread(target=run_scheduler)
scheduler_thread.start()

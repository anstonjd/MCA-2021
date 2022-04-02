# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 25
Write a python application to generate student report card enter all the details of the
student required. Calculate the marks, average,and resuls, then update the
information accordingly.

---------------------------------------------------------------------------------"""

import sqlite3 as db

conn = db.Connection('student.db')
cursor = conn.cursor()
cursor.execute(
    """create table if not exists student(id integer primary key,name text,mark1 integer,mark2 integer,
    mark3 integer,total integer ,average real,result text)""")


def insert_data(stud_id, stud_name, mark1, mark2, mark3):
    total = mark1 + mark2 + mark3
    average = round(total / 3, 2)
    result = None
    if mark1 < 35 or mark2 < 35 or mark3 < 35:
        result = "failed"
    elif average >= 90:
        result = "Distinction"
    elif average >= 70:
        result = "First"
    elif average >= 50:
        result = "Second"
    elif average >= 35:
        result = "Passed"
    if cursor.execute(
            f"insert into student values({stud_id},'{stud_name}',{mark1},{mark2},{mark3},{total},{average},'{result}')"):
        print("data inserted")
    else:
        print("data insertion failed")


def display_report(stud_id: int):
    print(stud_id)
    data = cursor.execute(f"select * from student where id={stud_id}")
    data = data.fetchone()
    print(data)
    print(f"{data[1]} Report Card")
    print(f"Register Number: \t {data[0]}")
    print(f"Name: \t {data[1]}")
    print(f"Mark 1: \t {data[2]}")
    print(f"Mark 2: \t {data[3]}")
    print(f"Mark 3: \t {data[4]}")
    print(f"Total: \t {data[5]}")
    print(f"Average: \t {data[6]}")
    print(f"Result: \t {data[7]}")


while True:
    choice = int(input("Enter the choice\n1. Insert\t2. Display\t3. Commit Data\t4.Exit"))
    if choice == 1:
        stud_id = int(input("Enter the student id"))
        name = input("Enter the name")
        mark1 = int(input("Enter the 1st Mark"))
        mark2 = int(input("Enter the 2nd Mark"))
        mark3 = int(input("Enter the 3rd Mark"))

        insert_data(stud_id=stud_id, stud_name=name, mark1=mark1, mark2=mark2, mark3=mark3)
        # insert_data(stud_id=101, stud_name='zaz', mark1=60, mark2=70, mark3=80)

    elif choice == 2:
        display_report(int(input("Enter the student number: ")))

    elif choice == 3:
        conn.commit()

    elif choice == 4:
        conn.close()
        break
    else:
        print("Invalid choice.")

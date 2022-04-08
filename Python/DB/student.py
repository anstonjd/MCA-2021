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
cursor.execute("drop table if exists  student")
cursor.execute(
    """create table if not exists student(id integer primary key,name text,mark1 integer,mark2 integer,
    mark3 integer,total integer ,average real,result text)""")


class student:
    def _calculate_res(self, mark1, mark2, mark3):
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

        return {
            "total": total,
            "average": average,
            "result": result
        }

    def insert_data(self, stud_id, stud_name, mark1, mark2, mark3):
        res = self._calculate_res(mark1, mark2, mark3)
        total = res['total']
        average = res['average']
        result = res['result']
        if cursor.execute(
                f"insert into student values({stud_id},'{stud_name}',{mark1},{mark2},{mark3},{total},{average},'{result}')"):
            print("data inserted")
        else:
            print("data insertion failed")

    def update_data(self):
        stud_id = int(input("Enter the student ID whose data has to updated"))
        data=self.display_report(stud_id)
        if data is not None:
            mark1 = int(input("Enter the mark 1: "))
            mark2 = int(input("Enter the mark 2: "))
            mark3 = int(input("Enter the mark 3: "))
            res = self._calculate_res(mark1, mark2, mark3)
            total = res['total']
            average = res['average']
            result = res['result']
            if cursor.execute(
                    f"""update student set name='{name}', mark1={mark1},mark2={mark2},mark3={mark3},total='{total}',
                    average='{average}',result='{result}' where id={stud_id}"""):
                print("Data successfully updated")
            else:
                print("Data updation failed")


    def delete_data(self):
        stud_id = int(input("Enter the student id you wish to delete: "))
        if cursor.execute(f"delete from student where id={stud_id}"):
            print("Data successfully deleted")
        else:
            print("Data deletion failed")

    def display_report(self, stud_id: int):
        # print(stud_id)
        data = cursor.execute(f"select * from student where id={stud_id}")
        data = data.fetchone()
        if data is not None:
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
        else:
            print("Data not found")

        return data


while True:
    st = student()
    choice = int(input("Enter the choice\n1. Insert\t2. Display\t3.Update Data\t4.Delete Data\t5. Commit Data\t6.Exit\n"))
    if choice == 1:
        stud_id = int(input("Enter the student id: "))
        name = input("Enter the name: ")
        mark1 = int(input("Enter the 1st Mark: "))
        mark2 = int(input("Enter the 2nd Mark: "))
        mark3 = int(input("Enter the 3rd Mark: "))

        st.insert_data(stud_id=stud_id, stud_name=name, mark1=mark1, mark2=mark2, mark3=mark3)
        # insert_data(stud_id=101, stud_name='zaz', mark1=60, mark2=70, mark3=80)

    elif choice == 2:
        st.display_report(int(input("Enter the student number: ")))

    elif choice == 3:
        st.update_data()

    elif choice == 4:
        st.delete_data()

    elif choice == 5:
        conn.commit()

    elif choice == 6:
        conn.close()
        break
    else:
        print("Invalid choice.")

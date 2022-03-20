'''----------------------------------------------------------------------------------
'Lab 10 old
Consider the scenario from student management system and perform the following

i) accept student id and validate whether it contains only digits.

i) if student_id is valid, accept student name from the user and valida whether it contains

only alphabets.

ii) if student name is valid, accept fecs amount paid by the student • Decimal point is optional à fees amount

. Only two digits are allowed after decimal point.
iv) if invalid data is entered in any of the above steps, display appropriate error messages, else
create an email id for student as student name@ABC.com Where ABC is the name of
college. Assume there are no duplicate names.
v) Perform above validation using regular expression and print detailsstudent.

student id, student name, fees amount, email_id

--------------------------------------------------------------------------------- '''
import re


class Student:
    selftudentInfoArray = []

    def __init__(self):
        self.collegeName = "MyCollege"
        self.studentid = int
        self.studentName = ""
        self.studentFees = float

        self.takeInput()

    def takeInput(self):
        student_id = input("Enter the student Id")
        if re.match('^-?[\d]+$', student_id):
            self.studentid = student_id

        else:
            print("id isnt in digit")
            return
        student_name = input("Enter student name")
        if re.match('^[A-Za-z]+$', student_name):
            for student in self.selftudentInfoArray:
                if student['student_name'] == student_name:
                    print("Student already exists")
                    return
            self.studentName = student_name

        else:
            print("Name isnt string")
            return
        fees = float(input("enter the fees"))
        self.studentFees = format(fees, ".2f")

        self.selftudentInfoArray.append({
            "student_name": self.studentName,
            "student_id": self.studentid,
            "student_fees": self.studentFees,
        })

        print(f"{student_name}@{self.collegeName}.com")

        print(f"The name is {self.studentName} ")
        print(f"The id is {self.studentid} ")
        print(f"The fees is {self.studentFees} ")


conti = True

while conti:
    perm = input("Do you want to continue y or n")
    conti = True if perm.lower() == "y" else False
    s = Student()

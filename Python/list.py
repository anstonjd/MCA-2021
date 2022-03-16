'''----------------------------------------------------------------------------------
Lab8.py
Write a python program to satisfy the following requirements:
 a) List number of student who enrolled for python course.
b) List number of student who enrolled for RDBMS Course Only
 c) List number of student who enrolled for RDBMS Python Only
 d) List number and name of the student for both RDBMS Python Only
 e) List number and name of the student for either RDBMS or Python not for both
f) List number and name of the student for either RDBMS or Python

----------------------------------------------------------------------------------'''

students = [

    ['ABC',
     ['rdbms', 'python', 'stats']
     ],
    ['Sam',
     ['rdbms']
     ]
]


def insertData():
    name = input('enter the name: ')
    courses = []
    while True:
        courses.append(input("enter the subject: "))
        if input("do you want to enter new subject: ").lower() != 'y':
            break
    students.append([name, courses])


while True:
    print('''0) Insert
1) List number of student who enrolled for python course.
2) List number of student who enrolled for RDBMS Course Only
3) List number of student who enrolled for RDBMS Python Only
4) List number and name of the student for both RDBMS Python Only
5) List number and name of the student for either RDBMS or Python not for both
6) List number and name of the student for either RDBMS or Python.
7) Exit
''')
    choice = int(input("insert the choice: "))
    if choice == 0:
        insertData()
        print(students)
    if choice == 1:
        count = 0
        for student in students:
            if 'python' in student[1]:
                count += 1
        print(f'The count is {count}')

    if choice == 2:
        count = 0
        for student in students:
            if len(student[1]) == 1 and 'rdbms' in student[1]:
                count += 1
        print(f'The count is {count}')

    if choice == 3:
        count = 0
        for student in students:

            if (len(student[1]) == 1) and ('rdbms' or 'python' in student[1]):
                count += 1
        print(f'The count is {count}')

    if choice == 4:
        count = 0
        for student in students:
            if (len(student[1]) == 2) and ('rdbms' in student[1] and 'python' in student[1]):
                count += 1
                print(student[0])
        print(f'The count is {count}')

    if choice == 5:
        count = 0
        for student in students:
            both_are_there = 0
            if 'rdbms' in student[1]:
                both_are_there += 1
            if 'python' in student[1]:
                both_are_there += 1
            if both_are_there == 1:
                count += 1
                print(student[0])
        print(f'The count is {count}')

    if choice == 6:
        count = 0
        for student in students:
            if 'rdbms' or 'python' in student[1]:
                count += 1
                print(student[0])
        print(f'The count is {count}')
    if choice == 7:
        break

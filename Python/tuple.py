# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 13
Write a python program using tuple to satisfy following business requirements:
    a) List the number of courses opted by student “John”
    b) List all the courses opted by student “John”
    c) Student “John” is also interested in elective course mentioned above. Print the
    updated tuple including electives.
    d) Check whether student “john” is allowed to change his course from SE to
    Computer network.
    Consider the list of courses opted by a student “john” and available electives as a part of
    student Management System.
    Courses: (“Python Programming”, ”RDBMS”, ”Web Technology”,
    “Software Engineering”)
    Electives:(”Business Intelligence”, Big Data Analytics”)

---------------------------------------------------------------------------------"""
john_courses = ('Python Programming', 'RDBMS', 'Web Technology', 'Software Engineering')
electives = ('Business Intelligence', 'Big Data Analytics')
print(f"the number of courses opted by student John : {len(john_courses)}")
print(f"The courses opted by student John : \n{john_courses}")
newjohncourses = john_courses + electives
print(f"John courses after adding electives: \n{newjohncourses}")

courses_list = list(newjohncourses)
courses_list[courses_list.index('Software Engineering')] = 'Computer network'
newjohncourses = tuple(courses_list)
print(f"John courses after chaging: \n {newjohncourses}")
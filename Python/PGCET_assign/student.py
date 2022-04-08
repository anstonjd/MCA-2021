class Student:
    reg_no = 180000
    count = 0

    def __init__(self, student_name=None, address=None, contact_number=None, marks=None):
        Student.reg_no += 1
        self._reg_no = Student.reg_no
        self._student_name = student_name
        self._address = address
        self._contact_num = contact_number
        self._marks = marks
        Student.count += 1

    def display(self):
        print(f"the name is {self._student_name}")
        print(f"the regno is {self._reg_no}")
        print(f"the contact is {self._contact_num}")
        print(f"the marks is {self._marks}")


data = []
while True:
    ch = int(input("Enter your choice.\n1.Input\t2.display count\t3.display data\n"))
    if ch == 1:
        name = input("enter the name")
        address = input("enter the address")
        contact = input("enter the contact")
        marks = input("enter the marks")
        st = Student(name, address, contact, marks)
        data.append(st)
    elif ch == 2:
        print(f"The count is {Student.count}")
    elif ch == 3:
        i = 1
        for student in data:
            print(f"Student {i} data:")
            student.display()
            print("\n\n")
    elif ch == 4:
        break
    else:
        print("Invalid choice")

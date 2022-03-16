'''----------------------------------------------------------------------------------
Lab1.py
Write a Python Program to display the student marks card in a proper format

----------------------------------------------------------------------------------'''
name = input("Enter the name:  ")
clas = input("Enter the class: ")
regno = input("Enter the Register Number: ")

total = 0
mark1 = int(input(f"Enter the subject 1 marks"))
mark2 = int(input(f"Enter the subject 2 marks"))
mark3 = int(input(f"Enter the subject 3 marks"))
mark4 = int(input(f"Enter the subject 4 marks"))
mark5 = int(input(f"Enter the subject 5 marks"))
mark6 = int(input(f"Enter the subject 6 marks"))

total = mark1 + mark2 + mark3 + mark4 + mark5 + mark6
print(f"The name is {name}")
print(f"The class is {clas}")
print(f"The regno is {regno}")

print(f"The 6 subject marks are ")
print(f"Subject 1 marks is {mark1}")
print(f"Subject 2 marks is {mark2}")
print(f"Subject 3 marks is {mark3}")
print(f"Subject 4 marks is {mark4}")
print(f"Subject 5 marks is {mark5}")
print(f"Subject 6 marks is {mark6}")

print(f"The total is {total}")

print(f"The average is {round(total / 6, 0)}")

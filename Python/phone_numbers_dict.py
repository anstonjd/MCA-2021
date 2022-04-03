'''----------------------------------------------------------------------------------
'Lab 6 old
Write a Python program to input 'n' names and phone numbers to store it a dictionary
and print the phone number of a particular name

--------------------------------------------------------------------------------- '''

info = {}


def input_elements():
    name = input("Enter the name: ")
    phone = ""
    while len(phone) != 10:
        phone = str(input("Enter the phone Number: "))
    new_data = {
        "name": name,
        "phone": phone
    }
    info[name] = new_data
    print(new_data)


def find_element(name: str):
    if info[name]:
        print(f"Phone number of name {name} is : {info[name]['phone']}")
    else:
        print("Not found")


def main():

    while True:
        choice = int(input("Enter the choice \n1.Insert\t2.Find by Name\t3.Exit\nYour choice: "))
        if choice == 1:
            input_elements()
        elif choice == 2:
            find_element(str(input("Enter the name :")))
        elif choice == 3:
            break
        else:
            print("Invalid choice")


main()

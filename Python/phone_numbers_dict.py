'''----------------------------------------------------------------------------------
'Lab 6 old
Write a Python program to input 'n' names and phone numbers to store it a dictionary
and print the phone number of a particular name

--------------------------------------------------------------------------------- '''

info = {}


def input_elements():
    name = input("Enter the name")
    phone = int(input("Enter the phone Number"))
    new_data = {
        "name": name,
        "phone": phone

    }
    info[phone] = new_data


def find_element(phone_num: int):
    if info[phone_num]:
        print(info[phone_num]['name'])
    else:
        print("Not found")


def main():
    number_of_elements = int(input("Enter the number of elements"))
    while number_of_elements > 0:
        input_elements()
        number_of_elements -= 1

    phone_to_find = int(input("Enter the Phone number to find: "))
    find_element(phone_to_find)


main()

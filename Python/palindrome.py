'''----------------------------------------------------------------------------------
Lab4.py
Write a Python program to check for palindrome. Input a string from the keyboard. The string can have alphabets, spaces, question marks, periods and apostrophes only. Check whether the string is a palindrome

--------------------------------------------------------------------------------- '''
input_string = input("Enter the string:")

allowed_chr = ['?', ' ', '.', "'"]
string_acceptable = True
flag = True
for element in input_string:
    if not element.isdigit() and not element.isalpha() and not element in allowed_chr:
        string_acceptable = False
if string_acceptable:
    for i in range(int(len(input_string) / 2)):
        if input_string[i] != input_string[(len(input_string) - 1) - i]:
            flag = False
            break

print("Is palindorme" if flag and string_acceptable else "Not a palinrome")

# print("Is palindorme" if flag else "Not a palinrome")

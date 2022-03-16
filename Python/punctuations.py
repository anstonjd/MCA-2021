'''----------------------------------------------------------------------------------
Lab3.py
Write python program to remove all punctuation from the string provided by the user.

----------------------------------------------------------------------------------'''

symbolList = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
user_in = input("Enter the string")
newString = ""
for element in user_in:
    if element not in symbolList:
        newString += element
print("The string with all the punctuations removed : ")
print(newString)

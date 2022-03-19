'''----------------------------------------------------------------------------------
'Lab 9
Write a Python program to perform linear search on a list of integers. Input the
content of the list.

--------------------------------------------------------------------------------- '''

numberList = []
while True:
    element = input("Enter the element to be inserted.  Enter a non digit to exit inserting: ")

    if not element.isdigit():
        print(numberList)
        break
    else:
        numberList.append(int(element))

searchingElement = int(input("Enter the element to be searched: "))

flag = False
for element in numberList:
    if element == searchingElement:
        print("Element Found")
        flag = True
        break
if not flag:
    print("Element not found")

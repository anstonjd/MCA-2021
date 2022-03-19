'''----------------------------------------------------------------------------------
'Lab 11
Write a Python function that takes a list of integers as parameter. The
function creates two smaller lists from the parameter. One list contains
odd and another even numbers from the bigger list.

--------------------------------------------------------------------------------- '''


def splitList(numbers: list):
    evenList = []
    oddList = []

    for element in numbers:
        if element % 2 == 0:
            evenList.append(element)
        else:
            oddList.append(element)
    print(f"The even list is {evenList}")
    print(f"The odd list is {oddList}")


numbersList = []
limit = int(input("Enter the number of elements"))
for i in range(limit):
    element = int(input(f"Enter the {i + 1} element"))
    numbersList.append(element)
splitList(numbersList)

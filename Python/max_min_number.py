'''----------------------------------------------------------------------------------
'Lab 10
Write a Python function that takes a list of integers as parameter. The
function returns the maximum and minimum numbers from the list

--------------------------------------------------------------------------------- '''


def maxMinFunc(numbers: list):
    maxNumber = numbers[0]
    minNumber = numbers[0]
    for number in numbers:
        if number > maxNumber:
            maxNumber = number
        if number < minNumber:
            minNumber = number

    print(f"The Maximum number is {maxNumber}")
    print(f"The Minimum number is {minNumber}")


numbersList = []
number_of_elements_to_be_inserted = 5
for i in range(number_of_elements_to_be_inserted):
    numbersList.append(int(input(f"Enter the {i + 1} element: ")))

maxMinFunc(numbersList)

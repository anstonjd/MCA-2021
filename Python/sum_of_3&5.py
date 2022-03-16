'''----------------------------------------------------------------------------------
Lab7.py
Write a function that returns the sum of multiples of 3 and 5 between 0 and limit (parameter). For example, if limit is 20, it should return the sum of 3, 5,6, 9, 10, 12, 15, 18, 20.
Regno: 2117012
29/01/2022
----------------------------------------------------------------------------------'''


def findSum(limit: int):
    sum = 0
    for i in range(1, limit):
        if i % 3 == 0 or i % 5 == 0:
            sum += i
    return sum


limit = int(input("Enter the limit"))
result = findSum(limit)
print(f"The sum of 3 and 5 multiples between 1 and {limit} is {result}")

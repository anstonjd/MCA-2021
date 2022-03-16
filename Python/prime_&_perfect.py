'''----------------------------------------------------------------------------------
'Lab2.py
Write a python program to print the prime and perfect number from 1 to 100.

--------------------------------------------------------------------------------- '''

# prime numbers
prime = [1, 2]
for i in range(3, 100):
    flag = True
    for j in range(2, int(i / 2) + 1):
        if i % j == 0:
            flag = False
    if flag:
        prime.append(i)
print(f"prime numbers are {prime}")

# perfect number
print("perfect numbers are: ")
for i in range(1, 100):
    sum_of_numbers = 0
    for j in range(1, i):
        if i % j == 0:
            sum_of_numbers += j

    if sum_of_numbers == i:
        print(i, end=",")

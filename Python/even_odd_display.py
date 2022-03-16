'''----------------------------------------------------------------------------------
Lab6.py
Write a function called showNumbers that takes a parameter called limit. It should print all the numbers between 0 and limit with a label to identify the even and odd numbers. For example, if the limit is 3, it should print:
o 0 EVEN
o 1 ODD
o 2 EVEN
o 3 ODD

----------------------------------------------------------------------------------'''


def showNumbers(limit: int):
    for i in range(1, limit):
        print(f"{i}  EVEN") if (i % 2) == 0 else print(f"{i}  ODD")


limit = int(input("Enter the limit"))
showNumbers(limit)

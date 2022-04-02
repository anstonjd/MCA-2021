# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 15
Write a python script
1) To generate and print a dictionary that contains a number(between 1 and n) in the
form (x,x*x) .
2) To Map two list into dictionary.

---------------------------------------------------------------------------------"""
final_dict = {}

n = int(input("Enter the limit number: "))

for i in range(n + 1):
    final_dict[i] = i * i

print(final_dict)

list1 = [int(item) for item in input("Enter the keys: ").split()]
list2 = [int(item) for item in input("Enter the values: ").split()]
final_dict_2 = dict(zip(list1, list2))

print(final_dict_2)

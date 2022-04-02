# Last Updated: 25 March 2022
'''--------------------------------------------------------------------------------------------------------------------
Write a python program to perform

i) Reverse in descending order, union in ascending order, intersection in ascending order using the input present in the file.

ii) Print the output as well as save the file in the new file with file name as 'output program <<programnumber>>_
<<registernumber>> <<year>> <<month>> <<date>>.txt'

iii) Output of reverse, union, intersection should be printed in newline.

iv) Copy the program file from existing file destination to location where your input and out file is present.
----------------------------------------------------------------------------------------------------------------------'''


# TODO: REQUIREMENTS: CREATE A FILE NAMED 'input.txt' WHICH WILL HAVE THE INPUT YOU WANNA GIVE
# SAMPLE FILE:
# ************
# ABC AB ACB
# ABC BCA MCA
# UTH ABC CEBA
# PCMB CEBA CSBA ABC
# HEBA ABC BBA MBA
# ************

from datetime import datetime as dt

DATE_TODAY = dt.now()
PROGRAM_NUMBER = 9
REGISTER_NUMBER = 2117009
# TODO: seconds are added at last of the below variable REMOVE if not needed
DATE_TODAY_STRING = dt.strftime(DATE_TODAY, '%Y_%B_%d_%S')
RESULT_FILE_NAME = f"output_program_{PROGRAM_NUMBER}_{REGISTER_NUMBER}_{DATE_TODAY_STRING}"

reverse_array = ""
arr = []
title_print_flag = True


# file writing function
def print_write(writing_data, title: str = None):
    with open(f"{RESULT_FILE_NAME}.txt", 'a') as result_file:
        if title_print_flag:
            print(f"\n\n{title} : \n")
            result_file.write(f'\n\n{title}: \n\n')

        for ele in writing_data:
            result_file.write(f"{ele} ")
            print(f"{ele}", end=" ")
        result_file.write('\n')
        print()


with open('input.txt', 'r') as input_file:
    filedata = input_file.readlines()

# print(filedata)

for data in filedata:
    arr.append(data.rstrip('\n').split(','))

reverse_array = arr[::-1]

# reverse
for line in reverse_array:
    result_line = line[0].split(' ')[::-1]
    print_write(result_line, "Reverse String")
    title_print_flag = False
title_print_flag = True

# UNION

union_set = set()

for element in arr:
    line_data = element[0].split(' ')
    union_set = union_set.union(set(line_data))

print_write(union_set, "Union")

# intersection data

intersection_set = union_set

for element in arr:
    line_data = element[0].split(' ')
    intersection_set = intersection_set.intersection(set(line_data))

print_write(intersection_set, "Intersection")

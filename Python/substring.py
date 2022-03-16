'''----------------------------------------------------------------------------------
Lab5.py
Write a Python program to Count overlapping substring in a given string

--------------------------------------------------------------------------------- '''


def count_occurances(input_string, sub_string):
    count = 0
    start_position = 0

    while start_position < len(input_string):
        position = input_string.find(sub_string, start_position)
        if position != -1:
            start_position = position + 1
            count += 1
        else:
            start_position += 1
    return count


input_str = input("Enter the string: ")
sub_str = input("Enter the string to be counted: ")
print(count_occurances(input_str, sub_str))

# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 20
There is a file with several text messages. Each message is in its own line. Write a
Python program to count the number of lines in the file and the total number of
words contained in those messages. Assume the messages contain only alphabets,
and numbers.

---------------------------------------------------------------------------------"""

with open('input.txt', 'r') as file:
    file_content_list = file.readlines()
    number_of_lines = len(file_content_list)
    word_length = 0
    for line in file_content_list:
        word_length += len(line.split(" "))

print(f"The number of lines are : {number_of_lines}")
print(f"The number of words in the file are : {word_length}")

'''----------------------------------------------------------------------------------
'Lab 7 old
Write a Python program to sort the elements in the array using bubble sort technique
and display the elements in descending order

--------------------------------------------------------------------------------- '''

from bubble_sort_module import bubble_sort as bb
import array

elements = array.array('i')
number_of_elements = int(input("Enter the number of elements: "))
for i in range(number_of_elements):
    elements.append(int(input(f"enter the element {i + 1} : ")))

sorted_list = bb.bubble_sort(elements)
for i in range(len(sorted_list)-1,-1,-1):
    print(sorted_list[i],end="\t")

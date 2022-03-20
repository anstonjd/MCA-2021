def bubble_sort(elements: list):
    length_of_array = len(elements)
    for i in range(length_of_array):
        for j in range(length_of_array - 1):
            if elements[j] > elements[j + 1]:
                elements[j], elements[j + 1] = elements[j + 1], elements[j]
    return elements

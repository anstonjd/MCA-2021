input_string = input("Enter the input string")
count_string = {}
if input_string.isalpha():
    input_string = input_string.lower()
    for element in input_string:
        if element in count_string.keys():
            count_string[element] += 1

        else:
            count_string[element] = 1

    max = 0
    val = ""

    for key, value in count_string.items():
        if value > max:
            max = value
            val = key

    print(count_string)
    print(f"max count character is '{val}' repeating {max} times")

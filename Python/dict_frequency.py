# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 16
Write a function called string_dict that will take as parameter a string. The string
can have alphabets, spaces, question marks, periods and apostrophes only. The
function returns a dictionary. The keys of the dictionary should be the words from
the original string, and the values should be the frequency of that word.

---------------------------------------------------------------------------------"""


class UnwantedElementsException(Exception):
    def __init__(self, key):
        self._errorMessage = key

    def display_error(self):
        print(f"Not a valid data: {self._errorMessage} ")


def string_dict(user_input: str):
    try:
        final_dict = {}
        user_input_list = user_input.split(' ')
        for ele in user_input_list:
            flag = True
            if not ele.isalnum():
                if '?' not in ele and '.' not in ele:
                    flag = False
            if flag:
                if ele in final_dict.keys():
                    final_dict[ele] = final_dict[ele] + 1
                else:
                    final_dict[ele] = 1

            else:
                raise UnwantedElementsException(ele)

        return final_dict
    except UnwantedElementsException as uee:
        uee.display_error()


user_in = input("Enter the sentence: ")
final_d = string_dict(user_in)
print(final_d)

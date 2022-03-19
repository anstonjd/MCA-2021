'''----------------------------------------------------------------------------------
'Lab 12
Write a function called attendance_check. attendance_check should have
two parameters: roster and present. Both roster and present will be lists
of strings. Return a list (sorted alphabetically) of all strings in the list
roster that are not in the list present. In other words, if roster is a list of
students enrolled in a class and present is a list of students in class
today, return a list of students that are absent. You may assume that
every item in each list will be a string. You may also assume that every
name in the list present will be in the list roster. If no students are
absent, return an empty list.

--------------------------------------------------------------------------------- '''


def attendance_check(roster: list, present: list):
    absentees = [element for element in roster if element not in present]
    absentees.sort()
    return absentees


roster_list = ["Jessica", "Nick", "Winston", "Schmidt", "Cece", "Ferguson"]
present_list = ["Jessica",  "Schmidt", "Cece", "Ferguson"]
print(attendance_check(roster_list, present_list))

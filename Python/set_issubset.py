'''----------------------------------------------------------------------------------
'Lab 13
Write a python program to check whether the given is subset of a set or a super set of a set

--------------------------------------------------------------------------------- '''
set1 = set()
set2 = set()

print("******SET 1******")
num_of_char = int(input("Enter the num of characters for set 1"))
for i in range(num_of_char):
    char = int(input("Enter the char "))
    set1.add(char)

print("******SET 2******")
num_of_char = int(input("Enter the num of characters for set 2"))
for i in range(num_of_char):
    char = int(input("Enter the char "))
    set2.add(char)

print("set 1 is subset of set 2" if set1.issubset(set2) else "set 1 is not the subset of set 2")
print("set 1 is superset of set 2" if set1.issuperset(set2) else "set 1 is not the superset of set 2")

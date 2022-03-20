'''----------------------------------------------------------------------------------
'Lab 12 old Create an abstract
class Relation with abstract method to implement t basic relational operators (-.,-) on two integers. Define class
numbe with two data fields (N), N2) which extends class Relation and illustrate the main class. (hint: use user
module all the three program in different fil like sample car example.)

--------------------------------------------------------------------------------- '''
from relational_operators_module import numbers as num_mod

num1 = float(input("Enter the number 1: "))
num2 = float(input("Enter the number 2: "))

c = num_mod.Number(num1, num2)
print(f"Equals to: {c.equals_to()}")
print(f"Greater than: {c.greater_than()}")
print(f"Lesser than: {c.lesser_than()}")
print(f"Greater than or equal: {c.greater_than_equals()}")
print(f"Lesser than or equal: {c.lesser_than_equals()}")

'''----------------------------------------------------------------------------------
'Lab 11 old
Program to illustrate Multilevel inhertance Box (length,breadth,,height) as the super class. Boxweight (weight) a
Boxshipment (cost) as the subclasses. Illustate the use of super keyword constructor assign the value not zero.

--------------------------------------------------------------------------------- '''


class Box:
    def __init__(self, length: float, breadth: float, height: float):
        self.length = length
        self.breadth = breadth
        self.height = height

    def display(self):
        print(f"The length is {self.length}")
        print(f"The breadth is {self.breadth}")
        print(f"The height is {self.height}")


class Boxweight(Box):
    def __init__(self, weight: float, length: float, breadth: float, height: float):
        super().__init__(length, breadth, height)
        self.weight = weight

    def display(self):
        super().display()
        print(f"The weight is {self.weight}")


class Boxshipment(Boxweight):
    def __init__(self, cost: float, weight: float, length: float, breadth: float, height: float):
        super().__init__(weight, length, breadth, height)
        self.cost = cost

    def display(self):
        super().display()
        print(f"The cost is {self.cost}")


user_length = float(input("Enter the Length: "))
user_breadth = float(input("Enter the Breadth: "))
user_height = float(input("Enter the Height: "))
user_weight = float(input("Enter the Weight: "))
user_cost = float(input("Enter the Cost: "))

bs = Boxshipment(length=user_length, breadth=user_breadth, height=user_height, weight=user_weight, cost=user_cost)
bs.display()

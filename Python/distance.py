# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 22
Write a class Distance with instance variables feet and inches. Include necessary
methods. Test the class


---------------------------------------------------------------------------------"""


class Distance:
    def __init__(self, feet=None, inches=None):
        self.feet: float = feet
        self.inches: float = inches

    def input_data(self):
        self.feet = float(input("Enter the feet: "))
        self.inches = float(input("Enter the inches: "))

    def add_distance(self, distance):
        newfeet = (distance.feet + self.feet) + int((distance.inches + self.inches) / 12)
        newinches = (distance.inches + self.inches) % 12
        return Distance(feet=newfeet, inches=newinches)

    def display(self):
        print(f"The feet : {self.feet}")
        print(f"The inches : {self.inches}")


obj1 = Distance()
obj1.input_data()
obj1.display()

obj2 = Distance()
obj2.input_data()
obj2.display()

print("adding two objects")
newobj = obj1.add_distance(obj2)
newobj.display()

# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 21
Program to illustrate multilevel inheritance Box (length,breadth,,height) as the super
class. Boxweight (weight) and Boxshipment (cost) as the subclasses. Illustate the use
of super keywords, constructor assign the value not zero

---------------------------------------------------------------------------------"""
class Box:
    def __init__(self, length, breadth, height):
        self.length = length
        self.breadth = breadth
        self.height = height

    def dislplay(self):
        print(f"The length is {self.length}")
        print(f"The breadth is {self.breadth}")
        print(f"The height is {self.height}")


class BoxWeight(Box):
    def __init__(self, length, breadth, height, weight):
        super(BoxWeight, self).__init__(length, breadth, height)
        self.weight = weight

    def dislplay(self):
        super(BoxWeight, self).dislplay()
        print(f"The weight is {self.weight}")


class BoxShipment(BoxWeight):
    def __init__(self, length, breadth, height, weight, shipment):
        super(BoxShipment, self).__init__(length, breadth, height, weight)
        self.shipment = shipment

    def dislplay(self):
        super(BoxShipment, self).dislplay()
        print(f"The shipment is {self.shipment}")


bs = BoxShipment(4, 5, 6, 34, 650)
bs.dislplay()

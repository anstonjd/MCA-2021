from .relation import Relation


class Number(Relation):

    def __init__(self, num1, num2):
        super().__init__()
        self.N1 = num1
        self.N2 = num2

    def equals_to(self):
        return self.N1 == self.N2

    def greater_than(self):
        return self.N1 > self.N2

    def lesser_than(self):
        return self.N1 < self.N2

    def greater_than_equals(self):
        return self.N1 >= self.N2

    def lesser_than_equals(self):
        return self.N1 <= self.N2

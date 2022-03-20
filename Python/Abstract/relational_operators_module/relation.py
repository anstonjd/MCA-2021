from abc import ABC, abstractmethod


class Relation(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def equals_to(self):
        pass

    @abstractmethod
    def greater_than(self):
        pass

    @abstractmethod
    def lesser_than(self):
        pass

    @abstractmethod
    def greater_than_equals(self):
        pass

    @abstractmethod
    def lesser_than_equals(self):
        pass

#!/usr/bin/env python

class Plant:
    def __init__(self, name: str, height: float, age: float,
                 growth_factor: float):
        self.name = name
        self.height = height
        self.age = age
        self.growth_factor = round(growth_factor, 1)
        print(f"Created: {self.name.capitalize()}: {
              self.height}cm, {self.age} days old")

    name: str
    height: float
    growth_factor: float
    age: float

    def show(self):
        print(f"{self.name.capitalize()}: {
              self.height}cm, {self.age} days old")

    def age(self):
        ++self.age

    def grow(self):
        self.height = round(self.height * self.growth_factor, 1)


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    p0 = Plant("Rose, not pink", 120, 21, 1.2)
    p1 = Plant("Ginseng, the plant present in monster, the drink", 53, 3, 1.1)
    p2 = Plant("Ginger, the immuniser", 10, 40, 1.5)
    p3 = Plant("Ivy, the devorer of worlds", 250, 2, 2)
    p4 = Plant("Strawberry, a good sirup flavor", 2, 21, 1.3)

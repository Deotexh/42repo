#!/usr/bin/env python

class Plant:
    def __init__(self, name: str, height: float, age: float,
                 growth_factor: float):
        self.name = name
        self.height = height
        self.age = age
        self.growth_factor = round(growth_factor, 1)

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
    total_growth: float = 0
    i: int = 0
    plant = Plant("Ivy, the spanish gargoyle", 28.3, 3, 1.4)

    print("=== Garden Plant Growth ===")
    plant.show()
    for i in range(1, 8):
        print(f"=== Day {i} ===")
        total_growth += round(plant.height * plant.growth_factor, 1)
        plant.age()
        plant.grow()
        plant.show()
    print(f"Growth this week: {total_growth}cm")

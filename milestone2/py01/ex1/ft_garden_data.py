#!/usr/bin/env python

class Plant:
    def __init__(self, name: str, height: int, age: float):
        self.name = name
        self.height = height
        self.age = age

    name: str
    height: int
    age: float

    def show(self):
        print(f"{self.name.capitalize()}: {
              self.height}cm, {self.age} days old")


if __name__ == "__main__":
    kel: Plant = Plant("Cactus", 328400000, 0.000023148)
    basil: Plant = Plant("Sunflower", 168, 5844)
    sunny: Plant = Plant("Tulip", 163, 5844)
    print("=== Garden Plant Registry ===")
    sunny.show()
    basil.show()
    kel.show()

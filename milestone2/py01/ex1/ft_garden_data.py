#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, days_old: int):
        self.name = name
        self.height = height
        self.days_old = days_old

    name: str
    height: int
    days_old: int

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {
              self.height}cm, {self.days_old} days old")


if __name__ == "__main__":
    kel: Plant = Plant("Cactus", 328400000, 0)
    basil: Plant = Plant("Sunflower", 168, 5844)
    sunny: Plant = Plant("Tulip", 163, 5844)
    print("=== Garden Plant Registry ===")
    sunny.show()
    basil.show()
    kel.show()

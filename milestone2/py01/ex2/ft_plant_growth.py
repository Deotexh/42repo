#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, days_old: int,
                 growth_factor: float):
        self.name = name
        self.height = height
        self.days_old = days_old
        self.growth_factor = round(growth_factor, 1)

    name: str
    height: float
    growth_factor: float
    days_old: int

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {
              self.height}cm, {self.days_old} days old")

    def age(self) -> None:
        self.days_old += 1

    def grow(self) -> None:
        self.height = round(self.height * self.growth_factor, 1)


if __name__ == "__main__":
    total_growth: float = 0
    i: int = 0
    plant = Plant("Ivy, the spanish gargoyle", 28.3, 3, 1.4)

    print("=== Garden Plant Growth ===")
    plant.show()
    for i in range(1, 8):
        print(f"=== Day {i} ===")
        total_growth += round(plant.height * plant.growth_factor - plant.height, 1)
        plant.age()
        plant.grow()
        plant.show()
    print(f"Growth this week: {total_growth}cm")

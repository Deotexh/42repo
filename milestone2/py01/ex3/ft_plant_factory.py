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
    print("=== Plant Factory Output ===")
    p0 = Plant("Rose, not pink", 120, 21, 1.2)
    p0.show()
    p1 = Plant("Ginseng, the plant present in Monster, the drink", 53, 3, 1.1)
    p1.show()
    p2 = Plant("Ginger, the immuniser", 10, 40, 1.5)
    p2.show()
    p3 = Plant("Ivy, the devorer of worlds", 250, 2, 2)
    p3.show()
    p4 = Plant("Strawberry, a good sirup flavor", 2, 21, 1.3)
    p4.show()

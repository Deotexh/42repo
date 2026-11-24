#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, days_old: int,
                 growth_factor: float):
        if (days_old < 0 or height < 0):
            print("Might aswell create hollow purple no?")
            print("Yeah, get your defaults")
            self.name = "Depressed magenta"
            self._height = 1000
            self._days_old = 0
            self._growth_factor = 0.5
        else:
            self.name = name
            self._height = height
            self._days_old = days_old
            self._growth_factor = round(growth_factor, 1)

    name: str
    _height: float
    _growth_factor: float
    _days_old: int

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {
              self._height}cm, {self._days_old} days old")

    def age(self) -> None:
        self._days_old += 1

    def grow(self) -> None:
        self._height = round(self._height * self._growth_factor, 1)

    def get_height(self) -> float:
        return (self._height)

    def set_height(self, new_height: float) -> None:
        if (new_height < 0):
            print("Invalid height inputted, aborting...You stupid skyscrapper")
            return
        self._height = new_height

    def get_age(self) -> int:
        return (self._days_old)

    def set_age(self, new_age: int) -> None:
        if (new_age < 0):
            print("Invalid age inputted, aborting...You old clapped brick")
            return
        self._days_old = new_age


if __name__ == "__main__":
    print("=== Garden Securty System ===")
    plant = Plant("Rose, not pink", 120, 21, 1.2)
    plant.show()

    plant.set_height(-12)
    plant.set_age(-42)

    plant.show()

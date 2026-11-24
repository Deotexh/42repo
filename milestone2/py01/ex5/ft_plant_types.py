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


class Flower(Plant):
    def __init__(self, name: str, height: float, days_old: int,
                 growth_factor: float, color: str, is_blooming: bool = False):
        super().__init__(name, height, days_old, growth_factor)
        self.color = color
        self.is_blooming = is_blooming

    color: str
    __is_blooming: bool

    def bloom(self) -> None:
        self.is_blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color.lower()}")
        if (self.is_blooming):
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, days_old: int,
                 growth_factor: float, trunk_diameter: float):
        super().__init__(name, height, days_old, growth_factor)
        self.trunk_diameter = round(trunk_diameter, 1)

    trunk_diameter: float

    def shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of {
              self._height}cm long and {self.trunk_diameter}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, days_old: int,
                 growth_factor: float, harvest_season: str,
                 nutritional_value: int):
        super().__init__(name, height, days_old, growth_factor)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    harvest_season: str
    nutritional_value: int

    def grow(self) -> None:
        super().grow()
        self.nutritional_value += 1

    def age(self) -> None:
        super().age()
        self.nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season.capitalize()}")
        print(f" Nutritional_value: {self.nutritional_value}")

if __name__ == "__main__":

    print("=== Flower ===")
    rose = Flower("Rose", 15, 10, 1.5, "red")
    rose.show()
    print("[Asking rose to bloom]")
    rose.bloom()
    rose.show()

    print("=== Tree ===")
    oak = Tree("Oak", 200, 365, 1.1, 20)
    oak.show()
    print("[Asking oak to produce shade]")
    oak.shade()
    oak.show()

    print("=== Vegetable ===")
    tomato = Vegetable("Tomato", 5, 10, 1.1, "April", 0)
    tomato.show()
    i: int = 0
    print("[Making tomato age and grow for 20 days]")
    for i in range (0, 10):
        tomato.grow()
    for i in range (0, 10):
        tomato.age()
    tomato.show()

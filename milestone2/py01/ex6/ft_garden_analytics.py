#!/usr/bin/env python3

from typing import Self

class Plant:
    class PlantStats:
        _grow_call_count: int = 0
        _age_call_count: int = 0
        _show_call_count: int = 0

        def add_grow_call(self) -> None:
            self._grow_call_count += 1

        def add_age_call(self) -> None:
            self._age_call_count += 1

        def add_show_call(self) -> None:
            self._show_call_count += 1

        def display_stats(self) -> None:
            print(f"Stats: {self._grow_call_count} grow, {
                  self._age_call_count} age, {self._show_call_count} show")
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
        self.plant_stats = self.PlantStats()

    name: str
    _height: float
    _growth_factor: float
    _days_old: int
    _plant_stats: PlantStats

    @staticmethod
    def is_older_than_a_year(days: int) -> bool:
        return days > 365

    @classmethod
    def create_anonymous(cls, name: str = "Unknown plant", height: float = 0.0, days_old: int = 0,
                         growth_factor: float = 1) -> Self:
        return cls(name, height, days_old, growth_factor)

    def grow(self) -> None:
        self._height = round(self._height * self._growth_factor, 1)
        self.plant_stats.add_grow_call()

    def age(self) -> None:
        self._days_old += 1
        self.plant_stats.add_age_call()

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {
              self._height}cm, {self._days_old} days old")
        self.plant_stats.add_show_call()

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


class Seed(Flower):
    seeds: int = 0

    def bloom(self) -> None:
        super().bloom()
        self.seeds = 42

    def show(self) -> None:
        super().show()
        print(f" Seed{'s'[:self.seeds > 1]}: {self.seeds}")


class Tree(Plant):
    class PlantStats(Plant.PlantStats):
        _shade_call_count: int = 0

        def add_shade_call(self) -> None:
            self._shade_call_count += 1

        def display_stats(self) -> None:
            super().display_stats()
            print(f" {self._shade_call_count} shade{
                  's'[:self._shade_call_count > 1]}")

    trunk_diameter: float

    def __init__(self, name: str, height: float, days_old: int,
                 growth_factor: float, trunk_diameter: float):
        super().__init__(name, height, days_old, growth_factor)
        self.trunk_diameter = round(trunk_diameter, 1)
        self.plant_stats = self.PlantStats()


    def shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of {
              self._height}cm long and {self.trunk_diameter}cm wide.")
        self.plant_stats.add_shade_call()

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
    nutrional_value: int

    def grow(self) -> None:
        super().grow()
        self.nutrional_value += 1

    def age(self) -> None:
        super().age()
        self.nutrional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season.capitalize()}")
        print(f" Nutritional_value: {self.nutrional_value}")


def display_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant.plant_stats.display_stats()


if __name__ == "__main__":
    print("=== Check year-old ===")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_a_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_a_year(400)}")

    print("=== Flower ===")
    rose = Flower("Rose", 15, 10, 1.5, "red")
    rose.show()
    display_stats(rose)
    print("[Asking rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    display_stats(rose)

    print("=== Tree ===")
    oak = Tree("Oak", 200, 365, 1.1, 20)
    oak.show()
    display_stats(oak)
    print("[Asking oak to produce shade]")
    oak.shade()
    oak.show()
    display_stats(oak)

    print("=== Seed ===")
    sunflower = Seed("Sunflower", 80, 45, 1.2, "yellow")
    sunflower.show()
    display_stats(sunflower)
    print("[Asking sunflower to grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    display_stats(sunflower)

    print("=== Anonymous ===")
    anon = Plant.create_anonymous()
    display_stats(anon)

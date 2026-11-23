class Plant:
    def __init__(self, name: str, height: float, age: int,
                 growth_factor: float):
        if (age < 0 or height < 0):
            print("Might aswell create hollow purple no?")
            print("Yeah, get your defaults")
            self.name = "Depressed magenta"
            self.height = 1000
            self.age = 0
            self.growth_factor = 0.5
        else:
            self.name = name
            self.height = height
            self.age = age
            self.growth_factor = round(growth_factor, 1)

    name: str
    _height: float
    growth_factor: float
    _age: float

    @staticmethod
    def is_older_than_a_year(age: int):
        print(f"Is {age} days more than a year? -> {age > 365}")

    @classmethod
    def create_anonymous(cls, name: str = "Unknown plant", height: float = 0.0, age: int = 0,
                         growth_factor: float = 1):
        return cls(name, height, age, growth_factor)

    def grow(self):
        self.height = round(self.height * self.growth_factor, 1)
        self.PlantStats.add_grow_call()

    def age(self):
        ++self.age
        self.PlantStats.add_age_call()

    def show(self):
        print(f"{self.name.capitalize()}: {
              self.height}cm, {self.age} days old")
        self.PlantStats.add_show_call()

    def get_height(self):
        return (self.height)

    def set_height(self, new_height: float):
        if (new_height < 0):
            print("Invalid height inputted, aborting...You stupid skyscrapper")
            return
        self.height = new_height

    def get_age(self):
        return (self.age)

    def set_age(self, new_age: float):
        if (new_age < 0):
            print("Invalid age inputted, aborting...You old clapped brick")
            return
        self.age = new_age

    class PlantStats:
        _grow_call_count: int
        _age_call_count: int
        _show_call_count: int

        def add_grow_call(self):
            ++self.grow_call_count

        def add_age_call(self):
            ++self.age_call_count

        def add_show_call(self):
            ++self.show_call_count

        def display_stats(self):
            print(f"Stats: {self.grow_call_count} grow, {
                  self.age_call_count} age, {self.show_call_count} show")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: float,
                 growth_factor: float, color: str, is_blooming: bool = False):
        super().__init(name, height, age, growth_factor)
        self.color = color
        self.is_blooming = is_blooming

    color: str
    __is_blooming: bool

    def bloom(self):
        if (not self.is_blooming):
            self.is_blooming = True
            self.show()
        else:
            print(f"{self.name} already bloomed!")

    def show(self):
        super().show()
        print(f" Color: {self.color.lower()}")
        if (self.is_blooming):
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Seed(Flower):
    seeds: int

    def bloom(self):
        super().bloom()
        self.seeds = 42

    def show(self):
        super().show()
        print(f"Seed{'s'[:self.seeds > 1]}: {self.seeds}")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: float,
                 growth_factor: float, trunk_diameter: float):
        super().__init(name, height, age, growth_factor)
        self.trunk_diameter = round(trunk_diameter, 1)

    trunk_diameter: float

    def shade(self):
        print(f"Tree {super().name} now produces a shade of {
              self.height}cm long and {self.trunk_diameter}cm wide.")

    def show(self):
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    class PlantStats(Plant.PlantStats):
        _shade_call_count: int

        def add_shade_call(self):
            ++self._shade_call_count

        def display_stats(self):
            super().display_stats()
            print(f" {self._shade_call_count} shade{
                  's'[:self._shade_call_count > 1]}")


class Vegetables(Plant):
    def __init__(self, name: str, height: float, age: float,
                 growth_factor: float, harvest_season: str,
                 nutritional_value: int):
        super().__init(name, height, age, growth_factor)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    harvest_season: str
    nutrional_value: int

    def grow(self):
        super().grow()
        ++self.nutrional_value

    def age(self):
        super().age()
        ++self.nutrional_value

    def show(self):
        super().show()
        print(f" Harvest season: {self.harvest_season.capitalize()}")
        print(f" Nutritional_value: {self.nutrional_value}")


def display_stats(plant: Plant):
    plant.PlantStats.display_stats()


if __name__ == "__main__":
    print("=== Check year-old ===")
    Plant.is_older_than_a_year(30)
    Plant.is_older_than_a_year(400)

    print("=== Flower ===")
    rose = Flower("Rose", 15, 10, 1.5, "red")
    rose.show()
    display_stats(rose)
    rose.bloom()
    rose.show()
    display_stats(rose)

    print("=== Tree ===")
    oak = Tree("Oak", 200, 365, 1.1)
    oak.show()
    display_stats(oak)
    oak.shade()
    oak.show()
    display_stats(oak)

    print("=== Seed ===")
    sunflower = Seed("Sunflower", 80, 45, 1.2, "yellow")
    sunflower.show()
    display_stats(sunflower)
    sunflower.bloom()
    sunflower.show()
    display_stats(sunflower)

    print("=== Anonymous ===")
    anon = Plant.create_anonymous()
    anon.show()
    display_stats(anon)

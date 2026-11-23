class Plant:
    def __init__(self, name: str, height: float, age: float,
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

    def show(self):
        print(f"{self.name.capitalize()}: {
              self.height}cm, {self.age} days old")

    def age(self):
        ++self.age

    def grow(self):
        self.height = round(self.height * self.growth_factor, 1)

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

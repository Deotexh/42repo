class GardenError(Exception):

    def __init__(self, message: str = "Unknown garden error"):
        self.message = message
        super().__init__(self.message)


class PlantError(GardenError):

    def __init__(self, message: str = "Unknown plant error"):
        self.message = message
        super().__init__(self.message)


class WaterError(GardenError):

    def __init__(self, message: str = "Unknown water error"):
        self.message = message
        super().__init__(self.message)


def water_plant(plant_name: str) -> None:
    if (str != plant_name.capitalize()):
        raise PlantError(f"Invalid plant name to water: '{str}'")
    print(f"Watering {plant_name.capitalize()}: [OK]!")


def test_watering_system() -> None:
    print("=== Testing valid REAL plants... ==")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("Potato")
        water_plant("Welcometo42to")
    except PlantError as e:
        print(f"Caught a PlantError: {e}")
        print(".. ending tests, I'm leaving.")
    finally:
        print("Closing watering system")

    print("\n=== Testing invalid FAKE plants... ==")
    try:
        water_plant("Nachos")
        water_plant("gojo")
        water_plant("mybraincell")
    except PlantError as e:
        print(f"Caught a PlantError: {e}")
        print(".. ending tests, I'm leaving.")
    finally:
        print("Closing watering system")

    print("\nBla, bla, bla, cleaned up everyting...")
    print("See, I'm doing fine no need to stress bro oOOOOOHH", end='')
    print("WATCH OUT AN AIRSTRIKE")

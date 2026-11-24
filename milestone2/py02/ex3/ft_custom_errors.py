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


def test_water(liters: int) -> None:
    try:
        if (liters < 15):
            raise WaterError(f"{liters} is not enough water!")
        else:
            print("Plants are happy and hydrated!")
    except WaterError as e:
        print(f"Caught a WaterError: {e}")


def test_plant(plant: str, days_last_watered: int) -> None:
    try:
        if (days_last_watered < 2):
            raise PlantError(f"{plant} is going to wilt!")
        else:
            print(f"{plant} does not need to be watered!")
    except PlantError as e:
        print(f"Caught a PlantError: {e}")


def test_all(plant: str, days_last_watered: int, liters: int) -> None:
    try:
        test_plant(plant, days_last_watered)
    except GardenError as e:
        print(f"Caught a GardenError: {e}")
    try:
        test_water(liters)
    except GardenError as e:
        print(f"Caught a GardenError: {e}")

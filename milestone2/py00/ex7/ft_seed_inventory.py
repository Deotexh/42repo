def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if (unit == "packets"):
        print(seed_type.capitalize() + f" seed{'s'[:quantity > 1]}" +
              f": {quantity} packet{'s'[:quantity > 1]} available")
    elif (unit == "grams"):
        print(seed_type.capitalize() + f" seed{'s'[:quantity > 1]}" +
              f": {quantity} gram{'s'[:quantity > 1]} total")
    elif (unit == "area"):
        print(seed_type.capitalize() + f" seed{'s'[:quantity > 1]}" +
              f": covers {quantity} square meter{'s'[:quantity > 1]}")
    else:
        print("Unknown unit type")

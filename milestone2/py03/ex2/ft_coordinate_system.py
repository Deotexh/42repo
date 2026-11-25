import math


def get_player_pos() -> tuple:
    while (1):
        vector: str = input(
            "Enter new coordinates as floats in format 'x,y,z': ")
        i: int = 0
        try:
            if (vector.count(",") != 2):
                raise SyntaxError("Invalid syntax")
            split: list = vector.split()
            while (i < 3):
                float(split[i])
                i += 1
        except SyntaxError as e:
            print(f"{e}")
        except ValueError:
            print(f"Error on parameter {
                  vector[i]}: could not convert string to float")
        except Exception:
            pass
        else:
            return tuple(round(float(split[0]), 2),
                         round(float(split[1]), 2),
                         round(float(split[2]), 4))
            break


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    vec1: tuple = get_player_pos()
    print(f"Got a first tuple: {vec1}")
    print(f"It includes: X={vec1[0]}, Y={vec1[1]}, Z={vec1[2]}")
    print(f"Distance to center: {round(math.sqrt(
        vec1[0]**2 + vec1[1]**2 + vec1[2]**2), 4)}")

    print("\nGet a first set of coordinates")
    vec2: tuple = get_player_pos()
    print(f"Distance between the 2 sets of coordinates: {round(
        math.sqrt((vec2[0] - vec1[0])**2 +
                  (vec2[1] - vec1[1])**2 +
                  (vec2[2] - vec1[2])**2),
        4)}")

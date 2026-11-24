def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        int("abc")
    elif (operation_number == 1):
        42/0
    elif (operation_number == 2):
        open(-1)
    elif (operation_number == 3):
        42 + "On est à 42 un quoi là pffff"
    else:
        return


def test_error_types() -> None:

    i: int = 0
    while (i <= 4):
        try:
            garden_operations(i)
        except ValueError:
            print("Bad data has been provided")
        except ZeroDivisionError:
            print("You tried to divide by zero")
        except FileNotFoundError:
            print("You tried to open a file that does not exist")
        except TypeError:
            print("You tried to mix different types that cannot be mixed")
        else:
            print("Today, I called garden_operations", end='')
            print(f" with {i} as parameter. Everything was okay.")
    print("Dance with the steel ball run")
    print("'cause the program is still spinning!")

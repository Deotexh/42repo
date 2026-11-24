def input_temperature(temp_str: str) -> int:
    try:
        temp_int: int = int(temp_str);
    except ValueError:
        print("Caught input_temperature error: invalid input")
    if (temp_int >= 0 and temp_int <= 40):
        return temp_int
    else:
        raise()

def test_temperature() -> None:
    print("Input is '25'")
    tmp: int = input_temperature("25")
    print(f"Temperature is now {tmp}°CELSIUS and not FARAHNHEIGHT")
    print("CELSIUS!!!")

    print("Input is 'abc'")
    input_temperature("abc")

    print("Input is '100'")
    input_temperature("100")

    print("Input is '-50'")
    input_temperature("-50")

if __name__ == "__main__":
    test_temperature()

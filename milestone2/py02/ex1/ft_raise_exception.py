def input_temperature(temp_str: str) -> int:
    temp_int: int = int(temp_str)
    if (temp_int < 0):
        raise ValueError(temp_str + " is too cold for this plant" +
                         "you ain't that cold little bro")
    elif (temp_int > 40):
        raise ValueError(temp_str + " is TOO HOT!!! Do you want a garden " +
                         "or a damn hamam???")
    return int(temp_str)


def test_temperature() -> None:
    print("Input is '25'")
    tmp: int = input_temperature("25")
    print(f"Temperature is now {tmp}°CELSIUS and not FARAHNHEIGHT")
    print("CELSIUS!!!")

    print("Input is 'abc'")
    try:
        tmp = input_temperature("abc")
    except ValueError:
        print("Caught input_temperature error: 'abc' is made ", end='')
        print("of letters there's not even a single digit????")

    try:
        tmp = input_temperature("100")
    except Exception:
        pass

    try:
        tmp = input_temperature("-50")
    except Exception:
        pass

    print("Tenjō tenge, yuiga dokuson")
    print("(Throughout heaven and earth, I alone am the honored one)")


if __name__ == "__main__":
    test_temperature()

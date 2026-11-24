def input_temperature(temp_str: str) -> int:
    try:
        temp_int: int = int(temp_str);
    except ValueError:
        print("Caught input_temperature error: invalid input")
    return temp_int

def test_temperature() -> None:
    print("Input is '25'")
    tmp: int = input_temperature("25")
    print(f"Temperature is now {tmp}°CELSIUS and not FARAHNHEIGHT")
    print("CELSIUS!!!")

    print("Input is 'abc'")
    input_temperature("abc")

    print("I'M STILL STAANNDING")
    print("'fin j'crois")
    print("Nan ptn je crois que je me sens partir")
    print("Aled...")
    print("\n\n\n\n\nSike...")


if __name__ == "__main__":
    test_temperature()

def ft_count_harvest_iterative():
    days_left: int = int(input("Days until harvest: "))
    for i in range(1, days_left + 1):
        print(f"Day {i}")
    print("Harvest time!")


def ft_count_harvest_recursive():
    def ft_day_countdown(current_day: int, last_day: int):
        print(f"Day {current_day}")
        if (current_day != last_day):
            ft_day_countdown(current_day + 1, last_day)

    days_left: int = int(input("Days until harvest: "))
    ft_day_countdown(1, days_left)
    print("Harvest time!")

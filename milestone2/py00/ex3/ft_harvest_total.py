def ft_harvest_total():
    i: int = 1
    total: int = 0
    while (i <= 3):
        total += int(input(f"Day {i} harvest: "))
        print(f"Total harvest: {total}")

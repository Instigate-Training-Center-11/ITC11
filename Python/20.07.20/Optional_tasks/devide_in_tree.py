def my_foo(value):
    """ Ֆունկցիան տպում է 3֊ի բաժանվող բոլոր չկրկնվող նիշերով թվերի քանակը 

    Args:
        value (integer): Վերին սահմանը եռանիշ թվերի
    """

    count = 0
    start = 102
    while start <= value:
        a = int(start/100)
        b = int((start - (a * 100)) / 10)
        c = start - ((a * 100) + (b * 10))
        if start % 3 == 0 and a != b != c and a != c:
            count += 1
        start += 1
    print(count)

my_foo(int(input("Insert value: ")))

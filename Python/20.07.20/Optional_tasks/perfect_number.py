def perfect_number(value):
    """ Function perfect_number

    Args:
        value (integer): Value
    """

    result = 0
    count = 1
    while count < value:
        if value % count == 0:
            result += count
        count += 1
    if result == value:
        print("True")
    else:
        print("False")

perfect_number(int(input("Insert value: ")))
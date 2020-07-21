def input_value():
    """ Function checking value and return it

    Returns:
        (integer): Positive integer
    """

    while True:
        try:
            value = int(input("Insert value: "))
        except ValueError:
            print("Insert integer! Try again ")
            continue
        else:
            return value
            break

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
    return (result == value)

print(perfect_number(int(input_value())))
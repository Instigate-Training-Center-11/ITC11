def in_range(my_value):
    """ Check value

    Args:
        my_value (integer): Value 

    Returns:
        [bool]: in range(True) out of range(False)
    """

    return abs(my_value - 2000) <= 100 or abs(my_value - 1000) <= 100

def input_value():
    """ Function checking value and return it

    Returns:
        (integer): Positive integer
    """

    while True:
        try:
            value = int(input("Insert index: "))
            if value < 0:
                print("Insert positive integer! Try again ")
                continue
        except ValueError:
            print("Insert positive integer! Try again ")
            continue
        else:
            return value
            break

my_value = input_value()
print(in_range(my_value))
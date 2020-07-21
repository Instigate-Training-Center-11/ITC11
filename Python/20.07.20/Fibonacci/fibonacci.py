def number_by_index(index):
    """ Function for n-th Fibonacci number

    Args:
        index (integer): n-th index fibonacci number

    Returns:
        (integer): Value of n-th index
    """

    if index == 0 or index == 1:
        return 1
    else:
        return number_by_index(index - 1) + number_by_index(index - 2)

def input_index():
    """ Function checking value and return it

    Returns:
        (integer): Positive integer
    """

    while True:
        try:
            index = int(input("Insert index: "))
            if index < 0:
                print("Insert positive integer! Try again ")
                continue
        except ValueError:
            print("Insert positive integer! Try again ")
            continue
        else:
            return index
            break
def input_number(message):
    while True:
        try:
            user_input = int(input(message))
        except ValueError:
            print("Not an integer! Try again.")
            continue
        else:
            return user_input
            break

def compare_numbers(examples_number):
    """[the function gets integer number and returns true if the received
        number is between the (900 <= number <= 1100) and (1900 <= number <= 2100)]

    Args:
        examples_number ([integer]): [number]

    Returns:
        [bool]: [bool]
    """
    indicator = False
    indicator = 1100 >= examples_number >= 900 or 2100 >= examples_number >= 1900  and True or False
    return indicator


def main():
    examples_number = input_number("Input number ")
    if compare_numbers(examples_number):
        print("True")
    else:
        print("False")

    print(examples_number)

if __name__ == "__main__":
    main()
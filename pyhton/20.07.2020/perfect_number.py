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

def perfect(number):
    """[the function gets integer number and returns true if the number is perfect else returns false]

    Args:
        number ([integer]): [number]

    Returns:
        [bool]: [bool]
    """
    sum = 1
    i = number - 1
    while i > 1:
        if number % i == 0:
            sum = sum + i
        i = i - 1

    if sum == number:
        return True
    else:
        return False


def main():
    number = input_number("Input integer number ")
    if perfect(number):
        print("{} perfect number".format(number))
    else:
        print("{} no perfect number".format(number))

if __name__ == "__main__":
    main()



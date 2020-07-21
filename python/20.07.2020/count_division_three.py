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

def count_of_division(number):
    """[the function gets integer number and returns the count
        of numbers which is between 100 and the recited number,
        and divide on 3 and the digits of that's numbers are not repeat]

    Args:
        number ([integer]): [three digits]

    Returns:
        [integer]: [integer number]
    """
    counter = 0
    for i in range(102,number + 1,3):
        position_one = int(i / 100)
        position_two = int((i / 10) % 10)
        position_three = i % 10
        if position_one != position_two and position_two != position_three and position_one != position_three:
            counter += 1
    return counter

def main():
    examples_number = input_number("Input number > 99 and number < 999 -> ")
    print(count_of_division(examples_number))

if __name__ == "__main__":
    main()

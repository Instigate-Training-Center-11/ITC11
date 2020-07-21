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
    result_compare = False
    equal_number
    return result_compare


def main():
    examples_number = input_number("Input number ")
    compare_numbers(examples_number)
    print(examples_number)
main()
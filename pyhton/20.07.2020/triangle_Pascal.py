
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

def print_Pascal(n):
    """[the function gets integer number and print pascal triangles (rows == number)]

    Args:
        n ([integer]): [number]
    """
    for line in range(1, n + 1):
        current_member = 1
        for i in range(1, line + 1):
            print(current_member, end = " ")
            current_member = int(current_member * (line - i) / i)
        print("")

def main():

    n  = input_number("Input lines triangle Pascal ")
    print_Pascal(n)

if __name__ == "__main__":
    main()

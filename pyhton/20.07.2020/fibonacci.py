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


def fibonacci(n):
    """[the function gets integer number  and the n-th Fibonacci number is returned]

    Args:
        n ([integer]): [number]

    Returns:
        [integer]: [fibonacci number]
    """
    if n <= 0:
        print("Incorrect input")
    elif n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def main():
    fib_number = input_number("Input Fibonacci list number ")
    print("Fibonacci number ",fib_number," = ",fibonacci(fib_number))

if __name__ == "__main__":
    main()


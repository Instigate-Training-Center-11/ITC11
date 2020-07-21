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
    fib_first = 0
    fib_second = 1
    if n < 0:
        print("Incorrect input")
    elif n == 0:
        return fib_first
    elif n == 1:
        return fib_second
    else:
        for i in range(2,n):
            fib_membr = fib_first + fib_second
            fib_first = fib_second
            fib_second = fib_membr
        return fib_second

def main():
    print("count local variables in function input_number = ",input_number.__code__.co_nlocals)
    print("count local  variables in function fibonacci = ",fibonacci.__code__.co_nlocals)
    Fib_number = input_number("Input Fibonacci list number ")
    print("Fibonacci number ",Fib_number," = ",fibonacci(Fib_number))

if __name__ == "__main__":
    main()




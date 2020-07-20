# get Fibonacci element by number
def fibonacci(number):
    if number < 0:
        print("Not valid element index")
    elif number == 1 or number == 2:
        return 1
    else:
        return fibonacci(number - 1) + fibonacci(number - 2)

# Enter only integer number(not other charecter)
# Number must be greater then 0
def getNumber():
    number = 0
    while number < 1:
        print('Enter number to get Fibonacci number: ', end = "")
        try:
            number = int(input())
        except ValueError:
            print("It is not a number!")
            number = 0
        else:
            if number < 1:
                print("Number must be great then 0!")
                number = 0
            else:
                return number

# Main function
def main():
    number = getNumber()
    print("Fibonacci", number, "number is:", fibonacci(number))

if __name__ == "__main__":
    main()
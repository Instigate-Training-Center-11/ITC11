# function to get user's input
def userInput():
    index = 0
    while index < 1:
        print('Enter index of Fibonacci number You want to get: ', end = '')
        try:
            index = int(input())
        except ValueError:
            print('\nError!!! Your input is not a number!\n')
            index = 0
        else:
            if index < 1:
                print('\nError!!! Your input must be greater then 0!\n')
                index = 0
            else:
                return index

# function to get Fibonacci number by index
def fibonacci(index):
    if index == 1 or index == 2:
        return 1
    else:
        return fibonacci(index - 1) + fibonacci(index - 2)

def main():
    index = userInput()
    print("Fibonacci number by index ", index, "is:", fibonacci(index))

# to say to the interpreter to insert this at the top of the module when run as the main program
if __name__ == "__main__":
    main()
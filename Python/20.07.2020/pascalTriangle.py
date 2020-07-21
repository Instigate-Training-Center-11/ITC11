# function to get Pascal Triangle elements by row and by line
def pascalTriangle(column, row):
    number = 1
    if (row > (column - row)):
        row = (column - row)
    for i in range(row):
        number *= (column - i)
        number //= (i + 1)
    return number

# function to print Pascal Triangle
def printPascalTriangle(number):
    for column in range(number):
        space = (number - column)
        for i in range(0, space):
            print('  ', end = '')
        for row in range(column + 1):
            print(pascalTriangle(column, row), '  ', end = '')
        print('')

# function get user's input
def userInput():
    number = 0
    while number < 1:
        print('Enter size of Pascal Triangle: ', end = '')
        try:
            number = int(input())
        except ValueError:
            print('\nError!!! Your input is not a number!\n')
            number = 0
        else:
            if number < 1:
                print('\nError!!! Your input must be greater then 0!\n')
                number = 0
            else:
                return number

def main():
    number = userInput()
    print('\n====> PASCAL TRIANGLE <====')
    printPascalTriangle(number)
    print('\n====> COUNT OF LOCAL VARIABLES <====')
    print('Function \"pascalTriangle\" has ', pascalTriangle.__code__.co_nlocals, ' local variables')
    print('Function \"printPascalTriangle\" has ', printPascalTriangle.__code__.co_nlocals, ' local variables')
    print('Function \"userInput\" has ', userInput.__code__.co_nlocals, ' local variables')

# to say to the interpreter to insert this at the top of the module when run as the main program
if __name__ == "__main__":
    main()
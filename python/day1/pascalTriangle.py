# Print Pascal's triangle pretty
def pascalTriangle(number):
    for line in range(number):
        space = (number - line)
        for i in range(0, space):
            print("  ", end = "")
        for row in range(line + 1):
            print(getElement(line, row), "  ", end = "")
        print()

# Get Pascal's triangle element by row and line
def getElement(line, row):
    number = 1
    if (row > line - row):
        row = line - row
    for i in range(row) :
        number = number * (line - i)
        number = number // (i + 1)
    return number

# Enter only integer number(not other charecter)
# Number must be greater then 0
def getNumber():
    number = 0
    while number < 1:
        print('Enter number for Pascal Triangle size: ', end = "")
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

def main():
    number = getNumber()
    print("*** Pascal Triangle ***")
    pascalTriangle(number)

if __name__ == "__main__":
    main()
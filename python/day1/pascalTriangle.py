import getNumber

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

def main():
    print("Enter Pascal's Triangle Line count: ", end = "")
    number = getNumber.getNumber()
    print("*** Pascal Triangle ***")
    pascalTriangle(number)

if __name__ == "__main__":
    main()
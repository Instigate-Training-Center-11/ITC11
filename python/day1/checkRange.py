# Enter only integer number(not other charecter)
def getNumber():
    number = 0
    while number < 1:
        print('Enter number: ', end = "")
        try:
            number = int(input())
        except ValueError:
            print("It is not a number!")
            number = 0
        else:
            return number

def checkRange(number):
    return number in range(900, 1101) or number in range(1900, 2101)

# Main function to check range of number
def main():
    number = getNumber()
    array = [False, True]
    print(array[checkRange(number)])

if __name__ == "__main__":
    main()
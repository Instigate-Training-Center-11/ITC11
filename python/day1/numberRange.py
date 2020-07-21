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

# Main function to check range of number
def main():
    number = getNumber()
    condition = number <= 1100 and number >= 900
    condition = condition or (number <= 2100 and number >= 1900)
    print(True if condition else False)

if __name__ == "__main__":
    main()
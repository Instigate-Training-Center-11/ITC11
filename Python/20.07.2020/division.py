# function get user's input
def userInput():
    number = 0
    while number < 1:
        print('Enter a three-digit number: ', end = '')
        try:
            number = int(input())
        except ValueError:
            print('\nError!!! Your input is not a number!\n')
            number = 0
        else:
            if (number < 100 or number > 999):
                print('\nError!!! Your input is not a three-digit number!\n')
                number = 0
            else:
                return number

# function to check if the digits of number are equal
def checkNumber(number):
    c = number % 10
    b = ((number // 10) % 10)
    a = number // 100
    return(a != b and b != c and a != c)

# function to get the count of setisfactory numbers 
def getCount(number):
    count = 0
    for i in range(102, number + 1, 3):
        if checkNumber(i):
            count += 1
    return count

def main():
    number = userInput()
    print("Count of setisfactory numbers:", getCount(number))

if __name__ == "__main__":
    main()
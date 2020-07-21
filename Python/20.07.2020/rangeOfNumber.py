# function get user's input
def userInput():
    number = 0
    while number < 1:
        print('Enter the number: ', end = '')
        try:
            number = int(input())
        except ValueError:
            print('\nError!!! Your input is not a number!\n')
            number = 0
        else:
            return number

# function to check if inputted number is in the range (return TRUE) or not (return FALSE)
def checkRange(number):
    return ((abs(1000 - number) == 100) or (abs(2000 - number) == 100))

def main():
    number = userInput()
    print(checkRange(number))

# to say to the interpreter to insert this at the top of the module when run as the main program
if __name__ == "__main__":
    main()
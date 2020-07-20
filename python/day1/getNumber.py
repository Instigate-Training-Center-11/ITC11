# Enter only integer number(not other charecter)
# Number must be greater then 0
def getNumber():
    number = 0
    while number < 1:
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
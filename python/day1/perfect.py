import getNumber

def isPerfect(number):
    sum = 0
    for i in range(1, number - 1):
        if number % i == 0:
            sum += i

    return number == sum

# Check is number is perfect or not
def main():
    print('Enter number: ', end = "")
    number = getNumber.getNumber()
    if isPerfect(number):
        print(number, "is perfect number!")
    else:
        print(number, "is not perfect number!")

if __name__ == "__main__":
    main()
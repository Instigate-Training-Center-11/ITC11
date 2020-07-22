def inputUser():
    num = 0
    while num < 1:
        print('Enter the number: ', end = '')
        try:
            num = int(input())
        except ValueError:
            print('\nYour input is not a number!\n')
            num = 0
        else:
            return num
def range(num):
    return ((abs(1000 - num) <= 100) or (abs(2000 - num) <= 100))

def main():
    num = inputUser()
    print(range(num))

if __name__ == "__main__":
    main()

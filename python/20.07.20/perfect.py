"""The number is perfect or no"""
def perfect_number(num):
    sum = 0
    for x in range(1, num):
        if num % x == 0:
            sum += x
    return sum

def main():
    num = int(input("Enter any Number : "))
    if (num == perfect_number(num)):
        print(" %d is a Perfect Number" %num)
    else:
        print(" %d is not a Perfect Number" %num)

if __name__ == '__main__':
    main()

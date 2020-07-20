def perfect_number(num):
    sum = 0
    for i in range(1, num):
        if num % i == 0:
            sum += i

    if sum == num:
        print(num, "is Perfect Number")
    else:
        print(num, "is NOT Perfect Number")

def main():
    num = int(input("Enter the number: "))
    perfect_number(num)

if __name__ == '__main__':
    main()
def perfect_number(num):
    sum = 0
    for i in range(1, num):
        if num % i == 0:
            sum += i

    print()
    if sum == num:
        print(num, "is Perfect Number")
    else:
        print(num, "is NOT Perfect Number")

n = int(input("Enter the number: "))
print(perfect_number(n))
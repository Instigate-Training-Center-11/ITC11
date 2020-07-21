n = int(input("Enter the even positive number : "))

def is_perfect(n):
    total = 0
    for x in range(1, n):
        if n % x == 0:
            total += x
    return total == n

if is_perfect(n) == True:
    print(str(is_perfect(n)) + " : " + str(n) + " is a perfect number.")
else:
    print(str(is_perfect(n)) + " : " + str(n) + " is not a perfect number.")

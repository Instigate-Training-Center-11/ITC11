print("=======================Fibonacci numbers=======================")
n = int(input("Enter the positive number or 0 : "))

while n < 0:
    n = int(input("Enter the positive number or 0 : "))

def fibo(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

num = fibo(n)
print(num)

print("=======================Pascal triangle=======================")
n = int(input("Enter the number of rows : "))

def pascalLine(row, col):
    if col == 1:
        return 1
    if col == row:
        return 1
    left = pascalLine(row - 1, col - 1)
    right = pascalLine(row - 1, col)
    return left + right

for r in range(1, n + 1):
    for c in range(1, r + 1):
        print(pascalLine(r, c))
    print("")

print("=======================Count of local variables=======================")

def printingName():
    firstname = "Vardan"
    lastname = "Babayan"
    print (firstname + " " + lastname)

def addition():
    first = 3
    second = 4
    third = 5
    print(first + second + third)

n = printingName.__code__.co_nlocals
m = addition.__code__.co_nlocals
print ("The count of local variables of printName() is: " + str(n))
print ("The count of local variables of addition() is: " + str(m))

print("=======================Is in range? =======================")
n = int(input("Enter the number : "))

def isInRange(n):
    return ((abs(1000 - n) <= 100) or (abs(2000 - n) <= 100))

print(isInRange(n))

print("=======================Is perfect number? =======================")
n = int(input("Enter the number : "))

def isPerfect(n):
    total = 0
    for i in range(1, n):
        if n % i == 0:
            total += i
    return total == n

print (isPerfect(n))

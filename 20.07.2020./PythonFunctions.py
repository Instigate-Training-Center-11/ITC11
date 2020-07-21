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

def pascal_line(row, col):
    if col == 1:
        return 1
    if col == row:
        return 1
    left = pascal_line(row - 1, col - 1)
    right = pascal_line(row - 1, col)
    return left + right

for r in range(1, n + 1):
    for c in range(1, r + 1):
        print(pascal_line(r, c), end = " ")
    print('')

print("=======================Count of local variables=======================")

def printing_name():
    firstname = "Vardan"
    lastname = "Babayan"
    print(firstname + " " + lastname)

def addition():
    first = 3
    second = 4
    third = 5
    print(first + second + third)

n = printing_name.__code__.co_nlocals
m = addition.__code__.co_nlocals
print("The count of local variables of printName() is: " + str(n))
print("The count of local variables of addition() is: " + str(m))

print("=======================Is in range? =======================")

n = int(input("Enter the number : "))

def is_in_range(n):
    return ((abs(1000 - n) <= 100) or (abs(2000 - n) <= 100))

print(is_in_range(n))

print("=======================Is perfect number? =======================")

n = int(input("Enter the number : "))
while n < 0 or n % 2 > 0:
    n = int(input("Can not be a negative or an odd number : "))

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

print("=======================Three-digit number=======================")

n = int(input("Enter the three-digit number for range : "))
list_of_nums = []
for number in range(100, n):
    if number % 3 == 0:
        list_of_nums.append(number)
print(len(list_of_nums))

print("=======================End=======================")
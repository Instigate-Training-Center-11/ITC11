print("=======================Fibonacci numbers=======================")

n = int(input("Enter the positive number or 0 : "))

def fibo(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

num = fibo(n)
print(num)

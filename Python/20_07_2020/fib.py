def fib(n): 
    if n < 0: 
        print("Must be great or equal to 0") 
    elif n == 1 or n == 2: 
        return 1
    else: 
        return fib(n - 1) + fib(n - 2) 

n = input("Enter the number: ") 
print(fib(int(n)))
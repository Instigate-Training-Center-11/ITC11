def fib(num): 
    if num < 0: 
        print("Must be great or equal to 0") 
    elif num == 1 or num == 2: 
        return 1
    else: 
        return fib(num - 1) + fib(num - 2) 

def main():
    num = input("Enter the number: ") 
    print(fib(int(num)))

if __name__ == '__main__':
    main()
def fib(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)
        
def main():
    n = input("Print index of Fibonachi number: ")
    if int(n) < 0:
        print(n, "Index is not exist")
    else:
        print(n, "-th Fibonachi number is ", fib(int(n)))

if __name__ == '__main__':
    main()
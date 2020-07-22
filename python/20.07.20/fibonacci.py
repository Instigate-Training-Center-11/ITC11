"""get the nth Fibonacci number"""
def fibonacci(number):
    if number<0:
        print("Number must be equal or great to 0")
    elif number==1:
        return 0
    elif number==2:
        return 1
    else:
        return fibonacci(number-1)+fibonacci(number-2)

def main():
    number = int(input('Enter the number: '))
    print(fibonacci(number))

main()

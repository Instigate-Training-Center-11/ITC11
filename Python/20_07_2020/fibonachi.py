def fibonachi(n):
    if n==1:
        return 0
    elif n==2:
        return 1
    else:
        return fibonachi(n-1) + fibonachi(n-2)

def main():
    while True:
        number = input("Enter number ")
        print(fibonachi(number))

main()

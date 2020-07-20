def fibonachi(num):
    if num == 1 or num == 2:
        return 1
    else:
        return fibonachi(num - 1) + fibonachi(num - 2)

def main():
    number = int(input("enter your number ====== "))
    if number < 0:
        return
    print("fibonachi ( ",number," ) is a", fibonachi(number))


if __name__ == "__main__":
    main()

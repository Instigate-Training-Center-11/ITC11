def is_perfect(n):
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i

    if sum == n:
        return True
    else:
        return False
def main():
    n = int(input("Enter the number: "))
    if is_perfect(n):
        print("Number ", n, " is perfect")
    else:
        print("Number ", n, " is not perfect")
if __name__ == '__main__':
    main()
def check(number):
    count = 0
    for i in range(1 , number // 2 + 1):
        if number % i == 0:
            count += i
    if number == count:
        return True
    return False

def main():
    x = int(input("enter your number ==== "))
    print(check(x))

if __name__ == "__main__":
    main()

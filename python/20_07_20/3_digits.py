def check(a,b,c):
    if a != b and b != c and a != c :
        return True
    return False

def divide(n):
    a = n % 10
    b = (n // 10) % 10
    c = n // 100
    return check(a , b , c)

def main():
    x = int(input("input your  number ======= "))
    if  x < 100 or x>999:
            print("error")
            return
    i = 102
    count = 0
    while i <= x:
        if divide(i):
            count += 1
        i+=3
    print(count)


if __name__ == "__main__":
    main()
def three_digit(n):
    a = 0
    b = 0
    c = 0
    count = 0
    for i in range(100, n + 1):
        a = i // 100
        i = i - a * 100
        b = i // 10
        c = i % 10
        print (a," ",b, " ",c)
        if (a + b + c) % 3 == 0 and a != b and b != c and c != a:
            count += 1
    return count

def main():
    n = int(input("Enter the number: "))
    print(three_digit(n))

if __name__ == '__main__':
    main()
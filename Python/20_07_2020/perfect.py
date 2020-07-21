def perf(n):
    temp = 0
    for i in range(1, n):
        if n % i == 0:
            temp += i
    return temp == n


def main():
    i = int(input("num: "))
    print(perf(i))


main()


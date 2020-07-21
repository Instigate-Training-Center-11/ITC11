def m(n):
    if n < 103 or n > 999:
        return 0

    count = 0

    for i in range(102, n + 1, 3):
        one = i // 10
        two = (i // 10) % 10
        three = i % 10
        if one != two and one != three and two != three:
            count += 1
    return count


def main():
    num = int(input("Enter number: "))
    print(m(num))


main()

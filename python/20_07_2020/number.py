def tf():
    n = int(input("Input the number: "))
    print((n / 100 == 9) | (n / 100 == 11) | (n / 100 == 19) | (n / 100 == 21))

def main():
    tf()

if __name__ == '__main__':
    main()
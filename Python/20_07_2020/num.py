def main():
    num = int(input("Input the number: "))
    print((1000 - num == 100) | (num - 1000 == 100) 
        | (2000 - num == 100) | (num - 2000 == 100))

if __name__ == '__main__':
    main()
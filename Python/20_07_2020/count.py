def numbers_count(num):
    count = 0

    for i in range(100, num + 1):
        first = i // 100
        i = i - first * 100
        second = i // 10
        third = i % 10
            
        if (first + second + third) % 3 == 0 and first != second and first != third and second != third:
            count += 1
    
    print(count)

def main():
    n = int(input("Input the number: "))
    print("The count of 3-digit numbers, which is divided by 3 is: ")
    numbers_count(n)

if __name__ == '__main__':
    main()
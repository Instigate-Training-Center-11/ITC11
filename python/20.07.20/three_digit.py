def countOfThreeDigit(num):
    count = 0
    for i in range(102, num + 1, 3):
        begin = i // 100
        mid = (i // 10) % 10
        end = i % 10
        if(begin + mid + end) % 3 == 0 and begin != mid and begin != end and mid != end:
            count += 1
    print(count)

def main():
    num = int(input("Enter number: "))
    print("Count of setisfactory numbers:")
    countOfThreeDigit(num)

if __name__ == "__main__":
    main()

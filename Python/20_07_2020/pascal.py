def pascal(rows):
    arr = [1]
    for i in range(rows):
        print(arr)
        new_arr = []
        new_arr.append(1)
        for j in range(len(arr) - 1):
            new_arr.append(arr[j] + arr[j + 1])

        new_arr.append(1)
        arr = new_arr

def main():
    rows = int(input("Enter the number: "))
    pascal(rows)

if __name__ == '__main__':
    main()
def pascal_triangle(n):
    arr = []
    for i in range(n):
        arr.append([])
        arr[i].append(1)
        for j in range(1, i):
            arr[i].append(arr[i - 1][j - 1] + arr[i - 1][j])

        if(n != 0):
            arr[i].append(1)

    for i in range(n):
        print("   " * (n - i), end = " ")

        for j in range(0, i + 1):
            print('{0:6}'.format(arr[i][j]), end = " ")
        print()

def main():
    n = int(input("Enter number of rows: "))
    pascal_triangle(n)

if __name__ == '__main__':
    main()
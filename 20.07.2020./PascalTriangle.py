print("=======================Pascal triangle=======================")

n = int(input("Enter the number of rows : "))

def pascal_line(row, col):
    if col == 1:
        return 1
    if col == row:
        return 1
    left = pascal_line(row - 1, col - 1)
    right = pascal_line(row - 1, col)
    return left + right

for r in range(1, n + 1):
    for c in range(1, r + 1):
        print(pascal_line(r, c), end=" ")
    print('')
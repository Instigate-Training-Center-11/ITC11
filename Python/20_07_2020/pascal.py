def pascal(n):
    z = [[0 for row in range(0, n)]for col in range(0, n)]
    z[0][0] = 1

    for i in range(1, n):
        z[0][i] = 0

    for i in range(1, n):
        for j in range(0, n):
            z[i][j] = z[i - 1][j] + z[i - 1][j - 1]
    
    m = n / 2 + 2

    for i in range(0, n):
        for k in range(0, m):
            print("\t"),
        for j in range(0, n):
            if z[i][j] != 0:
                print(z[i][j]),
                print("\t\t"),
        print("\n\n")
        m -= 1

def main():
    while True:
        print("Enter the value of rows: ")
        x = int(input())
        pascal(x)

main()

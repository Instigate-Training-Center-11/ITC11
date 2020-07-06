#include <iostream>

void mul(int a[100][100], int b[100][100], int res[100][100], int size);
void print(int arr[100][100], int size);
void input(int arr[100][100], int size);

int main() {
    int a[100][100];
    int b[100][100];
    int res[100][100];
    int size = 2;

    std::cout << "mul's matrix multiplication\n";
    std::cout << "Enter the First matrix elements: \n";
    input(a, size);

    std::cout << "Enter the Second matrix elements: \n";
    input(b, size);

    std::cout << "\nFirst matrix is: \n";
    print(a, size);

    std::cout << "\nSecond matrix is: \n";
    print(b, size);

    mul(a, b, res, size);

    return 0;
}

void mul(int a[100][100], int b[100][100], int res[100][100], int size) {
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
    int p6;
    int p7;

    if (size > 2) {
        int mid = size / 2;
        mul(a, b, res, mid);
    } else {
        p1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
        p2 = (a[1][0] + a[1][1]) * b[0][0];
        p3 = a[0][0] * (b[0][1] - b[1][1]);
        p4 = a[1][1] * (b[1][0] - b[0][0]);
        p5 = (a[0][0] + a[0][1]) * b[1][1];
        p6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
        p7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
        res[0][0] = p1 + p4 - p5 + p7;
        res[0][1] = p3 + p5;
        res[1][0] = p2 + p4;
        res[1][1] = p1 - p2 + p3 + p6;

        std::cout << "\nThe result is: \n";
        print(res, size);
    }
}

void print(int arr[100][100], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            std::cout << arr[i][j] << " ";
        }

        std::cout << "\n";
    }
}

void input(int arr[100][100], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            std::cin >> arr[i][j];
        }
    }
}
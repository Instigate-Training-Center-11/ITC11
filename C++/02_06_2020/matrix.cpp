#include <iostream>

void sum(int row, int col, int matrixA[100][100], int matrixB[100][100]);
void subtract(int row, int col, int matrixA[100][100], int matrixB[100][100]);
void mulNumber(int row, int col, int num, int matrixA[100][100], int matrixB[100][100]);
void display(int row, int col, int matrix[100][100]);

int main() {
    int row;
    int col;
    int num;
    int matrixA[100][100];
    int matrixB[100][100];
    int mulNum[100][100];

    std::cout << "Enter number of rows: ";
    std::cin >> row;
    std::cout << "Enter number of cols: ";
    std::cin >> col;
    std::cout << "Enter the number for multiply: ";
    std::cin >> num;

    /* First matrix elements */
    std::cout << "\n" << "Enter elements of first Matrix: " << "\n";
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            std::cout << "Enter element for MatrixA: " << i + 1 << j + 1 << " : ";
            std::cin >> matrixA[i][j];
        }
    }

    /* Second matrix elements */
    std::cout << "\n" << "Enter elements of second Matrix: " << "\n";
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            std::cout << "Enter element for MatrixB: " << i + 1 << j + 1 << " : ";
            std::cin >> matrixB[i][j];
        }
    }

    sum(row, col, matrixA, matrixB);
    subtract(row, col, matrixA, matrixB);
    mulNumber(row, col,num, matrixA, matrixB);

    return 0;
}

/* Sum of matrix */
void sum(int row, int col, int matrixA[100][100], int matrixB[100][100]) {
    int sum[100][100];
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    /* Display the matrix and their sum */
    display(row, col, sum);
}

/* Subtract of matrix */
void subtract(int row, int col, int matrixA[100][100], int matrixB[100][100]) {
    int subtract[100][100];
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            subtract[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    /* Display the matrix and their subtract */
    display(row, col, subtract);
}

/* Multiply the Matrix with integer entered number. */
void mulNumber(int row, int col, int num, int matrixA[100][100], int matrixB[100][100]) {
    int mulNum[100][100];
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            mulNum[i][j] = matrixA[i][j] * num;
        }
    }
    /* Display the matrix and their dictance */
    display(row, col, mulNum);
}

void display(int row, int col, int matrix[100][100]) {
    /* Display the new matrix elements. */
    std::cout << "\n" << "Elements of the new matrix are: " << "\n";
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            std::cout << matrix[i][j] << " ";
            if(j == col - 1) {
                std::cout << "\n";
            }
        }
    }
}
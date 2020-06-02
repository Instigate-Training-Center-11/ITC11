#include <iostream>

int main() {
    int row;
    int col;
    int matrixA[100][100];
    int matrixB[100][100];
    int sum[100][100];
    int subtract[100][100];
    int i;
    int j;

    std::cout << "Enter number of rows: ";
    std::cin >> row;
    std::cout << "Enter number of columns: ";
    std::cin >> col;

    /* First matrix elements */
    std::cout << "\n" << "Enter elements of first matrix: " << "\n";
    for(i = 0; i < row; ++i) {
        for(j = 0; j < col; ++j) {
            std::cout << "Enter element for a matrix " << i + 1 << j + 1 << " : ";
            std::cin >> matrixA[i][j];
        }
    }

    /* Second matrix elements */
    std::cout << "\n" << "Enter elements of second matrix: " << "\n";
    for(i = 0; i < row; ++i) {
        for(j = 0; j < col; ++j) {
            std::cout << "Enter element for b matrix " << i + 1 << j + 1 << " : ";
            std::cin >> matrixB[i][j];
        }
    }

    /* Sum of matrix */
    for(i = 0; i < row; ++i) {
        for(j = 0; j < col; ++j) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    /* Display the matrix and their sum */
    std::cout << "\n" << "Sum of the matrix is: " << "\n";
    for(i = 0; i < row; ++i) {
        for(j = 0; j < col; ++j) {
            std::cout << sum[i][j] << " ";
            if(j == col - 1) {
                std::cout << "\n";
            }
        }
    }
    return 0;
}
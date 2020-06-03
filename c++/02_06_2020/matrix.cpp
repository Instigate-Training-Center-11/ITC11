#include <iostream>

void coutMatrix (int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int **cinMatrix (int row, int col) {
    std::cout << "Please enter elements of matrix" << std::endl;
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++) {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

int **sumMatrix(int **firstmatrix, int **secondmatrix, int row, int col) {
    int **temp = new int *[row];
    for (int i = 0; i < row; i++) {
        temp[i] = new int[col];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            temp[i][j] = firstmatrix[i][j] + secondmatrix[i][j];
        }
    }
    return temp;
}

int **subMatrix(int **firstmatrix, int **secondmatrix, int row, int col) {
    int **temp = new int *[row];
    for (int i = 0; i < row; i++) {
        temp[i] = new int[col];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            temp[i][j] = firstmatrix[i][j] - secondmatrix[i][j];
        }
    }
    return temp;
}

int **digitMatrix(int **matrix, int row, int col, int number) {
    int **temp = new int *[row];
    for (int i = 0; i < row; i++) {
        temp[i] = new int[col];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            temp[i][j] = number * matrix[i][j];
        }
    }
    return temp;
}


int main(){
    int row1 = 0;
    int col1 = 0;
    std::cout << "Please enter count of rows of first matrix" << std::endl;
    std::cin >> row1;
    std::cout << "Please enter count of colums of first matrix" << std::endl;
    std::cin >> col1; 
    int **matrix1 = cinMatrix(row1, col1);

    int row2 = 0;
    int col2 = 0;
    std::cout << "Please enter count of rows of second matrix" << std::endl;
    std::cin >> row2;
    std::cout << "Please enter count of colums of second matrix" << std::endl;
    std::cin >> col2; 
    int **matrix2 = cinMatrix(row2, col2);

    std::cout << std::endl;
    coutMatrix(matrix1, row1, col1);
    std::cout << std::endl;
    coutMatrix(matrix2, row2, col2);

    if (row1 == row2 && col1 == col2) {
        std::cout << "Matrix sum is: "<< std::endl;
        int **sumMat = sumMatrix(matrix1, matrix2, row1, col1);
        coutMatrix(sumMat, row1, col1);
    } else {
        std::cout << "These matrixs cannot be addition!!! " << std::endl;
    }
    
    if (row1 == row2 && col1 == col2) {
        std::cout << "Matrixs subtract is: "<< std::endl;
        int **diffMat = subMatrix(matrix1, matrix2, row1, col1);
        coutMatrix(diffMat, row1, col1);
    } else {
        std::cout << "These matrixs cannot be separated!!! "<< std::endl;
    }

    int digit = 0;
    std::cout << "Enter the number you want to multiplay by the matrix: "<< std::endl;
    std::cin >> digit;
    std::cout << "multiplied by the number of matrices:" << std::endl;
    int **digMat = digitMatrix(matrix1, row1, col1, digit);
    coutMatrix(digMat, row1, col1);

    return 0;   
}
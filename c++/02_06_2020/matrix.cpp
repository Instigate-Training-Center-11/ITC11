#include <iostream>

/* This function inputed an integer number */
int inputNumber() {
    int intNumber = 0;
    do {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter only number: ";
        std::cin >> intNumber;
    } while (std::cin.fail());

    return intNumber;
}

/* This function inputs elements of array */
void coutMatrix (int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* This function outputs elements of array */
int **cinMatrix (int row, int col) {
    std::cout << "Please enter elements of matrix" << std::endl;
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = inputNumber();
        }
    }

    return matrix;
}

/* This function calculates the sum of the tow arraies */
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

/* This function calculates the difference between the tow arraies */
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

/* This function calculates the product the array and number */
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

/* This function calculates the product between the tow arraies */
int** multMatrix(int **firstmatrix, int **secondmatrix, int r1, int c1, int r2, int c2) {
    int **temp = new int *[r1];
    for (int i = 0; i < r1; i++) {
        temp[i] = new int[c2];
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            temp[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                temp[i][j] += firstmatrix[i][k] * secondmatrix[k][j];
            }
        }
    }

    return temp;
}

void deleMatrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;
}

int main(){
    std::cout << "Please enter count of rows of first matrix" << std::endl;
    int row1 = inputNumber();
    std::cout << "Please enter count of colums of first matrix" << std::endl;
    int col1 = inputNumber();
    int **matrix1 = cinMatrix(row1, col1);

    std::cout << "Please enter count of rows of second matrix" << std::endl;
    int row2 = inputNumber();
    std::cout << "Please enter count of colums of second matrix" << std::endl;
    int col2 = inputNumber(); 
    int **matrix2 = cinMatrix(row2, col2);

    std::cout << std::endl;
    coutMatrix(matrix1, row1, col1);
    std::cout << std::endl;
    coutMatrix(matrix2, row2, col2);

    if (row1 == row2 && col1 == col2) {
        std::cout << "Matrix sum is: "<< std::endl;
        int **sumMat = sumMatrix(matrix1, matrix2, row1, col1);
        coutMatrix(sumMat, row1, col1);
        deleMatrix(sumMat, row1, col1);
    } else {
        std::cout << "These matrixs cannot be addition!!! " << std::endl;
    }

    if (row1 == row2 && col1 == col2) {
        std::cout << "Matrixs subtract is: "<< std::endl;
        int **diffMat = subMatrix(matrix1, matrix2, row1, col1);
        coutMatrix(diffMat, row1, col1);
        deleMatrix(diffMat, row1, col1);
    } else {
        std::cout << "These matrixs cannot be separated!!! "<< std::endl;
    }

    std::cout << "Enter the number you want to multiplay by the matrix: "<< std::endl;
    int digit  =inputNumber();
    std::cout << "multiplied by the number of matrix:" << std::endl;
    int **digMat = digitMatrix(matrix1, row1, col1, digit);
    coutMatrix(digMat, row1, col1);

    if (col1 != row2) {
        std::cout << "Can not miltiply these matrices!!!" << std::endl;
    } else {
        int **multMat = multMatrix(matrix1, matrix2, row1, col1, row2, col2);
        std::cout << "There will be a multiplication of tow matrixes:" << std::endl;
        coutMatrix(multMat, row1, col2);
        deleMatrix(multMat, row1, col2);
    }

    deleMatrix(matrix1, row1, col1);
    deleMatrix(matrix2, row2, col2);
    deleMatrix(digMat, row1, col1);

    return 0;
}
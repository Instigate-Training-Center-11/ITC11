#include <iostream>
#include <cstdlib>
#include <iomanip>

/* Checks input number is integer or not */
int type(int num) {
    std::cout << "Enter a positive number: ";
    std::cin >> num;
    while (std::cin.fail() || num < 1) {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter a positive number: ";
        std::cin >> num;
    }
    return num;
}

/*Display a matrix*/
void displayMatrix(int **arr, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*Create a matrix*/
int **createMatrix(int row, int column) {
    int **arr = new int *[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int [column];
        for (int j = 0; j < column; j++) {
            arr[i][j] = rand()%10;
        }
    }
    return arr;
}

/*Get sum of two matrixes*/
int **addMatrix(int **fMat, int **sMat, int row, int column) {
    int **sum = createMatrix(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            sum[i][j] = fMat[i][j] + sMat[i][j];
        }
    }
    return sum;
}

/*Get subtracting of two matrixes*/
int **subMatrix(int **fMat, int **sMat, int row, int column) {
    int **sub = createMatrix(row, column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; j++) {
            sub[i][j] = fMat[i][j] - sMat[i][j];
        }
    }
    return sub;
}

/*Multiply two matrix*/
int **mulMatrix(int **fMat, int **sMat, int row1, int row2, int column1, int column2) {
    int **mul = createMatrix(row1, column2);
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            mul[i][j] = 0;
        }
    }
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            for (int k = 0; k < column1; k++) {
                mul[i][j] += fMat[i][k] * sMat[k][j];
            }
        }
    }
    return mul;
}

/* Multiply matrix to number */
int **mulNum(int **arr, int row, int column, int num) {
    int **mulNumber = createMatrix(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            mulNumber[i][j] = num * arr[i][j];
        }
    }

    return mulNumber;
}

/*Delete matrix*/
void destroyMatrix(int **arr, int row, int column) {
    for (int i = 0; i < row; i++) {
        delete (arr[i]);
    }
    delete (arr);
}
int main() {
    srand(time(NULL));
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;
    int num = 0;
    /*Input first matrix*/
    std::cout << "-----FIRST MATRIX-----" << std::endl;
    std::cout << "Please input number of rows: ";
    std::cin >> row1;
    std::cout << "Please input number of columns: ";
    std::cin >> column1;
    int **matrix1 = createMatrix(row1, column1);
    displayMatrix(matrix1, row1, column1);
    /*Input second matrix*/
    std::cout << "-----SECOND MATRIX-----" << std::endl;
    std::cout << "Please input number of rows: ";
    std::cin >> row2;
    std::cout << "Please input number of columns: ";
    std::cin >> column2;
    int **matrix2 = createMatrix(row2, column2);
    displayMatrix(matrix2, row2, column2);
    /*Add of two matrix*/
    if (row1 == row2 || column1 == column2) {
        std::cout << "-----SUM MATRIX-----" << std::endl;
        int **sumMat = addMatrix(matrix1, matrix2, row1, column1);
        displayMatrix(sumMat, row1, column1);
        destroyMatrix(sumMat, row1, column1);
    }
    /*Substructing of two matrix*/
    if (row1 == row2 || column1 == column2) {
        int **subMat = subMatrix(matrix1, matrix2, row1, column1);
        std::cout << "-----SUB MATRIX-----" << std::endl;
        displayMatrix(subMat, row1, column1);
        destroyMatrix(subMat, row1, column1);
    }
    /* Multiply two matrixes */
    if (row2 == column1) {
        std::cout << "-----MUL MATRIX-----" << std::endl;
        int **mulMat = mulMatrix(matrix1, matrix2, row1, row2, column1, column2);
        displayMatrix(mulMat, row1, column2);
        destroyMatrix(mulMat, row1, column2);
    }
    /*Multiply matrix to number */
    int input = type(num);
    int **mulMat1 = mulNum(matrix1, row1, column1, input);
    std::cout << "----- Matrix1 * " << input << "-----" << std::endl;
    displayMatrix(mulMat1, row1, column1);
    destroyMatrix(mulMat1, row1, column1);
    int **mulMat2 = mulNum(matrix2, row2, column2, input);
    std::cout << "----- Matrix2 * " << input << "-----" << std::endl;
    displayMatrix(mulMat2, row2, column2);
    destroyMatrix(mulMat2, row2, column2);
    /*Delete matrix*/
    destroyMatrix(matrix1, row1, column1);
    destroyMatrix(matrix2, row2, column2);
    return 0;
}


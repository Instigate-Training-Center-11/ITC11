#include <iostream>
#include <cstdlib>
#include <iomanip>

/*Create a matrix*/
int **createMatrix(int row, int column) {
    int **arr = new int *[row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int [column];
        for(int j = 0; j < column; j++) {
            arr[i][j] = rand()%10;
        }
    }
    return arr;
}

/*Display a matrix*/
void displayMatrix(int **arr, int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/*Delete matrix*/
void destroyMatrix(int **arr, int row, int column) {
    for(int i = 0; i < row; i++) {
        delete (arr[i]);
    }
    delete (arr);
}

/*Get sum of two matrixes*/
int **addMatrix(int **fMat, int **sMat, int row1, int row2, int column1, int column2) {
    if (row1 != row2 || column1 != column2) {
        return NULL;
    }
    int **sum = createMatrix(row1, column1);
    for(int i = 0; i < row1; ++i) {
        for(int j = 0; j < column1; j++) {
            sum[i][j] = fMat[i][j] + sMat[i][j];
        }
    }
    return sum;
}


/*Get subtracting of two matrixes*/
int **subMatrix(int **fMat, int **sMat, int row1, int row2, int column1, int column2) {
    if (row1 != row2 || column1 != column2) {
        return NULL;
    }
    int **sub = createMatrix(row1, column1);
    for(int i = 0; i < row1; ++i) {
        for(int j = 0; j < column1; j++) {
            sub[i][j] = fMat[i][j] - sMat[i][j];
        }
    }
    return sub;
}

/*Multiply matrix to number*/
int **mulMatrix(int **fMat, int **sMat, int row1, int row2, int column1, int column2) {
    if (row1 != column2) {
        return NULL;
    }
    int **mul = createMatrix(row1, column2);
    for(int i = 0; i < row1; ++i) {
        for(int j = 0; j < column2; j++) {
            mul[i][j] = 0;
        }
    }
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j <column2; j++) {
            for (int k = 0; k < column1; ++k) {
                mul[i][j] += fMat[i][k] * sMat[k][j];
            }
        }
    }

    return mul;
}

int main() {
    srand(time(NULL));
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;
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
    int **sumMat = addMatrix(matrix1, matrix2, row1, row2, column1, column2);
    if (sumMat == NULL) {
        std::cout << "Sizes are inappropriate to sum" << std::endl;
    } else {
        std::cout << "-----SUM MATRIX-----" << std::endl;
        std::cout << "Matrixs summa is: "<< std::endl;
        displayMatrix(sumMat, row2, column2);
        destroyMatrix(sumMat, row1, column1);
    }
    /*Substructing of two matrix*/
    int **subMat = subMatrix(matrix1, matrix2, row1, row2, column1, column2);
    if (subMat == NULL) {
        std::cout << "Sizes are inappropriate to subtracting" << std::endl;
    } else {
        std::cout << "-----SUB MATRIX-----" << std::endl;
        std::cout << "Matrixs substruct is: "<< std::endl;
        displayMatrix(subMat, row2, column2);
        destroyMatrix(subMat, row1, column1);
    }
    /* Multiply 2 matrices */
    int **mulMat = mulMatrix(matrix1, matrix2, row1, row1, column2, column2);
    if (mulMat == NULL) {
        std::cout << "Sizes are inappropriate to multiply" << std::endl;
    } else {
        std::cout << "-----MUL MATRIX-----" << std::endl;
        std::cout << "Matrixs multiply is: "<< std::endl;
        displayMatrix(mulMat, row1, column2);
        destroyMatrix(mulMat, row1, column2);
    }
    /*Delete matrix*/
    destroyMatrix(matrix1, row1, column1);
    destroyMatrix(matrix2, row2, column2);
    return 0;
}


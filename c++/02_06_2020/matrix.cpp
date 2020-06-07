#include <iostream>
#include<cstdlib>
#include<ctime>

/* Multiply two matrices */
int** multiplyingMatrix(int** matrixOne, int** matrixTwo, int rowOne, int columOne, int rowTwo, int columTwo);
/* Multiplies matrices by number */
void multiplyByNumber(int** matrix, int row, int colum, int number);
/* Subtracting two matrices */
int** SubtractingMatrix(int** matrixOne, int** matrixTwo, int rowOne, int columOne, int rowTwo, int columTwo);
/* Adding two matrices */
int** AddingMatrix(int** matrixOne, int** matrixTwo, int rowOne, int columOne, int rowTwo, int columTwo);
/* Removes matrices */
void deleteMatrix(int** matrixOne, int row, int colum);
/* Create matrices */
int** createMatrix(int row, int colum);
/* Print matrices */
void display(int **matrix,int row,int colum);

int checkValue(void);

int main() {
    int** matrixOne = NULL;
    int** matrixTwo = NULL;
    int** resoltAdding = NULL;
    int** resoltSubtracting = NULL;
    int** resoltMultiplyingMatrix = NULL;
    int row1 = 0;
    int colum1 = 0;
    int row2 = 0;
    int colum2 = 0;

    std::cout << "Input row matrix One--> ";
    row1 = checkValue();
    std::cout << "Input colum matrix One--> ";
    colum1 = checkValue();
    matrixOne = createMatrix(row1,colum1);
    std::cout << "Input row matrix Two--> ";
    row2 = checkValue();
    std::cout << "Input colum matrix Two--> ";
    colum2 = checkValue();
    matrixTwo = createMatrix(row2,colum2);
    std::cout << "\t\tMatrix One\n\n";
    display(matrixOne,row1,colum1);
    std::cout << "\n\t\tMatrix Two\n\n";
    display(matrixTwo,row2,colum2);

    //resoltAdding = AddingMatrix(matrixOne,matrixTwo,row1,colum1,row2,colum2);
    //std::cout << "\t\tResoltAdding\n";
    //display(resoltAdding,row1,colum1);
    //resoltSubtracting = SubtractingMatrix(matrixOne,matrixTwo,row1,colum1,row2,colum2);
    //std::cout << "\t\tSubtractingMatrix\n";
    //display(resoltSubtracting,row1,row2);
    //multiplyByNumber(matrixTwo,row2,colum2,10);
    //std::cout << "\t\tMultiplyByNumber\n";
    //display(matrixTwo,row2,colum2);
    //resoltMultiplyingMatrix = multiplyingMatrix(matrixOne,matrixTwo,row1,colum1,row2,colum2);
    //display(resoltMultiplyingMatrix,row1,colum2);
    deleteMatrix(resoltMultiplyingMatrix,row1,colum2);
    deleteMatrix(resoltSubtracting,row1,colum1);
    deleteMatrix(resoltAdding,row1,row2);
    deleteMatrix(matrixOne, row1, colum1);
    deleteMatrix(matrixTwo, row2, colum2);

    return 0;
}

/* Implementation function multiplyingMatrix */
int** multiplyingMatrix(int** matrixOne, int** matrixTwo, int rowOne, int columOne, int rowTwo, int columTwo) {
    if (columOne != rowTwo) {
        std::cout << "incompatible matrices for  multiplyingMatrix\n";
        return nullptr;
    }
    int** newMatrix = createMatrix(rowOne,columTwo);
    multiplyByNumber(newMatrix,rowOne,columTwo,0);
    for (int i = 0; i < rowOne; ++i) {
        for (int j = 0; j < columTwo; ++j) {
            for (int k = 0; k < columOne; ++k) {
                newMatrix[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
        }
    }
    return newMatrix;
}

/* Implementation function multiplyByNumber */
void multiplyByNumber(int** matrix, int row, int colum, int number) {
    for (int i = 0; i < row; ++i) {
        for(int j = 0; j < colum; ++j) {
        matrix[i][j] = matrix[i][j] * number;
        }
    }
    return;
}

/* Implementation function SubtractingMatrix */
int** SubtractingMatrix(int** matrixOne, int** matrixTwo, int rowOne, int columOne, int rowTwo, int columTwo) {
    if (rowOne != rowTwo || columOne != columTwo) {
        std::cout << "incompatible matrices for adding\n";
        return nullptr;
    }
    int** newMatrix = createMatrix(rowOne,columOne);
    for (int i = 0; i < rowOne; ++i) {
        for(int j = 0; j < columOne; ++j) {
            newMatrix[i][j] = matrixOne[i][j] - matrixTwo[i][j];
        }
    }
    return newMatrix;
}

/* Implementation function AddingMatrix */
int** AddingMatrix(int** matrixOne, int** matrixTwo, int rowOne, int columOne, int rowTwo, int columTwo) {
    if (rowOne != rowTwo || columOne != columTwo) {
        std::cout << "incompatible matrices for adding\n";
        return nullptr;
    }
    int** newMatrix = createMatrix(rowOne,columOne);
    for (int i = 0; i < rowOne; ++i) {
        for(int j = 0; j < columOne; ++j) {
            newMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }
    return newMatrix;
}

/* Implementation function deleteMatrix */
void deleteMatrix(int** matrix, int row, int colum) {
    if (matrix == NULL) {
        std::cout << "Matrix already deleted\n";
        return;
    }
    for (int i = row - 1; i != 0; --i) {
        delete [] matrix[i];
    }
    delete [] matrix;
    matrix = NULL;
    std::cout << "Matrix deleted\n";
    return;
}

/* Implementation function createMatrix */
int** createMatrix(int row,int colum) {
    std::cout << "\tCreating matrix\n\n";
    srand(time(NULL));
    int **newMatrix = new int*[row];
    for (int i = 0; i < row; i++) {
        newMatrix[i] = new int[colum];
        for (int j = 0; j < colum; j++) {
            newMatrix[i][j] = rand() % 100 - 50;
        }
    }
    return newMatrix;
}

/* Implementation function display */
void display(int** matrix, int row, int colum) {
    if (matrix == NULL) {
        std::cout << "MatrixOne already deleted\n";
        return;
    }
    std::cout << "row = " << row << "\tcolum = " << colum<<"\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colum; ++j) {
            std::cout << matrix[i][j] << " \t";
        }
        std::cout << "\n";
    }
    return;
}

int checkValue(void) {
    int value = 0;
    std::cin >> value;
    while ((std::cin.fail() | value < 1)) {
    std::cout << "Input number > 0 ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> value;
    }
    return value;
}

#include <iostream>
#include <string>

/* Functions I used */
int getSize(std::string);
int** createMatrix(int, int);
void showMatrix(int**, int, int);
int** getSum(int**, int**, int, int, int, int);
int** getSubtracting(int**, int**, int, int, int, int);
int** getMul(int**, int**, int, int, int, int);
int** mulNumber(int**, int, int, int);
void deleteMatrix(int**, int, int);

int main() {
    /* Init fisrt matrix */
    std::cout << "*** First matrix ***" << std::endl;
    int n1 = getSize("Row: ");
    int m1 = getSize("Column: ");
    int** matrix1 = createMatrix(n1, m1);

    /* Init second matrix */
    std::cout << "*** Second matrix ***" << std::endl;
    int n2 = getSize("Row: ");
    int m2 = getSize("Column: ");
    int** matrix2 = createMatrix(n2, m2);

    /* Show matreces pretty */
    std::cout << "*** First matrix is ***" << std::endl;
    showMatrix(matrix1, n1, m1);
    std::cout << "*** Second matrix is ***" << std::endl;
    showMatrix(matrix2, n2, m2);

    /* Get sum of two matreces */
    int** sumMatrix = getSum(matrix1, matrix2, n1, m1, n2, m2);

    /* Check is sum has been successfully calculated */
    if (sumMatrix == NULL) {
        std::cout << "Warning: Sizes are inappropriate to sum!" << std::endl;
    } else {
        /* Show and clear new matrix */
        std::cout << "*** Matrix1 + Matrix2 ***" << std::endl;
        showMatrix(sumMatrix, n2, m2);
        deleteMatrix(sumMatrix, n1, m1);
    }

    /* Get subtracting of two matreces */
    int** subMatrix = getSubtracting(matrix1, matrix2, n1, m1, n2, m2);

    /* Check is successfully calculated */
    if (subMatrix == NULL) {
        std::cout << "Warning: Sizes are inappropriate to subtract!" << std::endl;
    } else {
        /* Show and clear new matrix */
        std::cout << "*** Matrix1 - Matrix2 ***" << std::endl;
        showMatrix(subMatrix, n2, m2);
        deleteMatrix(subMatrix, n1, m1);
    }

    /* Get number to multiply matreces */
    int number = getSize("Integer number: ");

    /* Multiply matreces to number, show and delete */
    int** mulMatrix1 = mulNumber(matrix1, n1, m1, number);
    std::cout << "*** Matrix1 * " << number << " ***" << std::endl;
    showMatrix(mulMatrix1, n1, m1);
    deleteMatrix(mulMatrix1, n1, m1);

    int** mulMatrix2 = mulNumber(matrix2, n2, m2, number);
    std::cout << "*** Matrix2 * " << number << " ***" << std::endl;
    showMatrix(mulMatrix2, n2, m2);
    deleteMatrix(mulMatrix2, n2, m2);

    /* Multiply 2 matreces */
    int** mulMatrices = getMul(matrix1, matrix2, n1, m1, n2, m2);

    /* Check is successfully calculated */
    if (mulMatrices == NULL) {
        std::cout << "Warning: Sizes are inappropriate to Multiply!" << std::endl;
    } else {
        std::cout << "*** Matrix1 * Matrix2 ***" << std::endl;
        showMatrix(mulMatrices, n1, m2);
        deleteMatrix(mulMatrices, n1, m2);
    }

    /* Delete 2 matreces */
    deleteMatrix(matrix1, n1, m1);
    deleteMatrix(matrix2, n2, m2);
    return 0;
}

/* Get integer number for row or column, great then 0 */
int getSize(std::string key) {
    int n = 0;
    std::cout << key;
    std::cin >> n;

    while (std::cin.fail() || n <= 0) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Warning: Enter only integer number and great then 0!!!" << std::endl;
        std::cout << key;
        std::cin >> n;
    }

    return n;
}

/* Create and initialize matrix with n row and m column */
int** createMatrix(int n, int m) {
    /* Create matrix */
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
    }

    /* Initialize matrix */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "[" << i + 1 << " " << j + 1 << "] : ";
            std::cin >> a[i][j];
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout << "Warning: Enter only integer number!!!" << std::endl;
                std::cout << "[" << i + 1 << " " << j + 1 << "]: ";
                std::cin >> a[i][j];
            }
        }
    }

    return a;
}

/* Print the matrix pretty */
void showMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* get sum of two matreces */
int** getSum(int** a, int** b, int n1, int m1, int n2, int m2) {
    if (n1 != n2 || m1 != m2) {
        return NULL;
    }

    int** c = new int* [n1];
    for (int i = 0; i < n1; ++i) {
        c[i] = new int[m1];
    }

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}

/* Get Subtracting of two matrices */
int** getSubtracting(int** a, int** b, int n1, int m1, int n2, int m2) {
    if (n1 != n2 || m1 != m2) {
        return NULL;
    }

    int** c = new int* [n1];
    for (int i = 0; i < n1; ++i) {
        c[i] = new int[m1];
    }

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    return c;
}

/* Multiply matrix to number */
int** mulNumber(int** a, int n, int m, int number) {
    int** b = new int*[n];
    for (int i = 0; i < n; ++i) {
        b[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = number * a[i][j];
        }
    }

    return b;
}

/* free matrix memory by name and size */
void deleteMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        delete [] a[i];
    }

    delete [] a;
}

/* Multiply two matreces */
int** getMul(int** a, int** b, int n1, int m1, int n2, int m2) {
    if (m1 != n2) {
        return NULL;
    }

    int** c = new int* [n1];
    for (int i = 0; i < n1; ++i) {
        c[i] = new int[m2];
    }

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            for (int k = 0; k < m1; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

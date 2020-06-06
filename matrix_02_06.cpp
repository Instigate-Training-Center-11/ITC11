#include<iostream>

int rows_matrix(int k) {
    int n = 0;
    std::cout << k << " matrix rows: ";
    std::cin >> n;
    return n;
}
int columns_matrix(int k) {
    int m = 0;
    std::cout << k << " matrix columns: ";
    std::cin >> m;
    return m;
}
int** create_matrix(int n, int m) {
    std::cout << "\nElements of matrix." << std::endl;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }
    return matrix;
}

void print_matrix_elements(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "Element " << i + 1 << j + 1 << ": ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}

int display_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << " " << matrix[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}

int** sum_matrices(int** matrix1,int n1, int m1, int** matrix2, int n2, int m2) {
    /*
      If the number of rows and columns of one matrix is equal 
      to the number of rows and columns of the other matrix,
      then those matrices can be added.
    */
    if (n1 == n2 && m1 == m2) {
        int** matrix3 = create_matrix(n1, m1); 
        //or int matrix3 = create_matrix(n2, m2), because they are equal․
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return matrix3;
    } else {
        std::cout << "It is not possible to add 2 such matrices" << std::endl;
        return 0;
    }
}

int** sub_matrices(int** matrix1,int n1, int m1, int** matrix2, int n2, int m2) {
    /*
      If the number of rows and columns of one matrix is equal 
      to the number of rows and columns of the other matrix,
      then those matrices can be subtracted each other. 
    */
    if (n1 == n2 && m1 == m2) {
        int** matrix3 = create_matrix(n1, m1); 
        //or int matrix3 = create_matrix(n2, m2), because they are equal․
        for (int i = 0; i < n1; ++i) {
             for (int j = 0; j < m1; ++j) {
                 matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
             }
        }
        return matrix3;
    } else {
        std::cout << "It is not possible to subtract 2 such matrices" << std::endl;
        return 0;
    }
}

int** mul_matrices(int** matrix1,int n1, int m1, int** matrix2, int n2, int m2) {
    /*
      If the number columns of one matrix is equal 
      to the number of rows of the other matrix,
      then those matrices can be multiply. 
    */
    if (m1 == n2) {
        int** matrix3 = create_matrix(n1, m2);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m2; ++j) {
                matrix3[i][j] = 0;
            }
        }

        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m2; ++j) {
                for (int k = 0; k < m1; ++k) {
                    matrix3[i][j] = matrix3[i][j] + (matrix1[i][k] * matrix2[k][j]);
                }
            }
        }
        return matrix3;
    } else {
        std::cout << "It is not possible to multiply 2 such matrices" << std::endl;
        return 0;
    }
}

//multiply the integer number by the matrix.
int** k_mul_matrix(int** matrix1,int n1, int m1) {
    /*
      To multiply the number 'k' by the first matrix,
      you need to multiply each element of the matrix by K.
    */
    int k = 0;
    //input 'k' number.
    std::cout << "Enter Integer number: ";
    std::cin >> k;
    int** matrix3 = create_matrix(n1, m1);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            matrix3[i][j] = k * matrix1[i][j];
        }
    }
    return matrix3;
}

int main() {
    //Announcement of variables, call the functions.
    std::cout << "Enter rows and columns matrix1." << std::endl;
    int n1 = rows_matrix(1);
    int m1 = columns_matrix(1);
    int** matrix1 = create_matrix(n1, m1);
    print_matrix_elements(matrix1, n1, m1);
    display_matrix(matrix1, n1, m1);
    std::cout << "\nEnter rows and columns matrix1." << std::endl;
    int n2 = rows_matrix(2);
    int m2 = columns_matrix(2);
    int** matrix2 = create_matrix(n2, m2);
    print_matrix_elements(matrix2, n2, m2);
    display_matrix(matrix2, n2, m2);

    //sum of two matrices.
    std::cout << "\nLet's calculate the sum of the first and second matrices.\n";
    int** matrix3 = sum_matrices(matrix1, n1, m1, matrix2, n2, m2);
    if (matrix3 != 0) {
        display_matrix(matrix3, n1, m1);
    }

    //subtract of the matrices.
    std::cout << "\nLet's calculate the difference between the first and second matrices.\n";
    int** matrix4 = sub_matrices(matrix1, n1, m1, matrix2, n2, m2);
    if (matrix4 != 0) {
        display_matrix(matrix4, n1, m1);
    }

    //multiply of two matrices.
    std::cout << "\nLet's calculate the product of the some first and second matrices.\n";
    int** matrix5 = mul_matrices(matrix1, n1, m1, matrix2, n2, m2);
    if (matrix5 != 0) {
        display_matrix(matrix5, n1, m2);
    }

    //multiply the integer number by first matrix.
    std::cout << "\nLet's calculate the product of the 'k' number and the first matrix.\n";
    int** matrix6 = k_mul_matrix(matrix1, n1, m1);
    display_matrix(matrix6, n1, m1);

    system("pause");
    return 0;
}

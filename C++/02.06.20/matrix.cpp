#include <iostream>

/* Print menu in terminal */
int menu();

/* Logic of menu */
void logic_menu(int**, int**, int, int, int, int);

/* Checking validation of entries */
int validation();

/* Create matrix(rows and columns) */
int** create_matrix(int, int);

/* Insert all variables in matrix */
void insert_matrix(int**, int, int);

/* Generate "random" values for matrix */
void random_matrix(int**, int, int);

/* Print matrix in console */
void print_matrix(int**, int, int);

/* Free memory and destroy matrix */
void delete_matrix(int**, int);

/* Calculate scalar multiplication */
void scalar_mult(int**, int, int);

/* Calculate multiply for two matrixes */
void mult_matrix(int**, int**, int, int, int);

/* Calculate sum of two matrixes */
void add_matrix(int**, int**, int, int);

/* Subtracting matrixes */
void subtract_matrix(int** matrix1, int ** matrix2, int, int);

int main() {
    std::cout << "\t\tInsert number of rows...\n ";
    int rows1 = validation();
    std::cout << std::endl;
    std::cout << "\t\tInsert number of columns...\n ";
    int cols1 = validation();
    std::cout << std::endl;

    std::cout << "\t\tInsert number of rows...\n ";
    int rows2 = validation();
    std::cout << std::endl;
    std::cout << "\t\tInsert number of columns...\n ";
    int cols2 = validation();
    std::cout << std::endl;

    int** matrix1 = create_matrix(rows1, cols1);
    int** matrix2 = create_matrix(rows2, cols2);

    insert_matrix(matrix1, rows1, cols1);
    insert_matrix(matrix2, rows2, cols2);

    // random_matrix(matrix1, rows1, cols1);
    // random_matrix(matrix2, rows2, cols2);

    logic_menu(matrix1, matrix2, rows1, cols1, rows2, cols2);

    delete_matrix(matrix1, rows1);
    delete_matrix(matrix2, rows2);

    return 0;
}

void scalar_mult(int** matrix, int rows, int cols) {
    std::cout << "\t\tInsert scalar value...\n ";
    int scalar_value = validation();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] *= scalar_value;
        }
    }
}

void delete_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete [] matrix[i];
    }

    delete[] matrix;
}

void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j == 0) {
                std::cout << "\t\t|\t" << matrix[i][j] << '\t';
            } else {
                std::cout << matrix[i][j] << '\t';
            }
        }
        std::cout << '|' << std::endl;
    }
    std::cout << std::endl;
}

void random_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 30;
        }
    }
}

void insert_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
            std::cout << std::endl;
        }
    }
}

int** create_matrix(int rows, int cols) {
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

int menu() {
    int submenu;
    std::cout << "\t\t************************MENU**********************\n\n";
    std::cout << "\t\tCheck (1): Scalar Matrix Multiplication.\n";
    std::cout << "\t\tCheck (2): Matrix Multiplication.\n";
    std::cout << "\t\tCheck (3): Matrix Adding.\n";
    std::cout << "\t\tCheck (4): Matrix Subtracting.\n";
    std::cout << "\t\tCheck (5)..Quit...\n\n";
    std::cout << "\t\t**************************************************\n\n";
    std::cout << "\t\tInsert 1 - 5\n\n";

    return validation();
}

void logic_menu(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    bool exit = true;
    while (exit) {
        int submenu = menu();
        switch (submenu) {
        case(1):
            system("clear");
            std::cout << "\t\tScalar Matrix Multiplication..." << std::endl << std::endl;
            scalar_mult(matrix1, rows1, cols1);
            print_matrix(matrix1, rows1, cols1);
            scalar_mult(matrix2, rows2, cols2);
            print_matrix(matrix2, rows2, cols2);
            break;
        case(2):
            system("clear");
            std::cout << "\t\tMatrix Multiplication..." << std::endl << std::endl;
            print_matrix(matrix1, rows1, cols1);
            print_matrix(matrix2, rows2, cols2);
            std::cout << std::endl << std::endl << std::endl;
            if (cols1 == rows2) {
                mult_matrix(matrix1, matrix2, rows1, cols1, cols2);
            } else {
                std::cout << "\t\tMatrix 1 and 2 below cannot be multiplied together(rows1 != cols2)" << std::endl;
            }
            break;
        case(3):
            system("clear");
            std::cout << "\t\tMatrix Adding..." << std::endl << std::endl;
            print_matrix(matrix1, rows1, cols1);
            print_matrix(matrix2, rows2, cols2);
            std::cout << std::endl << std::endl << std::endl;
            if (rows1 == rows2 && cols1 == cols2) {
                add_matrix(matrix1, matrix2, rows1, cols1);
                print_matrix(matrix1, rows1, cols1);
            } else {
                std::cout << "\t\tMatrix 1 and 2 below cannot be added together(rows != rows)" << std::endl;
            }
            break;
        case(4):
            system("clear");
            std::cout << "\t\tMatrix Subtracting..." << std::endl << std::endl;
            print_matrix(matrix1, rows1, cols1);
            print_matrix(matrix2, rows2, cols2);
            std::cout << std::endl << std::endl << std::endl;
            if (rows1 == rows2 && cols1 == cols2) {
                subtract_matrix(matrix1, matrix2, rows1, cols1);
                print_matrix(matrix1, rows1, cols1);
            } else {
                std::cout << "\t\tMatrix 1 and 2 below cannot be subtracted together(rows != rows)" << std::endl;
            }
            break;
        case(5):
            system("clear");
            std::cout << "Bye...Good luck!" << std::endl;
            exit = false;
            break;
            default:
            std::cout << "\t\tplease select valid number of submenu..\n";
            break;
        }
    }
}

int validation() {
    std::cout << "\t\tPlease insert true value: ";
    int value = 0;
    std::cin >> value;
    std::cout << std::endl;
    while ((std::cin.fail() | value < 1)) {
            std::cout << "\t\tPlease insert only positive number: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> value;
    }
    return value;
}

void mult_matrix(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
    int** sum = create_matrix(rows1, cols2);
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            sum[i][j] = 0;
            int count = 0;
            while (count < cols1) {
                sum[i][j] += matrix1[i][count] * matrix2[count][j];
                ++count;
            }
        }
    }
    print_matrix(sum, rows1, cols2);
    delete_matrix(sum, rows1);
}

void add_matrix(int** matrix1, int ** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

void subtract_matrix(int** matrix1, int ** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix1[i][j] -= matrix2[i][j];
        }
    }
}
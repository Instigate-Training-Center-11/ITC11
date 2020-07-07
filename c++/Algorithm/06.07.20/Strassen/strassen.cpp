#include <iostream>

/*Checks input number is integer or symbol*/
int getType() {
    int number = 0;
    std::cin >> number;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cerr << "ERROR: Faulty input! ";
        std::cout << "Enter integer number: ";
        std::cin >> number;
    }

    return number;
}

/*show matrix*/
void display(int **mat, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*create matrix*/
int **create(int row, int col) {
    std::cout << "Enter matrix elements" << std::endl;
    int **mat = new int *[row];
    for (int i = 0; i < row; ++i) {
        mat[i] = new int[col];
        for (int j = 0; j < col; ++j) {
            mat[i][j] = getType();
        }
    }
    return mat;
}


int **initZero (int row, int col) {
    int **mat = new int *[row];
    for(int i = 0; i < row; i++) {
        mat[i] = new int[col];
        for(int j = 0; j < col; j++) {
            mat[i][j] = 0;
        }
    }

    return mat;
}

void add(int **A, int **B, int **Result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(int **A, int **B, int **Result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Result[i][j] = A[i][j] - B[i][j];
        }
    }
}



int Strassen(int size, int **A, int **B, int **C) {

    int HalfSize = size / 2;
    int newSize = size / 2;
    if ( size == 1 ) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int** A11 = new int *[newSize];
        int** A12 = new int *[newSize];
        int** A21 = new int *[newSize];
        int** A22 = new int *[newSize];

        int** B11 = new int *[newSize];
        int** B12 = new int *[newSize];
        int** B21 = new int *[newSize];
        int** B22 = new int *[newSize];

        int** C11 = new int *[newSize];
        int** C12 = new int *[newSize];
        int** C21 = new int *[newSize];
        int** C22 = new int *[newSize];

        int** M1 = new int *[newSize];
        int** M2 = new int *[newSize];
        int** M3 = new int *[newSize];
        int** M4 = new int *[newSize];
        int** M5 = new int *[newSize];
        int** M6 = new int *[newSize];
        int** M7 = new int *[newSize];

        int** AResult = new int *[newSize];
        int** BResult = new int *[newSize];

        int length = newSize;

        for ( int i = 0; i < newSize; i++) {
            A11[i] = new int[length];
            A12[i] = new int[length];
            A21[i] = new int[length];
            A22[i] = new int[length];

            B11[i] = new int[length];
            B12[i] = new int[length];
            B21[i] = new int[length];
            B22[i] = new int[length];

            C11[i] = new int[length];
            C12[i] = new int[length];
            C21[i] = new int[length];
            C22[i] = new int[length];

            M1[i] = new int[length];
            M2[i] = new int[length];
            M3[i] = new int[length];
            M4[i] = new int[length];
            M5[i] = new int[length];
            M6[i] = new int[length];
            M7[i] = new int[length];

            AResult[i] = new int[length];
            BResult[i] = new int[length];
        }

        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size / 2; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + size / 2];
                A21[i][j] = A[i + size / 2][j];
                A22[i][j] = A[i + size / 2][j + size / 2];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + size / 2];
                B21[i][j] = B[i + size / 2][j];
                B22[i][j] = B[i + size / 2][j + size / 2];

            }
        }

        //M1[][]
        add(A11, A22, AResult, HalfSize);              //(A11+A22)
        add(B11, B22, BResult, HalfSize);              //(B11+B22)
        Strassen(HalfSize, AResult, BResult, M1);      //multiply(AResult,BResult,HalfSize,M1)

        //M2[][]
        add(A21, A22, AResult, HalfSize);              //M2=(A21+A22)B11
        Strassen(HalfSize, AResult, B11, M2);          //multiply(AResult,B11,M2);

        //M3[][]
        sub(B12, B22, BResult, HalfSize);              //M3=A11(B12-B22)
        Strassen(HalfSize, A11, BResult, M3);          //multiply(A11,BResult,M3);

        //M3[][]
        sub(B12, B22, BResult, HalfSize);              //M3=A11(B12-B22)
        Strassen(HalfSize, A11, BResult, M3);          //multiply(A11,BResult,M3);

        //M4[][]
        sub(B21, B11, BResult, HalfSize);               //M4=A22(B21-B11)
        Strassen(HalfSize, A22, BResult, M4);           //multiply(A22,BResult,M4);

        //M5[][]
        add(A11, A12, AResult, HalfSize);               //M5=(A11+A12)B22
        Strassen(HalfSize, AResult, B22, M5);           //multiply(AResult,B22,M5)

        //M6[][]
        sub(A21, A11, AResult, HalfSize);                //M6=(A21-A11)(B11+B12)
        add(B11, B12, BResult, HalfSize);
        Strassen(HalfSize, AResult, BResult, M6);        //multiply(AResult,BResult,M6);

        //M7[][]
        sub(A12, A22, AResult, HalfSize);                //M7=(A12-A22)(B21+B22)
        add(B21, B22, BResult, HalfSize);
        Strassen(HalfSize, AResult, BResult, M6);         //multiply(AResult,BResult,M7);

        //C11 = M1 + M4 - M5 + M7;
        add(M1, M4, AResult, HalfSize);
        sub(M7, M5, BResult, HalfSize);
        add(AResult, BResult, C11, HalfSize);

        //C12 = M3 + M5;
        add(M3, M5, C12, HalfSize);

        //C21 = M2 + M4;
        add(M2, M4, C21, HalfSize);

        //C22 = M1 + M3 - M2 + M6;
        add(M1, M3, AResult, HalfSize);
        sub(M6, M2, BResult, HalfSize);
        add(AResult, BResult, C22, HalfSize);

        for (int i = 0; i < size / 2 ; i++) {
            for (int j = 0 ; j < size / 2 ; j++) {
                C[i][j] = C11[i][j];
                C[i][j + size / 2] = C12[i][j];
                C[i + size / 2][j] = C21[i][j];
                C[i + size / 2][j + size / 2] = C22[i][j];
            }
        }

        for (int i = 0; i < length; i++) {
            delete[] A11[i];delete[] A12[i];delete[] A21[i];
            delete[] A22[i];

            delete[] B11[i];delete[] B12[i];delete[] B21[i];
            delete[] B22[i];
            delete[] C11[i];delete[] C12[i];delete[] C21[i];
            delete[] C22[i];
            delete[] M1[i];delete[] M2[i];delete[] M3[i];delete[] M4[i];
            delete[] M5[i];delete[] M6[i];delete[] M7[i];
            delete[] AResult[i];delete[] BResult[i] ;
        }
    }

    return 0;
}

int main() {
    std::cout << "Enter size: " << std::endl;
    int size = getType();
    int **mat1 = create(size, size);
    std::cout << "First matrix: " << std::endl;
    display(mat1, size, size);
    int **mat2 = create(size, size);
    std::cout << "Second matrix: " << std::endl;
    display(mat2, size, size);
    int **mat3 = initZero(size, size);
    Strassen(size, mat1, mat2, mat3);
    std::cout << "Multiply matrix: " << std::endl;
    display(mat3, size, size);

    return 0;
}


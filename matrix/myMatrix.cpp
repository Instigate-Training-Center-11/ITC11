#include <iostream>

#define SIZE 5

void enter(int **arr) {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            arr[i][j] = rand()%10 + 1;
        }
    }
}

void print(int **arr) {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            std::cout << "mat[" << i << "][" << j << "]: " << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void malloc(int **arr) {
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = new int [SIZE];
    }
}

void MatrixMultiply(int** arr1, int** arr2, int **arr3) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            arr3[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void strassenCalc(int ** arr1, int** arr2, int ** arr3) {
    int p1, p2, p3, p4, p5, p6, p7;
    p1 = (arr1[0][0] + arr1[1][1]) * (arr2[0][0] + arr2[1][1]);
    p2 = (arr1[1][0] + arr1[1][1]) * arr2[0][0];
    p3 = arr1[0][0] * (arr2[0][1] - arr2[1][1]);
    p4 = arr1[1][1] * (arr2[1][0] - arr2[0][0]);
    p5 = (arr1[0][0] + arr1[0][1]) * arr2[1][1];
    p6 = (arr1[1][0] - arr1[0][0]) * (arr2[0][0] + arr2[0][1]);
    p7 = (arr1[0][1] - arr1[1][1]) * (arr2[1][0] + arr2[1][1]);
    arr3[0][0] = p1 + p4 + -p5 + p7;
    arr3[0][1] = p3 + p5;
    arr3[1][0] = p2 + p4;
    arr3[1][1] = p1 + p3 - p2 + p6;
}

void strassen(int **arr1, int **arr2, int **arr3, int s) {
    if (SIZE == 1) {
        MatrixMultiply(arr1, arr2, arr3);
    } else if(SIZE == 2){
        strassenCalc(arr1, arr2, arr3);
    } else {
        std::cout << "Can not calculate matrix , please change matrix size 1 or 2" << std::endl;
        return;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    //allocate memory for first  matrix
    int** mat1 = new int*[SIZE];
    malloc(mat1);

    //allocate memory for second matrix
    int** mat2 = new int*[SIZE];
    malloc(mat2);

    //allocate memory for matrix of result
    int** mat3 = new int*[SIZE];
    malloc(mat3);

    //enter data for matrix
    enter(mat1);
    enter(mat2);

    std::cout << "First Matrix" << std::endl;
    print(mat1);

    std::cout << std::endl << "Second Matrix" << std::endl;
    print(mat2);

    std::cout << std::endl << "Result Matrix" << std::endl;
    strassen(mat1, mat2, mat3, SIZE);

    if(SIZE < 3 && SIZE > 0) {
        //print matrix
        print(mat3);
    }

    return 0;
}
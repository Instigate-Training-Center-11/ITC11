#include <iostream>

void matrixSum(int **, int **, int **, int);
void matrixSub(int **, int **, int **, int);
void matrixMul(int **, int **, int **, int);
void coutMatrix(int **, int, int);
int **cinMatrix(int, int);
int **initZero (int, int);
int inputNumber();

int main() {
    int size = inputNumber();
    int **a = cinMatrix(size, size);
    coutMatrix(a, size, size);
    int **b = cinMatrix(size, size);
    coutMatrix(b, size, size);
    int **c  = initZero(size, size);
    matrix_mul(a,b,c,size);
    coutMatrix (c,size,size);

    return 0;
}

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

    int **initZero (int row, int col) {

    int **matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
    }


void matrix_sum(int **a, int **b, int **c, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void matrix_sub(int **a, int **b, int **c, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

void matrix_mul(int **a, int **b, int **c, int n) {
	if (1 == n) {
		c[0][0] = a[0][0] * b[0][0];
	} else {
		int **a11 = new int *[n / 2];
		int **a12 = new int *[n / 2];
		int **a21 = new int *[n / 2];
		int **a22 = new int *[n / 2];
		int **b11 = new int *[n / 2];
		int **b12 = new int *[n / 2];
		int **b21 = new int *[n / 2];
		int **b22 = new int *[n / 2];
		int **c11 = new int *[n / 2];
		int **c12 = new int *[n / 2];
		int **c21 = new int *[n / 2];
		int **c22 = new int *[n / 2];
		int **m1 = new int* [n / 2];
		int **m2 = new int* [n / 2];
		int **m3 = new int* [n / 2];
		int **m4 = new int* [n / 2];
		int **m5 = new int* [n / 2];
		int **m6 = new int* [n / 2];
		int **m7 = new int* [n / 2];
		int **temp1 = new int *[n / 2];
		int **temp2 = new int *[n / 2];


		for (int i = 0; i < (n / 2); i++){
			delete[] a11[i];
			delete[] a12[i];
			delete[] a21[i];
			delete[] a22[i];
			delete[] b11[i];
			delete[] b12[i];
			delete[] b21[i];
			delete[] b22[i];
			delete[] c11[i];
			delete[] c12[i];
			delete[] c21[i];
			delete[] c22[i];
			delete[] temp1[i];
			delete[] temp2[i];
		}
	}
}
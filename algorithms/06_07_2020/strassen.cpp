#include <iostream>

void matrixSum(int **, int **, int **, int);
void matrixSub(int **, int **, int **, int);
void matrixMul(int **, int **, int **, int);
void coutMatrix(int **, int, int);
int **cinMatrix(int, int);
int **initZero (int, int);
int inputNumber();

int main() {
	std::cout << "Enter size of matric: " << std::endl;
	int size = inputNumber();
	int **a = cinMatrix(size, size);
	std::cout << "This is first matric: " << std::endl;
	coutMatrix(a, size, size);
	int **b = cinMatrix(size, size);
	std::cout << "This is second matric: " << std::endl;
	coutMatrix(b, size, size);
	int **c  = initZero(size, size);
	matrixMul(a,b,c,size);
	std::cout << "This is multiply of matrices: " << std::endl;
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
	} while(std::cin.fail());

	return intNumber;
}

/* This function fills the matrices elements with zeros */
void coutMatrix(int **matrix, int row, int col) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

/* This function outputed elements of matrices */
int **cinMatrix (int row, int col) {
	std::cout << "Please enter elements of matrix" << std::endl;
	int **matrix = new int *[row];
	for(int i = 0; i < row; i++) {
		matrix[i] = new int[col];
		for(int j = 0; j < col; j++) {
			matrix[i][j] = inputNumber();
		}
	}

	return matrix;
}

/* This function outputs elements of matrices */
int **initZero (int row, int col) {
	int **matrix = new int *[row];
	for(int i = 0; i < row; i++) {
		matrix[i] = new int[col];
		for(int j = 0; j < col; j++) {
			matrix[i][j] = 0;
		}
	}

	return matrix;
}

/* This function considers the result of adding 2 matrices. */
void matrixSum(int **a, int **b, int **c, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

/* This function considers the result of subtract 2 matrices */
void matrixSub(int **a, int **b, int **c, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

/* This function considers the result of multiply 2 matrices with recursion */
void matrixMul(int **a, int **b, int **c, int n) {
	if(1 == n) {
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

		for(int i = 0; i < n / 2; i++) {
			a11[i] = new int[n / 2];
			a12[i] = new int[n / 2];
			a21[i] = new int[n / 2];
			a22[i] = new int[n / 2];
			b11[i] = new int[n / 2];
			b12[i] = new int[n / 2];
			b21[i] = new int[n / 2];
			b22[i] = new int[n / 2];
			c11[i] = new int[n / 2];
			c12[i] = new int[n / 2];
			c21[i] = new int[n / 2];
			c22[i] = new int[n / 2];
			m1[i] = new int[n / 2];
			m2[i] = new int[n / 2];
			m3[i] = new int[n / 2];
			m4[i] = new int[n / 2];
			m5[i] = new int[n / 2];
			m6[i] = new int[n / 2];
			m7[i] = new int[n / 2];
			temp1[i] = new int[n / 2];
			temp2[i] = new int[n / 2];
		}

		for(int i = 0; i < n / 2; i++) {
			for(int j = 0; j < n / 2; j++) {
				a11[i][j] = a[i][j];
				a12[i][j] = a[i][j + n / 2];
				a21[i][j] = a[i + n / 2][j];
				a22[i][j] = a[i + n / 2][j + n / 2];
				b11[i][j] = b[i][j];
				b12[i][j] = b[i][j + n / 2];
				b21[i][j] = b[i + n / 2][j];
				b22[i][j] = b[i + n / 2][j + n / 2];
			}
		}

		matrixSum(a11, a22, temp1, n / 2);
		matrixSum(b11, b22, temp2, n / 2);
		matrixMul(temp1, temp2, m1, n / 2);
		matrixSum(a21, a22, temp1, n / 2);
		matrixMul(temp1, b11, m2, n / 2);
		matrixSub(b12, b22, temp1, n / 2);
		matrixMul(a11, temp1, m3, n / 2);
		matrixSub(b21, b11, temp1, n / 2);
		matrixMul(a22, temp1, m4, n / 2);
		matrixSum(a11, a12, temp1, n / 2);
		matrixMul(temp1, b22, m5, n / 2);
		matrixSub(a21, a11, temp1, n / 2);
		matrixSum(b11, b12, temp2, n / 2);
		matrixMul(temp1, temp2, m6, n / 2);
		matrixSub(a12, a22, temp1, n / 2);
		matrixSum(b21, b22, temp2, n / 2);
		matrixMul(temp1, temp2, m7, n / 2);
		matrixSum(m1, m4, temp1, n / 2);
		matrixSum(temp1, m7,temp2, n / 2);
		matrixSub(temp2, m5, c11, n / 2);
		matrixSum(m3, m5, c12, n / 2);
		matrixSum(m2, m4, c21, n / 2);
		matrixSum(m1, m3, temp1, n / 2);
		matrixSum(temp1, m6, temp2, n / 2);
		matrixSub(temp2, m2, c22, n / 2);

		for(int i = 0; i < n / 2; i++) {
			for(int j = 0; j < n / 2; j++) {
				c[i][j] = c11[i][j];
				c[i][j + n / 2] = c12[i][j];
				c[i + n / 2][j] = c21[i][j];
				c[i + n / 2][j + n / 2] = c22[i][j];
			}
		}

		for(int i = 0; i < n / 2; i++) {
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

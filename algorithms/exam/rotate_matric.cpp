#include <iostream>

int inputNumber();
int **cinMatrix(int, int);
void coutMatrix(int **, int, int);
void rotate(int **, int);

int main() {
	std::cout << "Enter size of matric: " << std::endl;
	int size = inputNumber();
	int **matric = cinMatrix(size, size);
	std::cout << "This is direct matric: " << std::endl;
    coutMatrix(matric, size, size);
    rotate(matric, size);
	return 0;
}

/* This function inputed an integer number */
int inputNumber() {
	int intNumber = 0;
    std::cout << "Enter number: ";
    std::cin >> intNumber;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(100,'\n');
		std::cout << "Enter only number: ";
		std::cin >> intNumber;
	}
	return intNumber;
}

/* This function outputed elements of matrices */
int **cinMatrix(int row, int col) {
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

/* This function fills the matrices elements with zeros */
void coutMatrix(int **matrix, int row, int col) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

/* This function rotates the matric */
void rotate(int ** array, int n) {
    std::cout << "This is rotated matric: " << std::endl;
    for(int j = 0; j < n; j++) {
        for(int i = n - 1; i >= 0; i--) {
            std::cout << array[i][j] << " ";
        }

        std::cout << std::endl;
    }
}
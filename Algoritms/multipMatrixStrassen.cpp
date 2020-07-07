#include <iostream>
using namespace std;

class Matr{
public:
	int **matrix;
	int size;

	Matr() {
		matrix = NULL;
		size = 0;
	}

	Matr(int **matrix, int size) {
		this -> matrix = matrix;
		this -> size = size;
	}
	
	Matr** split() {
        	int** arr = this -> matrix;
        	Matr **matr = new Matr*[2];
        	matr[0] = new Matr[2];
        	matr[1] = new Matr[2];
        	const int size = this -> size;
        	const int newSize = size / 2;
        	for(int m = 0; m < 2; ++m) {
        	        for(int n = 0; n < 2; ++n) {
        	                matr[m][n].matrix = new int*[newSize];
        	                for(int i = 0; i < newSize; ++i) {
        	                        matr[m][n].matrix[i] = new int[newSize];
        	                }
        	                matr[m][n].size = newSize;
        	        }
        	}
        	for(int i = 0; i < newSize; ++i) {
        	        for(int j = 0; j < newSize; ++j) {
        	                matr[0][0].matrix[i][j] = arr[i][j];
        	        }
        	}
        	for(int i = 0; i < newSize; ++i) {
        	        for(int j = newSize, k = 0; j < size; ++j, ++k) {
        	                matr[0][1].matrix[i][k] = arr[i][j];
        	        }
        	}
        	for(int i = newSize, m = 0; i < size; ++i, ++m) {
        	        for(int j = 0, n = 0; j < newSize; ++j, ++n) {
        	                matr[1][0].matrix[n][m] = arr[i][j];
        	        }
        	}
        	for(int i = newSize, m = 0; i < size; ++i, ++m) {
        	        for(int j = newSize, k = 0; j < size; ++j, ++k) {
        	                matr[1][1].matrix[m][k] = arr[i][j];
        	        }
        	}
        	return matr;
	}


	void toString() {
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size; ++j) {
				cout << '\t' << matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	Matr operator+(const Matr& m) {
		const int size = m.size;
		int **arr = new int*[size];
		for(int i = 0; i < size; ++i) {
			arr[i] = new int[size];
		}
		Matr matr(arr, size);// = new Matr(arr, size);
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size; ++j) {
				matr.matrix[i][j] = this -> matrix[i][j] + m.matrix[i][j];
			}
		}

		return matr;	
	}

        Matr operator-(const Matr& m) {
                const int size = m.size;
                int **arr = new int*[size];
                for(int i = 0; i < size; ++i) {
                        arr[i] = new int[size];
                }
                Matr matr(arr, size);// = new Matr(arr, size);
                for(int i = 0; i < size; ++i) {
                        for(int j = 0; j < size; ++j) {
                                matr.matrix[i][j] = this -> matrix[i][j] - m.matrix[i][j];
                        }
                }

                return matr;
        }


	Matr operator*(const Matr& m) {
                const int size = m.size;
                int **arr = new int*[size];
                for(int i = 0; i < size; ++i) {
                        arr[i] = new int[size];
                }
                Matr matr(arr, size);
                for(int i = 0; i < size; ++i) {
                        for(int j = 0; j < size; ++j) {
                                //matr.matrix[i][j] = this -> matrix[i][j] + m.matrix[i][j];
				matr.matrix[i][j]=0;
				for(int k=0;k < size; ++k) {
					matr.matrix[i][j] += this -> matrix[i][k] * m.matrix[k][j];
                        	}
			}
                }

                return matr;
        }

	static void mult(Matr*& m1, Matr*& m2) {
		Matr **m = m1 -> split();
		Matr **n = m2 -> split();
		Matr p1 = (m[0][0] + m[1][1]) * (n[0][0] + n[1][1]);
		Matr p2 = (m[1][0] + m[1][1]) * n[0][0];
		Matr p3 = m[0][0] * (n[0][1] - n[1][1]);
		Matr p4 = m[1][1] * (n[1][0] - n[0][0]);
		Matr p5 = (m[0][0] + m[0][1]) * n[1][1];
		Matr p6 = (m[1][0] - m[0][0]) * (n[0][0] + n[0][1]);
		Matr p7 = (m[0][1] - m[1][1]) * (n[1][0] + n[1][1]);

		Matr c11 = p1 + p4 - p5 + p7;
		Matr c12 = p3 + p5;
		Matr c21 = p2 + p4;
		Matr c22 = p1 - p2 + p3 + p6;
		
		int size = m1 -> size;
		for(int i = 0; i < size / 2; ++i) {
			for(int j = 0; j < size / 2; ++j) {
				cout << c11.matrix[i][j] << ' ';
			}

			for(int j = 0; j < size / 2; ++j) {
                                cout << c12.matrix[i][j] << ' ';
                        }
			
			cout << endl;
		}

                for(int i = 0; i < size / 2; ++i) {
                        for(int j = 0; j < size / 2; ++j) {
                                cout << c21.matrix[i][j] << ' ';
                        }

                        for(int j = 0; j < size / 2; ++j) {
                                cout << c22.matrix[i][j] << ' ';
                        }

                        cout << endl;
                }
	}

};

/*Matr** split(Matr *matrix) {
	int** arr = matrix -> matrix;
	Matr **matr = new Matr*[2];
	matr[0] = new Matr[2];
	matr[1] = new Matr[2];
	const int size = matrix -> size;
	const int newSize = size / 2;
	for(int m = 0; m < 2; ++m) {
		for(int n = 0; n < 2; ++n) {
			matr[m][n].matrix = new int*[newSize];
			for(int i = 0; i < newSize; ++i) {
				matr[m][n].matrix[i] = new int[newSize];
			}
			matr[m][n].size = newSize;
		}
	}
        for(int i = 0; i < newSize; ++i) {
                for(int j = 0; j < newSize; ++j) {
                        matr[0][0].matrix[i][j] = arr[i][j];
                }
        }
	for(int i = 0; i < newSize; ++i) {
                for(int j = newSize, k = 0; j < size; ++j, ++k) {
                        matr[0][1].matrix[i][k] = arr[i][j];
                }
        }
        for(int i = newSize, m = 0; i < size; ++i, ++m) {
                for(int j = 0, n = 0; j < newSize; ++j, ++n) {
                        matr[1][0].matrix[n][m] = arr[i][j];
                }
        }
        for(int i = newSize, m = 0; i < size; ++i, ++m) {
                for(int j = newSize, k = 0; j < size; ++j, ++k) {
                        matr[1][1].matrix[m][k] = arr[i][j];
                }
        }
	return matr;
}**/


int main() {
	int **arr = new int*[4];

	for(int i = 0; i < 4; ++i) {
		arr[i] = new int[4];
	}

	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			arr[i][j] = i + j;
		}
	}

	Matr *mat = new Matr(arr, 4);
	mat -> toString();
	Matr **ms = mat -> split();
	
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			cout << "C[" << i << "][" << j << ']' << endl;
			ms[i][j].toString();
		}
	}

	Matr ma = ms[0][0] * ms[0][1];
	ma.toString();

	Matr::mult(mat, mat);

	return 0;
}

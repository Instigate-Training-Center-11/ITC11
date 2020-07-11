#include <iostream>

bool sudoku(int array[9][9]);

/* Find empty elements in array */
bool find_null_value(const int array[9][9], int& row, int& col);

/* Check for unique value in rows and cols */
bool present_in_row_col(const int array[9][9], int row, int col, int value);

/* Check for unique value 3x3 subarray */
bool present_in_subarr(const int array[9][9], int row, int col, int value);

/* Check for unique value in rows and columns and in 3x3 subarray */
bool safe_for_use(const int array[9][9], int row, int col, int value);

/* Print two-dimensional 9x9 array */
void print(const int array[9][9]);

int main() {
    int array[9][9] = { { 5, 3, 0,    0, 7, 0,    0, 0, 0 },
                        { 6, 0, 0,    1, 9, 5,    0, 0, 0 },
                        { 0, 9, 8,    0, 0, 0,    0, 6, 0 },

                        { 8, 0, 0,    0, 6, 0,    0, 0, 3 },
                        { 4, 0, 0,    8, 0, 3,    0, 0, 1 },
                        { 7, 0, 0,    0, 2, 0,    0, 0, 6 },

                        { 0, 6, 0,    0, 0, 0,    2, 8, 0 },
                        { 0, 0, 0,    4, 1, 9,    0, 0, 5 },
                        { 0, 0, 0,    0, 8, 0,    0, 7, 9 } };

    std::cout << "\n  After:\n";
    std::cout << "  _____________________\n";
    print(array);

    sudoku(array);

    std::cout << "\n  Before:\n";
    std::cout << "  _____________________\n";
    print(array);

    return 0;
}

bool sudoku(int array[9][9]) {
    int row = 0;
    int col = 0;

    if (!find_null_value(array, row, col)) {
        return true;
    }

    for (int value = 1; value <= 9; ++value) {
        if (safe_for_use(array, row, col, value)) {
            array[row][col] = value;
            if (sudoku(array)) {
                return true;
            }

            /* If something wrong return value to null and continue */
            array[row][col] = 0;
        }
    }

    return false;
}

/* Find empty elements in array */
bool find_null_value(const int array[9][9], int& row, int& col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (array[row][col] == 0) {
                return true;
            }
        }
    }

    return false;
}

/* Check for unique value in rows or columns */
bool present_in_row_col(const int array[9][9], int row, int col, int value) {
    for (int i = 0; i < 9; ++i) {
        if (array[row][i] == value || array[i][col] == value) {
            return true;
        }
    }

    return false;
}

/* Check for unique value 3x3 subarray */
bool present_in_subarr(const int array[9][9], int row, int col, int value) {
    int subarr_row = row - row % 3;
    int subarr_col = col - col % 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (array[i + subarr_row][j + subarr_col] == value) {
                return true;
            }
        }
    }

    return false;
}

/* Check for unique value in rows and columns and in 3x3 subarray */
bool safe_for_use(const int array[9][9], int row, int col, int value) {
    return !present_in_row_col(array, row, col, value) && !present_in_subarr(array, row, col, value);
}

/* Print two-dimensional 9x9 array */
void print(const int array[9][9]) {
    for (int i = 0, count = 2; i < 9; ++i) {
        std::cout << "  |";
        for (int j = 0, count = 2; j < 9; ++j) {
            if (array[i][j] == 0) {
                if (j == count) {
                    std::cout << "_ |";
                    count += 3;
                } else {
                    std::cout << "_ ";
                }
            } else if (j == count) {
                std::cout << array[i][j] << " |";
                count += 3;
            } else {
                std::cout << array[i][j] << " ";
            }
        }

        if (i == count) {
            std::cout << std::endl;
            std::cout << "  |______|______|______|\n";
            count += 3;
        } else {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
}
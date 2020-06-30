#include <iostream>

void displayArray(int *, int);
void selectionSort(int *, int);
void swap(int &, int &);

int main() {
    int array[] = {95, 45, 48, -8, -25, 98, 1, 400085, 65, 478, 1, 7777};
    int n = sizeof(array) / sizeof(array[0]);
    displayArray(array, n);
    selectionSort(array, n);
    std::cout << std::endl;
    displayArray(array, n);
    return (0);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void displayArray(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << '\t';
    }

    std::cout << std::endl;
}

void selectionSort(int *array, int size) {
    int temp;
    int min;

    for (int i = 0; i < size; ++i) {
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(array[i],array[min]);
        }
    }
}
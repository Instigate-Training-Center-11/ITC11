#include <iostream>

void inputArray(int* arr,unsigned int size);
void swap(int& indexNumOne, int& indexNumTwo);
void shellSort(int* array, unsigned int sizeArr);
void printArray(int* array,unsigned int size);

int main() {
    srand(time(NULL));
    unsigned int start_time =  clock();
    unsigned int sizeArray = 10;
    int* arr = new int[sizeArray];
    inputArray(arr,sizeArray);
    printArray(arr,sizeArray);
    std::cout << "\t\tCall function merge sort\n";
    shellSort(arr,sizeArray);
    printArray(arr,sizeArray);
    unsigned int end_time = clock();
    std::cout << "\nruntime = " << clock()/1000.0 << " ms" << std::endl;

    return 0;
}

void inputArray(int* arr,unsigned int size) {
    unsigned int number = 100;
    for (unsigned int i = 0; i < size; ++i) {
        arr[i] = rand() % number - number/2;
    }
}

void swap(int& indexNumOne, int& indexNumTwo) {
    int temp = 0;
    temp = indexNumOne;
    indexNumOne = indexNumTwo;
    indexNumTwo = temp;
}


void shellSort(int* array, unsigned int sizeArr) {
    int j =0;
    int i = 0;
    int end = 0;
    for (i = sizeArr/2; i > 0; i = i/2) {
        for (j = i; j < sizeArr; ++j) {
            end = j;
            while (array[end - i] > array[end] && end - i >= 0) {
                swap(array[end - i], array[end]);
                end = end - i;
            }
        }
    }
}

void printArray(int* array,unsigned int size){
    unsigned int i = 0;
    while (i < size) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
        ++i;
    }

}

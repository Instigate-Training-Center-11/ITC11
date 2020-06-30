#include <iostream>
#include <ctime>

/* sort array ascending */
void quickSort(int* array, int left, int right);
/* initialize the array with random values  */
void inputArray(int* arr,unsigned int size);
void swap(int& indexNumOne, int& indexNumTwo);
void printArray(int* array,unsigned int size);

int main() {

    srand(time(NULL));
    unsigned int start_time =  clock();
    unsigned int sizeArray = 10;
    int* arr = new int[sizeArray];
    inputArray(arr,sizeArray);
    printArray(arr,sizeArray);
    std::cout << "\t\tCall function merge sort\n";
    quickSort(arr,0,sizeArray);
    printArray(arr,sizeArray);
    unsigned int end_time = clock();
    std::cout << "\nruntime = " << clock()/1000.0 << " ms" << std::endl;

    return 0;
}

void quickSort(int* array, int left, int right) {
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];

    while (i <= j) {

        while (array[i] < pivot) {
            i++;
        }

         while (array[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(array[i],array[j]);
            i++;
            j--;
        }

    }

    if (left < j) {
        quickSort(array, left, j);
    }

    if (i < right) {
        quickSort(array, i, right);
    }

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

void printArray(int* array,unsigned int size){
    unsigned int i = 0;
    while (i < size) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
        ++i;
    }

}

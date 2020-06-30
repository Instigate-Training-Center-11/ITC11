#include <iostream>
#include <cstdio>
#include <cstdlib>

/*swapping two elements*/
void swap(int &val1, int &val2) {
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

/*choose array elements random*/
int *array(int* arr, int size){
    srand(time(0));
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 1000;
    }
    return arr;
}

/*show array*/
void display(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/*sorting by quick sort where pivot is middle element*/
void quickSort(int*arr, int begin, int end){
    int b = begin;
    int e = end;
    int mid = arr[(begin + end) / 2];
    while (b <= e) {
        while(arr[b] < mid) {
            b++;
        }

        while (arr[e] > mid) {
            e--;
        }

        if (b <= e) {
            swap(arr[b], arr[e]);
            b++;
            e--;
        }
    }

    if (begin < e) {
        quickSort(arr, begin, e);
    }

    if (b < end) {
        quickSort(arr, b, end);
    }
}

int part(int *arr, int begin, int end) {
    int i = begin - 1;
    int pivot = arr[end];
    for (int j = begin; j <= end - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i+1);
}

/*sorting by quick sort where pivot is last element*/
void qSort(int *arr, int begin, int end) {
    if (begin < end) {
        int piv = part(arr, begin,end);
        qSort(arr, begin, piv - 1);
        qSort(arr, piv + 1, end);
    }
}

int main() {
    int begin = 0;
    int end;
    int size;
    std::cout << "Enter size of array " << "\n";
    std::cin >> size;
    end = size - 1;
    int* arr = new int[size];
    arr = array(arr, size);
    std::cout << "Array before sorting" << "\n";
    display(arr, size);
    std::cout << "Array after sorting" << "\n";
    quickSort(arr, begin, end);
    display(arr, size);
    std::cout << "Array after q sorting" << "\n";
    qSort(arr, begin, end);
    display(arr, size);
    delete []arr;
    return 0;
}


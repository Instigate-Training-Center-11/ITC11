#include <iostream>

void swap(int &val1, int &val2) {
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

void display(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}

void shellSort(int *arr, int size) {
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = i; j < size; ++j) {
            for (int tmp = j - i; tmp >= 0 && arr[tmp + i] < arr[tmp]; tmp -= i) {
                swap(arr[tmp + i], arr[tmp]);
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements:" << std::endl;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Array before Sorting" << std::endl;
    display(arr, n);
    shellSort(arr, n);
    std::cout << "Array after Sorting" << std::endl;
    display(arr, n);
    return 0;
}

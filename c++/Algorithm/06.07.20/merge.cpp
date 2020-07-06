#include <iostream>

void display(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}

void merge(int *arr, int left, int mid, int right) {
    int l = mid - left + 1;
    int r = right - mid;
    int lArr[l];
    int rArr[r];
    int i;
    int j;
    int tmp;

    for (i = 0; i < l; ++i) {
        lArr[i] = arr[left + i];
    }

    for (j = 0; j < r; ++j) {
        rArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    tmp = left;

    while (i < l && j < r) {
        if (lArr[i] < rArr[j]) {
            arr[tmp] = lArr[i];
            i++;
        } else {
            arr[tmp] = rArr[j];
            j++;
        }
        tmp++;
    }

    while (i < l) {
        arr[tmp] = lArr[i];
        i++;
        tmp++;
    }

    while (j < r) {
        arr[tmp] = rArr[j];
        j++;
        tmp++;
    }
}

void mergeSort(int *arr, int left, int right) {
    int mid;
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int num;
    std::cout << "Enter the number of elements: ";
    std::cin >> num;
    int arr[num];
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Array before Sorting: " << std::endl;
    display(arr, num);
    mergeSort(arr, 0, num - 1);
    std::cout << "Array after Sorting: " << std::endl;
    display(arr, num);
    return 0;
}

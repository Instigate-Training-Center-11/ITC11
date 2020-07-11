#include <iostream>
#include <vector>

void swap(int&, int&);
void bubbleSort(int*, int);
void findSubArray(std::vector<int>);

int main() {
    std::vector<int> arr = {0, -1, 2, -3, 1};

    std::cout << "The subArrays, which sum is '0', is: " << "\n";
    findSubArray(arr);

    return 0;
}

void findSubArray(std::vector<int> arr) {
    const int size = 3;
    int sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        for(int j = i + 1; j < arr.size() - 1; ++j) {
            for(int k = j + 1; k < arr.size(); ++k) {
                int first = arr[i];
                int second = arr[j];
                int subArr[size];
                if(first  + second + arr[k] == sum) {
                    subArr[0] = first;
                    subArr[1] = second;
                    subArr[2] = arr[k];
                    bubbleSort(subArr, size);

                    for(int j = 0; j < size; ++j) {
                        std::cout << subArr[j] << "\t";
                    }

                    std::cout  << "\n";
                }
            }
        }
    }
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int *arr, int n) {
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
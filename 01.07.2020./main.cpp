#include <iostream>
#include "allSearchingAlgorithms.cpp"

int main()
{

int size;
std::cout << "Enter the size of array: " << std::endl;
std::cin >> size;
int *arr = new int[size] ;
if (size <= 0) {
std::cout << "Size will not be equal or les then zero." << std::endl;
} else {
for (int i = 0; i < size; i++) {
    std::cout << "Enter the numbers " << std::endl;
    std::cin >> arr[i];   
}    
    selectionSort(arr, size);
    display(arr, size);

    inputParameters (arr);
}
    std::cout << std::endl;
    return 0;
}
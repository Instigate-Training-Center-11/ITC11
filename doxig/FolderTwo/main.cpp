#include <iostream>
#include "allSearchingAlgorithms.cpp"
using namespace std;

int main()
{
    int arr[] = {10, 8, 3, 1, 7, 4, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    display(arr, size);

    int index;
    int value;

    cout << "For linearSearch enter 1:" << endl;

    cin >> index;

    cout << "Enter the value which you want to find in array:" << endl;
    cin >> value;

    cout << "Index of the number is: " << linearSearch(arr, size, value);

    cout << endl;
    return 0;
}
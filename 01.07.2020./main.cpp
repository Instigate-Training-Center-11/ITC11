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
    cout << "For binarySearch enter 2:" << endl;
    cout << "For jumpSearch enter 3:" << endl;
    cout << "For interpolationSearch enter 4:" << endl;
    cout << "For exponentialSearch enter 5:" << endl;
    cout << "For ternarySearch enter 6:" << endl;
    cin >> index;

    cout << "Enter the value which you want to find in array:" << endl;
    cin >> value;

    switch (index)
    {
    case 1:
        cout << "Index of the number is: " << linearSearch(arr, size, value);
        break;
    case 2:
        cout << "Index of the number is: " << binarySearch(arr, 0, size, value);
        break;
    case 3:
        cout << "Index of the number is: " << jumpSearch(arr, size - 1, value);
        break;
    case 4:
        cout << "Index of the number is: " << interpolationSearch(arr, 0, size, value);
        break;
    case 5:
        cout << "Index of the number is: " << exponentialSearch(arr, 0, size, value); /* exponentialSearch works correctly into iside file */
        break;                                                                        /* but I don't know whay it returs -1 here :( */
    case 6:
        cout << "Index of the number is: " << ternarySearch(arr, 0, size, value);
        break;
    default:
        break;
    }
    cout << endl;
    return 0;
}
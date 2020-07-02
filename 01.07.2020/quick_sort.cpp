#include <iostream>

void quickSort(int*, int, int);
int quickSwap(int*, int, int);
int swap(int&, int&);

/* function for quck sorting */
void quickSort(int* arr, int first, int last)
{
    if (first <= last)
    {
        int index = quickSwap(arr, first, last);
        quickSort(arr, first, index - 1);
        quickSort(arr, index + 1, last);
    }
}


/* function will compare array elements with pivot,
if array element is greater than pivot it must be moved into left hand of pivot*/
int quickSwap(int* arr, int first, int last)
{
    int index = first;
    int pivot = arr[last];

    for(int i = first; i < last; ++i)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[index], arr[i]);
            ++index;
        }
    }

    swap(arr[index], arr[last]);

    return index;
}

/* function to swap two values */
int swap(int& val1, int& val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}
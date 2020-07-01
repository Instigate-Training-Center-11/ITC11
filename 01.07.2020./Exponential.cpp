#include <iostream>
using namespace std;

int size = 0;

/* create function for swap elements of array */
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

/* create function for display elements of array */
void display(int arr[])
{
    cout << "Displaying elements: " << endl;
    /* display array elements */
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

/* create function for sort elements of array */
void selectionSort(int arr[], int size)
{
    int j = 0;
    /* if we have n elements in array, we need */
    /* do  n - 1 steps to pass array for selection sort */
    for (int i = 0; i < size - 1; i++)
    {
        /* we need for firs to find the minimum element in array */
        int min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        /* swap minimum element with first big element in array */
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
    }
}

int binarySearch(int arr[], int left, int right, int num)
{
    int result = -1;

    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == num)
        {
            result = mid;
        }
        else if (arr[mid] > num)
        {
            result = binarySearch(arr, left, mid - 1, num);
        }
        else if (arr[mid] < num)
        {
            result = binarySearch(arr, mid + 1, right, num);
        }
    }
    return result;
}

/* create ExponentialSearch function to shearch some number and return the position */
int exponentialSearch(int arr[], int left, int right, int num)
{
    int i = 1;

    while (i < right - left)
    {

        if (arr[i] < num)
        {

            i = (i * 2);
        }
        else
        {

            return -1;
        }
    }
    return binarySearch(arr, i / 2, i, num);
}

int main()
{
    size = 8;
    int arr[size] = {8, 5, 9, 6, 7, 5, 6, 3};

    selectionSort(arr, size);
    display(arr);

    int index = exponentialSearch(arr, 0, size, 7);
    cout << index << endl;
    cout << endl;
    return 0;
}
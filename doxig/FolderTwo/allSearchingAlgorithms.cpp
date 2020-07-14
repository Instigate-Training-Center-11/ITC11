#include <iostream>
#include <cmath>
using namespace std;

int size = 0;

 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}


void display(int arr[], int size)
{
    cout << "Displaying elements: " << endl;

    /* display array elements */
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

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


int linearSearch(int arr[], int size, int num)
{
    int result = -1;
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            result = i;
        }
    }
    return result;
}


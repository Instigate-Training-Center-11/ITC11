#include <iostream>
#include <cmath>
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
void display(int arr[], int size)
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

/* create linearSearch function to search some number and return the position */
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

/* create jumpSearch function to search some number and return the position */
int jumpSearch(int arr[], int length, int num)
{
    int left = 0;
    int right = sqrt(length);

    while (right < length && arr[right] <= num)
    {
        left = right;
        right += sqrt(length);
        if (right > length - 1)
        {
            right = length;
        }
    }
    for (int i = left; i < right; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
/* create binarySearch function to search some number and return the position */
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

/* create exponentialSearch function to search some number and return the position */
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

/* create interpolationSearch function to search some number and return the position */
int interpolationSearch(int arr[], int left, int right, int num)
{
    int lowIndex = left;
    int highIndex = right - 1;
    int mid;

    while (arr[highIndex] != arr[lowIndex] && num >= arr[lowIndex] && num <= arr[highIndex])
    {
        mid = lowIndex + ((num - arr[lowIndex]) * (highIndex - lowIndex) / (arr[highIndex] - arr[lowIndex]));

        if (num > arr[mid])
        {
            lowIndex = mid + 1;
        }
        else if (num < arr[mid])
        {
            highIndex = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    if (num == arr[lowIndex])
    {
        return lowIndex;
    }
    return -1;
}
/* create ternarySearch function to search some number and return the position */
int ternarySearch(int arr[], int left, int right, int num)
{
    int interval = (right - left) / 3;

    if (right - left > 0)
    {
        /* we nee to select two middle positions with the interval */
        int midOne = left + interval;
        int midTwo = midOne + interval;

        if (arr[midOne] == num)
        {
            return midOne;
        }
        if (arr[midTwo] == num)
        {
            return midTwo;
        }
        if (num < arr[midOne])
        {
            return ternarySearch(arr, left, midOne, num);
        }
        if (num > arr[midTwo])
        {
            return ternarySearch(arr, midTwo + 1, right, num);
        }
        return ternarySearch(arr, midOne, midTwo, num);
    }
    else
    {
        return -1;
    }
}
#include <iostream>
using namespace std;

int size = 0;

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

void merge(int arr[], int left, int mid, int right)
{
    int tempArray[size];
    int i = left;    /* for increment in the 1st sorted part of array */
    int j = mid + 1; /* for increment in 2nd sorted part of array */
    int k = 0;       /* for increment in the new sorted array */
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            tempArray[k++] = arr[i++];
        else
            tempArray[k++] = arr[j++];
    }
    while (i <= mid)
        tempArray[k++] = arr[i++];
    while (j <= right)
        tempArray[k++] = arr[j++];
    k--;
    while (k >= 0)
    {
        arr[k + left] = tempArray[k];
        k--;
    }
}

/* create function for dividing array and then sorting */
void mergeSort(int arr[], int left, int right)
{
    int mid;
    /* until it becomes 1 element after dividing */
    if (left < right)
    {
        /* calculate the middle element */
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    size = 6;
    int arr[size] = {7, 4, 10, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    display(arr);
    cout << endl;
    return 0;
}

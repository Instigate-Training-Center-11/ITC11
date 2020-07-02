/* function for Binary Search algorithm */

int binarySearch(int* arr, int first, int last, int key)
{

    if (key <= arr[last] && key >= arr[first])
    {
        /* find middle index of array */
        int middle = first + (last - first) / 2;

        /* check if key is equal to element which has middle index and return middle if true */
        if (key == arr[middle])
        {
            return middle;
        }
        /* if key is smaller then element in middle index then repeat binary search algorithm for left part of middle index */
        else if (key < arr[middle])
        {
            return binarySearch(arr, first, middle - 1, key);
        }
        /* else key is greates then element in middle index so repeat binary search algorithm for right part of middle index */
        else
        {
            return binarySearch(arr, middle + 1, last, key);
        }
    }

    /* Key not found */
    return -1;
}
/* function for Exponential Search algorithm */
// #include <bits/stdc++.h>
// #include <algorithm>

int exponentialSearch(int* arr, int size, int key)
{
    if (key >= arr[0] && key <= arr[size - 1])
    {
        /* check if key is first element */
        if (arr[0] == key)
        {
            return 0;
        }
        /* find range where key can be */
        int i = 1;
        while (i < size && arr[i] <= key)
        {
            i = i * 2; 
        }

        return binarySearch(arr, i/2, std::min(i, size), key);
        /* call binary search for the found range */

    }

    /* Key not found */
    return -1;
}
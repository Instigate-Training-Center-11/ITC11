/* function for Jump Search algorithm */

#include <cmath>

int jumpSearch(int arr[], int size, int key)
{
    if (key <= arr[size - 1] && key >= arr[0])
    {
        int step = sqrt(size);
        int first = 0;
        int last = first + step;

        /* get the right interval to search */
        while (last < size && arr[last] <= key)
        {
            first = last;
            last += step;

            /* check if the last index after jump is greater than the size and in case of it reset the value of last as size -1 */
            if (last > size - 1)
            {
       	        last = size;
            }
        }

        /* use Linear Search algorithm to find key from seperated interval */
        linearSearch(arr, size, key);
    }

    /* Key not found */
    return -1;
}
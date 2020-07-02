/* Function to perform Ternary Search */

int ternarySearch(int* arr, int first, int last, int key)
{
    if (first <= last)
    {
        /* ind the middle1 and middle2 */
        int middle1 = first + (last - first) / 3;
        int middle2 = last - (last - first) / 3;

        /* check if key is equal at any middle element */
        if (key == arr[middle1])
        { 
            return middle1; 
        } 
        if (key == arr[middle2])
        { 
            return middle2; 
        } 

        /* check in which part key is located */
        if (key < arr[middle1])
        {
            /* The key is in first part */
            return ternarySearch(arr, first, middle1 - 1, key); 
        } 
        else if (key > arr[middle2])
        {
            /* The key is in last part */
            return ternarySearch(arr, middle2 + 1, last, key); 
        } 
        else
        {
            /* The key is between middle1 and middle2 */
            return ternarySearch(arr, middle1 + 1, middle2 - 1, key);
        }
    }

    /* Key not found */
    return -1;
}
/* function for Linear Searching algorithm */
int linearSearch(int* arr, int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (key == arr[i])
        {
            return i;
        }
    }

    /* Key not found */
    return -1;
}
/* function for Interpolation Search algorithm */

int interpolationSearch(int* arr, int size, int key) 
{ 
    int first = 0;
    int last = (size - 1); 
  
    while (key >= arr[first] && key <= arr[last]) 
    { 
        if (first == last) 
        { 
            if (arr[first] == key)
            {
                return first;
            }

            return -1;
        }
        /* formula to finde the position */
        int position = first + (((last - first) / (arr[last] - arr[first])) * (key - arr[first]));
  
        /* check if key is equal to the value in the position */ 
        if (arr[position] == key)
        {
            return position;
        }
  
        /* check if key is smaller to the value in the position */ 
        if (key < arr[position])
        {
            last = position - 1;
        }

        /* case the key is greater to the value in the position */ 
        else
        {
            first = position + 1;
        }
    }

    /* Key not found */
    return -1;
}
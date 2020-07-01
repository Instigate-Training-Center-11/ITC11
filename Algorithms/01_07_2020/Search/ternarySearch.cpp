/* Ternary Search */
int ternarySearch(int *arr, int low, int high, int element) {
    if(low <= high) {
        int mid1 = (low + (high - low) / 3);
        int mid2 = (mid1 + (high - low) / 3);

        if(arr[mid1] == element) {
            return mid1;
        }

        if(arr[mid2] == element) {
            return mid2;
        }

        if(element < arr[mid1]) {
            return ternarySearch(arr, low, mid1 - 1, element);
        }

        if(element > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, high, element);
        }

        return ternarySearch(arr, mid1 + 1, mid2 - 1, element);
    }

    return -1;
}
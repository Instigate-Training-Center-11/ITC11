/* Binary search */
int binarySearch(int *arr, int low, int high, int element) {
    if (high >= low) {
        if (arr[low] == element) {
            return low;
        }

        if (arr[high] == element) {
            return high;
        }

        int mid = low + (high - low) / 2;
        if (arr[mid] == element) {
            return mid;
        }

        if (arr[mid] > element) {
            return binarySearch(arr, low, mid - 1, element);
        }

        return binarySearch(arr, mid + 1, high, element);
    }

    return -1;
}
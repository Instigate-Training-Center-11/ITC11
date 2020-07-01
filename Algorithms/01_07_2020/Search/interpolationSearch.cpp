/*
 * Interpolation Search. This algorithm will work well for sorted arrays
 * where elements are distributed evenly.
 */
int interpolationSearch(int *arr, int size, int element) {
    int low = 0;
    int high = size - 1;
    int mid = 0;

    while (arr[low] <= element && arr[high] >= element) {
        mid = (low + ((element - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[mid] > element) {
            high = mid - 1;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    if (arr[low] == element) {
        return low;
    }

    return -1;
}
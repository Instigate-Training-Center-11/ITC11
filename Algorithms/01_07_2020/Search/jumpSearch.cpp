#include <cmath>

/* Jump search */
int jumpSearch(int *arr, int size, int element) {
    int tmp = 0;
    int step = sqrt(size);

    while(step < size && arr[step] <= element) {
        tmp = step;
        step += sqrt(size);
    }

    for(int i = tmp; i < step; ++i) {
        if(arr[i] == element) {
            return i;
        }
    }

    return -1;
}
/* Please compile the following code using --std=c++11 flag:
g++ MergeSort.cpp --std=c++11 */

#include <iostream>
#include <chrono>

/* function prototypes */
void print(int*, int);
void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main()
{
    /* ask user to enter number of array elements */
    int n = 0;
    std::cout << "Number of elements you want to insert: ";
    std::cin >> n;

    int arr[n];

    /* ask user to enter array elements */
    int input = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "element " << i + 1 << " : ";
        std::cin >> input;
        arr[i] = input;
    }    

    /* call "print" function to print array elements before merge sort */
    std::cout << "\nBefore Merge Sort: ";
    print(arr, n);
    std::cout << std::endl << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    /* call "mergeSort" function to apply merge sort algorithm on array elements */
    mergeSort(arr, 0, n - 1);

    auto stop = std::chrono::high_resolution_clock::now();

    /* call "print" function to print array elements after merge sort */
    std::cout << "After Merge Sort: ";
    print(arr, n);
    std::cout << std::endl << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time duration : " << duration.count() << std::endl;

    return (0);
}

void mergeSort(int* arr, int first, int last)
{
    if (first < last)
    {
        int middle = (first + last) / 2;

        /* split array elements into two parts */
        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);

        /* merge array elements to get sorted output */
        merge(arr, first, middle, last);
    }
}

void merge(int* arr, int first, int middle, int last)
{
    int f = first;
    int m = middle + 1;
    int i = 0;
    int tempArr[last + 1];

    /* comparing and merging elements of first and second parts of array
    into new array in sorted order */
    while (f <= middle && m <= last)
    {
        if (arr[f] <= arr[m])
        {
            tempArr[i] = arr[f];
            ++i;
            ++f;
        }
        else
        {
            tempArr[i] = arr[m];
            ++i;
            ++m;
        }
    }

    /* insert remaining elements from first part of array into new array */
    while (f <= middle)
    {
        tempArr[i] = arr[f];
        ++i;
        ++f;
    }

    /* insert remaining elements from second part of array into new array */
    while (m <= last)
    {
        tempArr[i] = arr[m];
        ++i;
        ++m;
    }

    --i;
    
    /* assign sorted data to previous array */
    for (i = first; i <= last; ++i)
    {
        arr[i] = tempArr[i - first];
    }
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}
/* Please compile the following code using --std=c++11 flag:
g++ TimeComparison.cpp */

#include <iostream>
#include <chrono>

/* function prototypes */
void print(int*, int);
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void insertionSort(int*, int);

int main()
{
   int arr[] = {3, 2, 7, 1, 8, 5, 4, 12, 4, 22, 8, 31, 7, 13, 3, 2, 7, 1, 8, 5, 4, 12, 4, 22, 8, 31, 7, 13, 16, 12, 77, 23, 26, 19};
   int n = sizeof(arr) / sizeof(arr[0]);

    /* call "print" function to print array elements before sorting */
    std::cout << "\nBefore sorting: ";
    print(arr, n);
    std::cout << std::endl << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    /* call "mergeSort" function to apply merge sort algorithm on array elements */
    mergeSort(arr, 0, n - 1);

    auto stop1 = std::chrono::high_resolution_clock::now();

    /* call "print" function to print array elements after merge sort */
    std::cout << "After Merge Sort: ";
    print(arr, n);
    std::cout << std::endl << std::endl;

    insertionSort(arr, n);
    auto stop2 = std::chrono::high_resolution_clock::now();

    /* call "print" function to print array elements after insertion sort */
    std::cout << "After Insertion Sort: ";
    print(arr, n);
    std::cout << std::endl << std::endl;


    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start);
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start);

    std::cout << "Merge algorithm time duration : " << duration1.count() << std::endl;
    std::cout << "Insertion algorithm time duration : " << duration2.count() << std::endl;

    if (duration1.count() < duration2.count())
    {
        std::cout << "\n*Merge sort algorithm is more efficient in terms of times then Insertion sort\n" << std::endl;
    }
    else if (duration1.count() < duration2.count())
    {
        std::cout << "\n*Insertion sort algorithm is more efficient in terms of times then Merge sort\n" << std::endl;
    }
    else
    {
        std::cout << "\nThe efficiencies of Merge Sort and Insertion Sort algorithms are equal in terms of time\n" << std::endl;
    }
    
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

void insertionSort(int* arr, int n)
{
   for (int i = 1; i < n; ++i)
   {
      int curr = arr[i];
      int j = i;
      while (j > 0 && arr[j-1] > curr)
      {
         arr[j] = arr[j-1];
         --j;
      }
      arr[j] = curr;
   }
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

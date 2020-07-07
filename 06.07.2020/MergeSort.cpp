#include <iostream>

void merge(int* arr, int first, int mid, int last)
{
    int f = first;
    int m = mid + 1;
    int i = 0;
    int tempArr[last + 1];

    while (f <= mid && m <= last)
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

    while (f <= mid)
    {
        tempArr[i] = arr[f];
        ++i;
        ++f;
    }

    while (m <= last)
    {
        tempArr[i] = arr[m];
        ++i;
        ++m;
    }

    --i;
    
    for (i = first; i <= last; ++i)
    {
        arr[i] = tempArr[i - first];
    }
}

void mergeSort(int* arr, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;

        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

int checkType(int input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "\nPlease enter integer type data: ";
        std::cin >> input;
    }

    return input;
}

int main()
{
    int n = 0;
    std::cout << "Number of elements: ";
    std::cin >> n;
    n = checkType(n);

    int a[n];

    int input = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "element " << i + 1 << " : ";
        std::cin >> input;
        input = checkType(input);
        a[i] = input;
    }    

    std::cout << "\nArray before Merge Sort: ";
    print(a, n);
    std::cout << std::endl << std::endl;

    mergeSort(a, 0, n - 1);

    std::cout << "Array after Merge Sort: ";
    print(a, n);
    std::cout << std::endl << std::endl;

    return (0);
}
#include <iostream>

#include "linear_search.cpp"
#include "binary_search.cpp"
#include "jump_search.cpp"
#include "interpolation_search.cpp"
#include "exponential_search.cpp"
#include "ternary_search.cpp"



#include "quick_sort.cpp"


void print(int*, int);
void printKey(int, int);
void menu();
int checkType(std::string, int);

int main()
{
    /* get size of array */
    int size = 0;
    std::string str1 = "Enter number of array elements: ";
    std::cout << str1;
    std::cin >> size;
    size = checkType(str1, size);

    /* get elements of array */
    int arr[size];
    int element = 0;
    std::cout << "Enter array elements: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "array[" << i << "] = ";
        std::cin >> element;
        element = checkType("array element: ", element);
        arr[i] = element;
    }

    std::cout << std::endl;

    /* get the key value which must be searched */
    int key = 0;
    std::cout << "==== Enter the key number which index you want to get ====" << std::endl;
    std::string str2 = "Key = ";
    std::cout << str2;
    std::cin >> key;
    key = checkType(str2, key);

    std::cout << std::endl;

    /* desplay user input array without sorting */
    std::cout << "====== Array without sorting ======\n";
    print(arr, size);

    std::cout << std::endl;

    /* call menu for user to chose the type of seraching algorithm */
    menu();

    std::cout << std::endl;

    int userChoise = 0;
    int keyIndex = 0;

    do
	{
		std::string str3 = "\nPlease, choose a searching algorithm you want to use: ";
		std::cout << str3;
		std::cin >> userChoise;
        userChoise = checkType(str3, userChoise);
        std::cout << std::endl;

		switch(userChoise)
		{
			case 1:
                std::cout << "==== You choose Linear Search algorithm ====" << std::endl;

                keyIndex = linearSearch(arr, size, key);
                printKey(key, keyIndex);

				break;

			case 2:
                std::cout << "==== You choose Binary Search algorithm ====" << std::endl << std::endl;

                quickSort(arr, 0, size - 1);
                std::cout << "====== Array after sorting ======\n";
                print(arr, size);

                keyIndex = binarySearch(arr, 0, size - 1, key);
                printKey(key, keyIndex);

				break;

			case 3:
                std::cout << "==== You choose Jump Search algorithm ====" << std::endl << std::endl;

                quickSort(arr, 0, size - 1);
                std::cout << "====== Array after sorting ======\n";
                print(arr, size);

                keyIndex = jumpSearch(arr, size, key);
                printKey(key, keyIndex);

                break;

			case 4:
                std::cout << "==== You choose Interpolation Search algorithm ====" << std::endl << std::endl;

                quickSort(arr, 0, size - 1);
                std::cout << "====== Array after sorting ======\n";
                print(arr, size);

                keyIndex = interpolationSearch(arr, size, key);
                printKey(key, keyIndex);

                break;

			case 5:
                std::cout << "==== You choose Exponential Search algorithm ====" << std::endl << std::endl;

                quickSort(arr, 0, size - 1);
                std::cout << "====== Array after sorting ======\n";
                print(arr, size);

                keyIndex = exponentialSearch(arr, size, key);
                printKey(key, keyIndex);

                break;

			case 6:
                std::cout << "==== You choose Trnary Search algorithm ====" << std::endl << std::endl;

                quickSort(arr, 0, size - 1);
                std::cout << "====== Array after sorting ======\n";
                print(arr, size);

                keyIndex = ternarySearch(arr, 0, size - 1, key);
                printKey(key, keyIndex);

                break;

            case 7:
                std::cout << "EXIT" << std::endl;
                break;
		}

	} while (userChoise != 7);


    return 0;
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printKey(int key, int keyIndex)
{
    if (keyIndex != -1)
    {
        std::cout << "The index of " << key << " is: " << keyIndex << std::endl;
    }
    else
    {
        std::cout << "Array does NOT contain element like " << key << " ..." <<  std::endl;
    }
}

/* check  whether input number is integer or not,
if it is not an integer ask user to enter a positive number,
if it is an integer then return it */
int checkType(std::string str, int input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "\nPlease enter integer type data: " << std::endl;
        std::cout << str;
        std::cin >> input;
    }

    return input;
}

void menu()
{
    std::cout << "==== Search Algorithms menu ====" << std::endl;
    std::cout << "1. Linear search." << std::endl;
    std::cout << "2. Binary search" << std::endl;
    std::cout << "3. Jump search" << std::endl;
    std::cout << "4. Interpolation search" << std::endl;
    std::cout << "5. Exponential search" << std::endl;
    std::cout << "6. Trnary search" << std::endl;
    std::cout << "7. EXIT" << std::endl;
}
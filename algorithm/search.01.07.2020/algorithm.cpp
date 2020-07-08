#include "algorithm.h"
#include <cmath>
#include <iostream>


int ternarySearch(int* arr, int key, int start,int end) {
    std::cout << "\n\t\tCall algorithm ternarySearch\n";
    if (end - start == 2) {
        return (arr[0] == key) ? 0 : 1;
    }
    if (end >= start) {
        int position1 = start + (end-start)/3;
        int position2 = end -  (end-start)/3;

        if (arr[position1] == key) {
            std:: cout << "\nFound in index -> ";
            return position1;
        }

        if (arr[position2] == key) {
            std:: cout << "\nFound in index -> ";
            return position2;
        }

        if (key < arr[position1]) {
            return ternarySearch(arr, key, start, position1 - 1);
        } else if (key > arr[position2]) {
            return ternarySearch(arr, key, position2 + 1, end);
        }

        return ternarySearch(arr, key, position1 + 1, position2 - 1);

    }
    return -1;
}

int exponentialSearch(int* arr, int key, int start, int end) {
    std::cout << "\n\t\tCall algorithm exponentialSearch\n";
    if (arr[start] == key) {
        std:: cout << "\nFound in index -> ";
        return start;
    }

    if (arr[end] == key) {
        std:: cout << "\nFound in index -> ";
        return start;
    }

    int  shift  =  1;
    while (shift < (end - start)) {
        if (2 * shift >= end) {
            return  binarySearch(arr, key, shift/2, end - 1);
        }
        if (arr[shift] < key) {
            shift  *=  2;
        }
    }

    return  binarySearch(arr, key, shift/2, shift);
}

int interpolationSearch (int* arr, int key, unsigned int size) {
    std::cout << "\n\t\tCall algorithm interpolationSearch\n";
    int low = 0;
    int high = size - 1;
    int mid;

    while (arr[low] <= key && arr[high] >= key) {
        mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[mid] < key) {
            low = mid + 1;
        } else if (arr[mid] > key) {
            low = mid - 1;
        } else {
            std:: cout << "\nFound in index -> ";
            return mid;
        }
    }

    if (arr[low] == key) {
        std:: cout << "\nFound in index -> ";
        return low;
    } else {
        std:: cout << "\nValue not found\n";
        return -1;
    }

}

int jumpSearch(int* arr, int key,unsigned int size) {
    std::cout << "\n\t\tCall algorithm jumpSearch\n";
	int jump = sqrt(size);
	int start = 0;
	int end = start + jump;

    while (end < size && arr[end] <= key) {
   		start = end;
      	end += jump;

      	if(end > size - 1) {
       		end = size;
        }

    }

    for(int i = start; i<end; i++) {

        if(arr[i] == key) {
       	    std:: cout << "\nFound in index -> ";
     	    return i;
        }
    }
    std:: cout << "\nValue not found\n";
    return -1;
}


int linearSearch(int* arr, int key, unsigned int  size) {
    std::cout << "\n\t\tCall algorithm linearSearch\n";
    int it = 0;
    if (arr[it] == key) {
        std:: cout << "\nFound in index -> ";
        return it;
    }

    if (arr[size - 1] == key) {
        std:: cout << "\nFound in index -> ";
        return size - 1;
    }

    while (arr[it] != key && it < size) {
        ++it;
    }
    if (arr[it] == key) {
        std:: cout << "\nFound in index -> ";
        return it;
    }
    std:: cout << "\nValue not found\n";
    return -1;
}

int binarySearch(int* arr,int key, int left, int right) {
    std::cout << "\n\t\tCall algorithm binarySearch\n";
    if (right >= left) {

        if (arr[left] == key) {
            std:: cout << "\nFound in index -> ";
            return left;
        }

        if (arr[right] == key) {
            std:: cout << "\nFound in index -> ";
            return right;
        }

        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            std:: cout << "\nFound in index -> ";
            return mid;
        }

        if (arr[mid] < key) {
            return binarySearch(arr, key, left, mid - 1);
        }

        return binarySearch(arr, key, mid + 1, right);

    }
    std:: cout << "\nValue not found\n";
    return -1;
}

void shellSort(int* array, unsigned int sizeArr) {
    int j =0;
    int i = 0;
    int end = 0;
    for (i = sizeArr/2; i > 0; i = i/2) {
        for (j = i; j < sizeArr; ++j) {
            end = j;
            while (array[end - i] > array[end] && end - i >= 0) {
                swap(array[end - i], array[end]);
                end = end - i;
            }
        }
    }
}

void printArray(int* array,unsigned int size){
    std::cout << "\n\t\t================== print array ================\n";
    unsigned int i = 0;
    while (i < size) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
        ++i;
    }

}

void swap(int& indexNumOne, int& indexNumTwo) {
    int temp = 0;
    temp = indexNumOne;
    indexNumOne = indexNumTwo;
    indexNumTwo = temp;
}

int* inputArray(unsigned int size) {
    std::cout << "\n\t\tInput array elements, please\n";
    int* tempArray = new int[size];
    int number = 0;
    for (unsigned int i = 0; i < size; ++i) {
        while (true) {
            std::cout << "array[" << i << "] = ";
            std::cin >> number;
            tempArray[i] = number;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
            } else {
                std::cin.ignore(32767, '\n');
            break;
            }
        }
    }
    return tempArray;
}

int algorithm(int* arr, int choice, unsigned int size) {
    int key = 0;
     while (true) {
        std::cout << "\nEnter the integer number you are looking for -> ";
        std::cin >> key;
         if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "\nThat input is invalid.  Please try again.!!!!" << std::endl;
        }
        else {
            std::cin.ignore(32767,'\n');
            break;
        }
    }

    switch (choice) {
    case 0:
        std::cout << linearSearch(arr, key, size) ;
        break;
    case 1:
        std::cout << binarySearch(arr, key, 0, size - 1);
        break;
    case 2:
        std::cout << jumpSearch(arr, key, size);
        break;
    case 3:
        std::cout << interpolationSearch (arr, key, size);
    case 4:
        std::cout<< exponentialSearch(arr, key, 0, size);
        break;
    case 5:
        std::cout<< ternarySearch(arr, key, 0, size);
        break;
    default:
        std::cout<< "\n\t\tThere is no such algorithm in my file\t";
        break;
    }
}
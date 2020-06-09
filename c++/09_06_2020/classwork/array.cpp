#include <iostream>

void printElementArr(int arr[], int index,int length) {
    if(index < 0) {
        throw 0;
    } else if(index >= length) {
        throw  length - 1;
    }
    std::cout << arr[index] << std::endl;
}

int main() {
    int i = 3000;
    int arr[] = {15, 25, 35, 45, 55};
    int size = 5;

    //std::cout << arr[3000];

    /*
    If you want to see the built-in Exeptions,
    you can remove the following line from the comment.
    */
    try {
        printElementArr(arr, i, size);
    }
    catch(int ex) {
        if(0 == ex) {
            std::cout << arr[ex] << std::endl; // print 15
        } else {
            std::cout << arr[ex] << std::endl; // print 55
        }
    }
    return 0;
}
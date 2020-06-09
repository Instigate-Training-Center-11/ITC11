#include <iostream>
#include<cstdlib>
#include<ctime>

unsigned int SIZE = 10;

int getByIndex(int* arr,int index) {
    if (index < 0) {
        throw arr[0];
    }
    if(index >= SIZE) {
        throw arr[SIZE - 1];
    } else {
        return arr[index];
    }

}


int main() {

    int arr[SIZE]{0};
    int value = 0;
    int index = 0;
    srand(time(NULL));
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
    }
    for(int i = 0; i < SIZE; ++i) {
        std::cout << "arr[" << i << "]" <<arr[i] << std::endl;
    }
    std::cout << "Enter index array ";
    std::cin >> index;
    try {
        value = getByIndex(arr,index);
        std::cout << value << std::endl;
    } catch (int value) {
        std::cout<<"catch  resolt -> ";
        std::cerr << value << std::endl;
    }

    return 0;
}
#include <iostream>

void reverse(char str[], int size) {
    for (int i = 0, j = size - 1; i < size / 2; ++i, --j) {
        str[i] ^= str[j] ^= str[i] ^= str[j];
    }
}

void print(char str[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

int get_size(char str[], int size) {
    for ( ; ; ++size) {
        if (str[size] == '\0') {
            return size;
        }
    }
}
int main() {
    char str[150];

    std::cout << "Please insert string : ";
    std::cin.getline(str, 150);

    int size = get_size(str, 0);

    reverse(str, size);

    print(str, size);
}


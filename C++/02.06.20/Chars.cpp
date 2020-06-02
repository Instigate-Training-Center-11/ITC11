#include <iostream>

/* Do revers for char array */
void revers(char[], int);

/* Print the array */
void print(char[], int);

/* Get the size of array */
int get_size(char[], int);

int main() {
    char str[250];

    std::cout << "Please insert string : ";
    std::cin.getline(str, 250);

    int size = get_size(str, 0);

    revers(str, size);

    print(str, size);
}

void revers(char str[], int size) {
    for (int i = 0, j = size - 1; i < size / 2; ++i, --j) {
        /* swap the values, not using temp value */
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
#include <iostream>

char *reverseString (char *str) {
    int size = 0;
    /*Get the size of string*/
    while (str[size] != '\0') {
        size++;
    }
    /*Reversed the string*/
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            char tmp = str[j];
            str[j] = str[j + 1];
            str[j + 1] = tmp;
        }
    }
    return str;
}
int main () {
    char str[50];
    std::cout << "Enter the string" << std::endl;
    std::cin.getline(str, 50, '\n');
    std::cout << "Entered string: " << str << std::endl;
    std::cout << "Outputed string: " << reverseString(str) << std::endl;
    return 0;
}


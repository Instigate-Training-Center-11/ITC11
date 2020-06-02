#include <iostream>

/* This function will reverse the string in the argument. */
void reverse(char *buf) {
    if (*buf) {
        reverse(buf + 1);
        std::cout << *buf;
    }
}

int main() {
    const int MAX = 1000;
    char str[MAX];
    std::cout << "Enter your string: ";

    /* Enter the string, which will be reversed. */
    std::cin.getline(str, MAX);
    std::cout << "Reversed string is: ";
    reverse(str);
    std::cout << "\n";
    std::cout << "Original string is: " << str << "\n";
    return 0;
}


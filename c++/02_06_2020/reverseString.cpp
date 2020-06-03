#include <iostream>

/* function  declaration reverseString, gets the argument string and will do reversed */
void reverseString(char* str);

int main() {
    const int SIZE = 200;
    char arr[SIZE];

    std::cout << "Please, enter your text: ";

    /* input text passed in array (arr) */
    std::cin.getline(arr, SIZE);
    char *text = arr;
    std::cout << "\n\t\tInput string\n" <<text << std::endl;
    /* call function reverseString */
    reverseString(text);
    std::cout << "\t\tReversed string\n" << text << std::endl;

    return 0;
}

/* implementation reverseString, gets the argument string and will do reversed */
void reverseString(char* str) {
    int length = 0;
    /* gets the number of characters in a string */
    while (str[length] != '\0') {
        ++length;
    }
    for (int i = 0, j = length - 1; i < length/2; ++i, --j) {
        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
    }
}
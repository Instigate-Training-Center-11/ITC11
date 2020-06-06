#include <iostream>

char* reverse(char*, int);
void swap(char&, char&);

int main() {
    int max = 1000;

    /* input string */
    char input[max];
    std::cout << "Enter a string: ";
    std::cin.getline(input, max);

    /* following is for counting the length of string */
    int length = 0;
    int i = 0;
    while (input[i] != '\0') {
        length = i;
        ++i;
    }

    /* print out inputted string and its reversed version */
    std::cout << "Inputed string: " << input << std::endl;
    std::cout << "Reversed string: " << reverse(input, length) << std::endl;
}

/* swap is a function which will swap two variables location */
void swap(char& var1, char& var2) {
    char temp = var1;
    var1 = var2;
    var2 = temp;
}

/* reverse is a function which will reverse inputted string by calling swap function,
if there is spaces in input, function will miss them */
char* reverse(char* input, int length) {
    for (int i = 0, j = length; i < length / 2; ++i, --j) {
        if (input[i] != 0) {
            swap(input[i], input[j]);
        } else {
            swap(input[i+1], input[j]);
        }
    }
    return input;
}
#include <iostream>
    
/* Definition of functions */
void printLine(int, int);

int main() {
    /* Get size of triangle's side */
    int size = 0;
    while (size < 1) {
        std::cout << "Enter side size: ";
        std::cin >> size;
    }

    /* Show triangle */
    for (int i = 0; i < size; ++i) {
        printLine(i, size);
        std::cout << std::endl;
    }
    return 0;
}

/*
 Function print the line
 Arguments:
  line: what kind of line to print
  size: size of line
*/
void printLine(int line, int size) {
    if (0 == line) {
        for (int i = 0; i < size; ++i) {
            std::cout << "* ";
        }
    } else if (size == line + 1) {
	for (int i = 0; i < line - 1; ++i) {
            std::cout << " ";
        }
        std::cout << " *";
    } else {
        for (int i = 0; i < line; ++i) {
            std::cout << " ";
        }
        std::cout << "*";`

        int second = 2 * (size - line) - 3;
        for (int i = 0; i < second; ++i) {
            std::cout << " ";
        }
        std::cout << "*";
    }
}

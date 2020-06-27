#include <iostream>

#include "tree.h"
#include "tree.cpp"

/* function prototype */
void MenuForChoise();

int main() {
    Tree<int> *bst = new Tree<int>();

    MenuForChoise();

	int userChoise = 0;
	int userInput = 0;

    do
	{
		std::cout << "\nPlease, choose an action for stack: ";
		std::cin >> userChoise;

		switch(userChoise)
		{
			case 1:
				std::cout << "Enter a value: ";
				std::cin >> userInput;
				bst->insert(userInput);
				break;

			case 2:
				std::cout << "Enter a value: ";
				std::cin >> userInput;
				bst->remove(userInput);
				break;

			case 3:
				bst->print();
				break;

			case 4:
				std::cout << "Exit" << std::endl << std::endl;
				break;

			default:
				std::cout << "Wrong function choise." << std::endl;
				break;
		}

	} while (userChoise != 4);


    return 0;
}

void MenuForChoise()
{
	std::cout << "1. Insert a node." << std::endl;
	std::cout << "2. Remove a node" << std::endl;
	std::cout << "3. Print Tree" << std::endl;
	std::cout << "4. EXIT" << std::endl;

	std::cout << std::endl;
}
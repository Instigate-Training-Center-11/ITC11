#include <iostream>

#include "stack.h"
#include "stack.cpp"

/* function prototype which contains actions list for user */
void stackFunction();

int main()
{
	stack<int> myStack;

	stackFunction();

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
				myStack.push(userInput);
				myStack.print();
				break;

			case 2:
				myStack.pop();
				myStack.print();
				break;

			case 3:
				if (myStack.empty())
				{
					std::cout << "Stack is empty" << std::endl;
					//return 0;
				}
				else
				{
					std::cout << "Top element: " << myStack.top() << std::endl;
				}
				break;

			case 4:
				if (myStack.empty() == true)
				{
					std::cout << "Stack is empty." << std::endl;
				}
				else
				{
					std::cout << "Stack is not empty." << std::endl;					
				}
				break;

			case 5:
				std::cout << "Size: " << myStack.size() << std::endl;
				break;

			case 6:
				myStack.print();
				break;

			case 7:
				std::cout << "Exit" << std::endl << std::endl;
				break;

			default:
				std::cout << "Wrong function choise." << std::endl;
				break;
		}

	} while (userChoise != 7);

	return 0;
}

void stackFunction()
{
	std::cout << "1. Push   /add data/" << std::endl;
	std::cout << "2. Pop    /delete last added data" << std::endl;
	std::cout << "3. Top    /get last added data/" << std::endl;
	std::cout << "4. Empty  /check whether stack is empty or not" << std::endl;
	std::cout << "5. Size   /desplay size of stack/" << std::endl;
	std::cout << "6. Print  /desplay stack content/" << std::endl;
	std::cout << "7. Exit " << std::endl;

	std::cout << std::endl;
}
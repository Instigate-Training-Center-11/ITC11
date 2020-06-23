#include<iostream>

#include<string>

#include "Stack.h"

int main() {
  Stack st;
  int option, postion, value;

  do {
    std::cout << "We have some operators. Please enter the number 1-7" << std::endl;

    std::cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      std::cout << "Enter an value to push in the stack" << std::endl;
      std::cin >> value;
      st.push(value);
      break;
    case 2:
      std::cout << "Poped value: " << st.pop() << std::endl;
      break;
    case 3:
      if (st.isEmpty())
        std::cout << "Stack is Empty" << std::endl;
      else
        std::cout << "Stack is not Empty" << std::endl;
      break;
    case 4:
      if (st.isFull())
        std::cout << "Stack is Full" << std::endl;
      else
        std::cout << "It is not Full" << std::endl;
      break;
    case 5:
      std::cout << "Enter position of item you want to peek: " << std::endl;
      std::cin >> postion;
      std::cout << "Value at position " << postion << " is " << st.peek(postion) << std::endl;
      break;
    case 6:
      std::cout << "Number of Items in the Stack are: " << st.size() << std::endl;
      break;
    case 7:
      std::cout << "All values: " << std::endl;
      st.display();
      break;
    default:
      std::cout << "Enter the Option number " << std::endl;
    }

  } while (option != 0);

  return 0;
}
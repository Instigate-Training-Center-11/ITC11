#include <iostream>

#include "stack.h"

/* default constructor of stack class */
template <typename T>
stack<T>::stack(){
	header = 0;
	length = 0;
}

/* destructor of stack class */
template <typename T>
stack<T>::~stack(){
	while (0 != header)
	{
		pop();
	}
}

/* add an element into stack, but before that check if stack is full or not */
template <typename T>
void stack<T>::push(const T value)
{
	if (header == (maxSize))
	{
		std::cout << "Stack Overflow" << std::endl;
		std::cout << "Max number of elementw must be 100" << std::endl;
	}
	else
	{
		content[++header] = value;
		length++;
	}
}

/* delete last edded element from stack */
template <typename T>
T stack<T>::pop()
{
	if (empty())
	{
		std::cout << "Stack is empty" << std::endl;
	}
	else
	{
		length--;
		return content[(header--)];
	}

}

/* desplay top element (last added element) of stack */
template <typename T>
T stack<T>::top()
{
	return content[header];
}

/* get count of stack content */
template <typename T>
int stack<T>::size()
{
	return length;
}

/* check if stack is empty or not */
template <typename T>
bool stack<T>::empty() const{
	if(header == 0){
		return true;
	}else{
		return false;
	}
}

/* desplay stack contents */
template <typename T>
void stack<T>::print()
{
	std::cout << "\n***** Stack content: ";
	for (size_type i = 1; i <= header; ++i)
	{
		std::cout << content[i] << " ";
	}

	std::cout << std::endl;
}
#ifndef STACK_H
#define STACK_H

#include <array>
#include <iostream>

/* max number of elements of stack */
#define maxSize 100

template<typename T> 
class stack{
	public:
		/* following will return number of elements in the comntainer */
		typedef typename std::array<T, maxSize>::size_type size_type;

		stack();
		~stack();
		void push(const T);
		T pop();
		T top();
		bool empty() const;
		int size ();
		void print();

	private:
		std::array<T, maxSize> content;
		size_type header;
		int length;
};
#endif
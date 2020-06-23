#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
	Stack();
	Stack(int count, T data);
	Stack(Stack<T> *stack);
	~Stack();
	void push(const T& data);
	int getSize() const;
	bool empty() const;
	T pop();
	T top();
private:
	template <class N>
	class Node {
	public:
		Node<N> *pNext;
		Node<N> *pPrev;
		N data;
		Node(N data = N(), Node<N> *pNext = NULL, Node<N> *pPrev = NULL) {
			this -> data = data;
			this -> pNext = pNext;
			this -> pPrev = pPrev;
		}
	};
	int size;	
	Node<T> *head;
	Node<T> *tail;
	void removeHead();
	void clear();
};

template <class T>
Stack<T>::Stack() {
	size = 0;
	head = NULL;
	tail = NULL;
}

template <class T>
Stack<T>::Stack(int count, T data) {
	size = count;
	head = NULL;
	tail = NULL;
	for(int i = 0; i < count; ++i) {
		push(data);
	}
}

template <class T>
Stack<T>::Stack(Stack<T> *stack) {
        size = stack -> getSize();
        head = NULL;
        tail = NULL;
        for(int i = 0; i < size; ++i) {
                push(stack -> pop());
		cout << "-" << endl;
        }
}

template <class T>
Stack<T>::~Stack() {
	clear();
}

template <class T>
int Stack<T>::getSize() const {
	return size;
}

template <class T>
bool Stack<T>::empty() const {
	return size != 0;
}

template <class T>
void Stack<T>::push(const T& data) {
	if(head == NULL) {
		head = new Node<T>(data);
		tail = head;
	} else {
		Node<T> *temp = tail;
		tail -> pNext = new Node<T>(data);
		tail = tail -> pNext;
		tail -> pPrev = temp;
	}
	size++;
}

template <class T>
void Stack<T>::removeHead() {
	if(head != NULL) {
		Node<T> *temp =head;
		head = head -> pNext;
		delete temp;
		size--;
	}
}

template <class T>
void Stack<T>::clear() {
	while(size) {
		removeHead();
	}
}

template <class T>
T Stack<T>::pop() {
	Node<T> *current = this -> tail;
	tail = tail -> pPrev;
	--size;
	return current -> data;
}

template <class T>
T Stack<T>::top() {
        return tail -> data;
}

int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	cout << "stack top:" << stack.top() << endl;
	cout << "size :" << stack.getSize() << endl;
	for(int i = 0; i < 4; ++i) {
		cout << stack.pop() << endl;
	}
	cout << "empty :" << stack.empty() << endl;

	Stack<int> *st = new Stack<int>(4, 5);
	for(int i = 0; i < 4; ++i) {
		cout << st -> pop() << endl;
	}

	Stack<int> s(st);// = new Stack<int>(st);
	for(int i = 0; i < 4; ++i) {
		cout << s.pop() << endl;
	}
	return 0;
}

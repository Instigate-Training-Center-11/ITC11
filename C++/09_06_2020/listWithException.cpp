#include <iostream>

class MyException {
	std::string str;
	public:
	MyException(std::string str) {
		this -> str = str;
	}
	void toString() {
		std::cout << str << std::endl;
	}
};

class MyExceptionExtendsStdException : std::exception {
        std::string str;
        public:
        MyExceptionExtendsStdException(std::string str) {
                this -> str = str;
        }
        void toString() {
                std::cout << str << std::endl;
        }
};

template <class N>
class Node {
        public:
                Node<N> *pNext;
                N data;
                Node(N data = N(), Node<N> *pNext = NULL) {
                        this -> data = data;
                        this -> pNext = pNext;
                }
};

template <class T>
class List {
public:
	List();
	~List();
	void push_back(T data);
	void push_front(T data);
	int get_size() {
		return size;
	}
	T &operator[](const int index);
	void operator<<(List<T>);
	friend std::ostream& operator<<(std::ostream& os, const List<T>& list);
	void insert(int index, T data);
	void clear();
	T pop_front();
	T pop_back();
	void print();
private:
	int size;	
	Node<T> *head;
	Node<T> *tail;
	void remove_head();
};


template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list)
{
        for(int i = 0; i < list.get_size(); ++i) {
                os << list.pop_front() << '\n';
        }
	return os;
}

template <class T>
List<T>::List() {
	size = 0;
	head = NULL;
	tail = NULL;
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
void List<T>::push_back(T data) {
	if(head == NULL) {
		head = new Node<T>(data);
		tail = head;
	} else {
		tail -> pNext = new Node<T>(data);
		tail = tail -> pNext;
	}
	size++;
}

template <class T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	size++;
}

template <class T>
void List<T>::operator<<(List<T>) {
	print();
}


template <class T>
T& List<T>::operator[](const int index) {
	if(index < 0) {
		//MyException e("IndexOutOfBoundsException");
		throw new MyException("IndexOutOfBoundsException");
		//std::cout << "IndexOutOfBoundsException" << std::endl;
		//return NULL;
	}
	int counter = 0;
	Node<T> *current = this -> head;
	
	while(current != NULL) {
		if(counter == index) {
			return current -> data;	
		}
		current = current -> pNext;
		counter++;
	}
}

template <class T>
void List<T>::insert(int index, T data) {
	Node<T> *current = this -> head;
	if(index == 0) {
		head = new Node<T>(data, head);
	} else {
		for(int counter = 0;counter != index - 1; ++counter) {
			current = current -> pNext;
		}
		current -> pNext = new Node<T>(data, current -> pNext);
	}
	size++;
}

template <class T>
void List<T>::remove_head() {
	if(head != NULL) {
		Node<T> *temp =head;
		head = head -> pNext;
		delete temp;
		size--;
	}
}

template <class T>
void List<T>::clear() {
	while(size) {
		remove_head();
	}
}

template <class T>
T List<T>::pop_front() {
	if(head != NULL) {
		Node<T> *temp = head;
		head = head -> pNext;
		size--;
		return temp -> data;
	}
}

template <class T>
T List<T>::pop_back() {
	Node<T> *current = this -> head;
	for (int counter = 0; counter < (this -> size - 1); ++counter) {
		current = current -> pNext;
	}
	return current -> data;
}

template <class T>
void List<T>::print() {
	Node<T> *temp = this -> head;
	for(int i = 0; i < size; ++i) {
		std::cout << temp -> data << std::endl;
		temp = temp -> pNext;
	}
}

template <class T>
class Queue : private List<T> {
	public:
		T pop();
		void push(T data);
		int getSize();
		void toString();
};

template <class T>
void Queue<T>::push(T data) {
	push_back(data);
}

template <class T>
T Queue<T>::pop() {
	if(get_size() == 0) {
		throw new MyExceptionExtendsStdException("NoElementInQueue");
	}
	pop_front();
}

template <class T>
int Queue<T>::getSize() {
	get_size();
}

template <class T>
void Queue<T>::toString() {
	print();
}


int main() {
	try {
	Queue<int> que;
	que.push(1);
	std::cout << que.pop() << std::endl;
	std::cout << que.pop() << std::endl;
	}
	catch(MyExceptionExtendsStdException *e) {
		e -> toString();
	}

	try {
		List<double> list;
		list.push_back(3);
		std::cout << list[-1] << std::endl;
		//with problems
		//std::cout << list;
		list<<list;
	}
	catch(MyException *e) {
		e -> toString();
	}
	catch( ... ) {
		std::cout << "Exception" << std::endl;
	}
	return 0;
}

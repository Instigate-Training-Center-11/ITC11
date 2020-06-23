#include <iostream>
using namespace std;

template <class T>
class List;

template <typename T>
class Iterator {
	int size;
	List<T>* obj;
public:
	Iterator(List<T>* object) {
		obj = object;
		size = 0;
	}

	bool hasNext() {
		return obj -> getSize() > size;
	}

	Iterator<T>* next() {
		++size;
		return this;
	}

	T getValue() {
		return (*obj)[size];
	}


	Iterator& operator++() {
		size++;
		return *this;
	}

	Iterator& operator--() {
		size--;
		return *this;
	}

	Iterator& operator++(int) {
		Iterator temp = *this;
		++(*this);
		return temp;
	}

	Iterator& operator--(int) {
		Iterator temp = *this;
		--(*this);
		return temp;
	}
};


template <class T>
class List {
public:
	List();
	~List();
	void pushBack(const T& data);
	void pushFront(const T& data);
	int getSize() const;
	bool empty() const;
	T &operator[](const int index);
	void insert(int index, T data);
	void clear();
	T popFront();
	T popBack();
	void toString();
	Iterator<T> getIterator();
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
};

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
Iterator<T> List<T>::getIterator() {
	Iterator<T> iter(this);
	return iter;
}

template <class T>
int List<T>::getSize() const {
	return size;
}

template <class T>
bool List<T>::empty() const {
	return size != 0;
}

template <class T>
void List<T>::pushBack(const T& data) {
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
void List<T>::pushFront(const T& data) {
	if(head == NULL) {
		head = new Node<T>(data);
		tail = head;
	} else {
		Node<T> *temp = new Node<T>(data, head);
		head -> pPrev = temp;
		head = temp;
	}
	size++;
}

template <class T>
T& List<T>::operator[](const int index) {
	int counter = 0;
	if(index < size / 2) {
		Node<T> *current = this -> head;
		while(current != NULL) {
			if(counter == index) {
				return current -> data;	
			}
			current = current -> pNext;
			counter++;
		}
	} else {
		int temp =size - index - 1;
		Node<T> *current = this -> tail;
		while(current != NULL) {
			if(counter == temp) {
				return current -> data;
			}
			current = current -> pPrev;
			counter++;
		}
	}
}

template <class T>
void List<T>::insert(int index, T data) {
	if(index == 0) {
		head = new Node<T>(data);
		tail = head;
	} 
	
	if(index < size / 2) {
		Node<T> *current = this -> head;
		for(int counter = 0; counter != index - 1; ++counter) {
			current = current -> pNext;
			cout << counter << endl;
		}
		current -> pNext = new Node<T>(data, current -> pNext);
		current -> pNext -> pPrev = current;
		current -> pNext -> pNext -> pPrev = current -> pNext;
	} else {
		Node<T> *current = this -> tail;
		for(int counter = 0; counter != size - index; ++counter) {
			current = current -> pPrev;
		}
		current -> pNext = new Node<T>(data, current -> pNext);
		current -> pNext -> pPrev = current;
		current -> pNext -> pNext -> pPrev = current -> pNext;
	}
	size++;
}

template <class T>
void List<T>::removeHead() {
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
		removeHead();
	}
}

template <class T>
T List<T>::popFront() {
	if(head != NULL) {
		Node<T> *temp = head;
		head = head -> pNext;
		--size;
		return temp -> data;
	}
}

template <class T>
T List<T>::popBack() {
	Node<T> *current = this -> tail;
	tail = tail -> pPrev;
	--size;
	return current -> data;
}

template <class T>
void List<T>::toString() {
	Node<T> *temp = this -> head;
	for(int i = 0; i < size; ++i) {
		std::cout << temp -> data << std::endl;
		temp = temp -> pNext;
	}
}

int main() {
	List<int> list;
	list.pushFront(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushBack(4);
	list.insert(1, 11);
	list.insert(3, 33);
	list.toString();
	cout << "----------------0, 1, & 2 elements" << endl;
	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[2] << endl;
	cout << "----------------popFront() & popBack()" << endl;
	cout << list.popFront() << endl;
	cout << list.popBack() << endl;
	cout << "------------iter" << endl;
	Iterator<int> iter = list.getIterator();
	do {
		cout << iter.getValue() << " ";
		iter.next();
	} while(iter.hasNext());
        cout << endl;
	cout << "---------++itr & itr++" << endl;
	Iterator<int> itr = list.getIterator();
	++itr;
	itr++;
	cout << itr.getValue() << endl;

	return 0;
}

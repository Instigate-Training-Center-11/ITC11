#include <iostream>

template<class T>
struct node {
	node<T>* next;
	T data;
};

template<class T>
class LinkedList
{
public:
	node<T>* first;
	node<T>* last;
	LinkedList<T>() {
		first = NULL;
		last = NULL;
	}

	void add(T data) {
		if(!first) {
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		} else {
			if(last == first) {
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			} else {
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
	}
    
	T get(int index) {
		if(index == 0) {
			return this->first->data;
		} else {
			node<T>* curr = this->first;
			for(int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->data;
		}
	}

	T operator[](int index) {
		return get(index);
	}

};

int main(int argc, char const *argv[])
{
	LinkedList<std::string> list;
	list.add("Hello");
	list.add("World");
	std::cout << list[1] << std::endl;
	return 0;
}
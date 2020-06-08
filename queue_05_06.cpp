#include <iostream>

class Node {
    public:
        int data;
        Node* next;
};
//Base class․
class linked_list {
    private:
	    int size;
		
    public:
		Node* head;
		int get_size();
		linked_list();
		~linked_list();
		void delete_list();
		void print();
        void add(int);
        int get_element(Node *, int);
};
//default constructor.
linked_list::linked_list() {
    this->size = 0;
    this->head = NULL;
};

//delete list begining first element.
void linked_list::delete_list() {
     while (size != 0) {
		delete head;
		size--;
	}
};

//default destructor.
linked_list::~linked_list() {
    delete_list();
	std::cout << "List deleted" << std::endl;
}

int linked_list::get_size() {
    return size;
}
//add elements in linked list.
void linked_list::add(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->size++;
}

void linked_list::print() {
    Node* head = this->head;
    int i = 1;
    while(head) {
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

//geting element by your index.
int linked_list::get_element(Node* head, int index) {  
    if (index <= size) {
		Node* current = this->head;
        int count = 1;
        while (current != NULL) {
             if (count == index) {
                 return current->data;
             }
             count++;
		     current = current->next;
        }
    } else {
		//for non-existent element.
	    std::cout << "There isn't element by " << index << " index" << std::endl;
	}
}
//Derived class․
class Queue : private linked_list {
    public:
        Node* head;
        void add_q(int);
        void print_q();
        int get_size_q();
        int get_element_q(Node*, int);
};

void Queue::add_q(int data) {
	add(data);
}
void Queue::print_q() {
	print();
}

int Queue::get_size_q() {
	return get_size();
}

int Queue::get_element_q(Node* head, int index) {
    return get_element(head, index);
}

int main() {
    Queue list;

	//using for loop quickly make the list(add list elements).
    for (int i = 20; i >= 1; --i) {
        list.add_q(i);
    }

	//show the list on monitor.
    list.print_q();

	//print list size.
    std::cout << "List size: " << list.get_size_q() << std::endl;

	//get N-th element of list.
	std::cout << "5th element of list: " << list.get_element_q(list.head, 5) << std::endl;
    std::cout << "22th element of list: " << list.get_element_q(list.head, 15) << std::endl;
    system("pause");
    return 0;
}
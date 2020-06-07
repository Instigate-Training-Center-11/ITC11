#include <iostream>
#include <assert.h>

class Node {
    public:
        int data;
        Node* next;
};

class linked_list {
    public:
        int size;
        Node* head;

        linked_list();
        void add(int);
        void delete_list();
        void print();
        int get_element(Node*, int);
        int delete_element(int);
        ~linked_list();
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
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == index) {
            return current->data;
        }
        count++;
        current = current->next;
    }
    //for non-existent element
    assert(1);
}

int main() {
    linked_list list;

	//using for loop quickly make the list(add list elements).
    for (int i = 20; i >= 1; --i) {
        list.add(i);
    }
	//show the list on monitor.
    list.print();

	//print list size.
    std::cout << "List size: " << list.size << std::endl;

	//get N-th element of list.
    std::cout << "5th element of list: " << list.get_element(list.head, 5) << std::endl;
    system("pause");
    return 0;
}
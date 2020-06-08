#include <iostream>
#include "list.hpp"

List::List() {
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
}

List::List(int size, int value) {
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
    for (int i = 0; i < size; ++i) {
        push_back(value);
    }
}

List::~List() {
    clear();
}

int List::get_size() const {
     return size;
}

void List::clear() {
    while (size) {
        pop_front();
    }
}

int List::get_at_index(int index) const {
    if (index > size || index < 0) {
        std::cout << "get_at_index(int >>> " << index << " <<<)...error.";
        return ERROR_101;
    }

    Node* tmp = head;

    for (int i = 0; i < index; ++i) {
        tmp = tmp -> next;
    }
    return tmp -> value;
}

void List::set_at_index(int value, int index) {
    if (index > size || index < 0) {
        std::cout << "set_at_index(int >>> " << index << " <<<)...error." << ERROR_101 << std::endl;
        return;
    }

    Node* tmp = head;

    for (int i = 0; i < index; ++i) {
        tmp = tmp -> next;
    }
    tmp -> value = value;
}

void List::remove_at_index(int index) {
    if (index > size || index < 0) {
        std::cout << "remove_at_index(int >>> " << index << " <<<)...error." << ERROR_101 << std::endl;
        return;
    }

    if (index == 0) {
	    pop_front();
    }
    else {
	    Node *tmp = head;
	    for (int i = 0; i < index - 1; i++) {
		    tmp = tmp -> next;
        }
	    Node *Node_Delete = tmp -> next;
	    tmp -> next = Node_Delete -> next;
	    delete Node_Delete;
	    --size;
    }
}

void List::push_back(int value) {
    if (size == 0) {
        head = new Node(value);
        tail = head;
    } else {
        Node* tmp  = head;
        while (tmp -> next != nullptr) {
            tmp = tmp -> next;
        }
        tmp -> next = new Node(value);
        tail = tmp;
    }
    ++size;
}

void List::push_front(int value) {
    head = new Node(value, head);
    ++size;
}

void List::pop_back() {
    if (size == 0) {
        std::cout << "pop_back()...size = " << size << "...list is empty: error." << ERROR_202 << std::endl;
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < size - 2; ++i) {
        tmp = tmp -> next;
    }

    delete tmp -> next;
    tmp -> next = nullptr;
    --size;
}

void List::pop_front() {
    if (size == 0) {
        std::cout << "pop_front()...size = " << size << "...list is empty: error." << ERROR_202 << std::endl;
        return;
    }

    Node* tmp = head;
    head = head -> next;
    delete tmp;
    --size;
}

int List::get_max() const {
    if (size == 0) {
        std::cout << "list_max()...size = " << size << "...list is empty.";
        return ERROR_202;
    }

    Node* tmp = head;
    int max = head -> value;

    for (int i = 0; i < size; ++i) {
        if (tmp -> value > max) {
            max = tmp -> value;
        }
        tmp = tmp -> next;
    }
    return max;
}

int List::get_min() const {
    if (size == 0) {
        std::cout << "list_min()...size = " << size << "...list is empty.";
        return ERROR_202;
    }

    Node* tmp = head;
    int min = head -> value;

    for (int i = 0; i < size; ++i) {
        if (tmp -> value < min) {
            min = tmp -> value;
        }
        tmp = tmp -> next;
    }
    return min;
}

void List::print() const {
    if (size == 0) {
        std::cout << "print()...size = " << size << "...list is empty: error." << ERROR_202 << std::endl;
        return;
    }

    Node* tmp = head;

    for (int i = 0; i < size; ++i) {
        std::cout << "value " << i << " = " << tmp -> value << std::endl;
        tmp = tmp -> next;
    }
    std::cout << std::endl;
}
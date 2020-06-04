#include <iostream>
#include "list.hpp"

List::List(void) {
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
}

int List::getSize(void) const {
    std::cout << "SIZE = " << this -> size << "\n";
    return this -> size;
}

void List::pushBack(int value) {
    if (size == 0) {
        Node* newNode = new Node();
        this -> head = newNode;
        this -> tail = newNode;
        newNode -> value = value;
        newNode -> next = nullptr;
        ++this -> size;
    } else {
        Node* temp = this -> head;
        int timer = 0;
        while (temp -> next != nullptr) {
            temp = temp -> next;
            ++timer;
        }
        Node* newNode = new Node();
        temp -> next = newNode;
        this -> tail = newNode;
        newNode -> next = nullptr;
        newNode -> value = value;
        ++this -> size;
    }
}

void List::setAtIndex(unsigned int index,int value) {
    if (index < 0) {
        return;
    } else if (index >= size && size != 0) {
        std::cout<< "Index must be smaller size" << "\n";
        return;
    }
    Node* temp = this -> head;
    for (int i = 0; i <= index; ++i) {
        temp = temp -> next;
    }
    temp -> value = value;
}

void List::removeAtIndex(unsigned index) {
    if (index < 0) {
        return;
    } else if (index >= size && size != 0) {
        std::cout << "Index must be smaller or equally  size" << "\n";
        return;
    } else if (this -> size == 0) {
        std::cout << "The list is empty" << "\n";
        return;
    }
    Node* temp = this -> head;
    if (size == 1) {
        delete head;
        this -> head = nullptr;
        this -> tail = nullptr;
        delete temp;
    } else if (size == 2 && index == 1) {
        temp = temp -> next;
        this -> tail = this -> head;
        delete temp;
    } else if (size == 2 && index == 0) {
        this -> head = this -> tail;
        delete temp;
    } else if (index == 0) {
        this -> head = this -> head -> next;
        delete temp;
    } else {
        for(int i = 0; i < index -1; ++i) {
            temp = temp -> next;
        }
        Node* tmp = temp -> next;
        temp -> next = tmp -> next;
        this -> tail = temp;
        delete tmp;
    }
    --this -> size;
}

void List::insertAtIndex(unsigned int index1,int value) {
    if (index1 < 0) {
        return;
    } else if (index1 > size && index1 != 0) {
        std::cout << "Index must be smaller or equally size" << "\n";
        return;
    } else if (index1 == size && index1 != 0) {
        this -> pushBack(value);
    } else if (index1 == 0 && size == 0) {
        Node* newNode = new Node();
        newNode -> value = value;
        this -> head = newNode;
        this -> tail = newNode;
        ++this -> size;
    } else {
        Node* temp = this -> head;
        for (int i = 0; i < index1; ++i) {
            temp = temp -> next;
        }
        Node* newNode = new Node();
        newNode -> next = temp -> next;
        temp -> next = newNode;
        newNode -> value = value;
        ++this -> size;
    }
}

int List::operator[](unsigned int index) const {
    if (index < 0) {
        return 0;
    } else if (index > size && index != 0) {
        std::cout << "Index must be smaller or equally size," << "\n";
        return 0;
    }
    Node* temp = this -> head;
    for (int i = 0; i < index; ++i) {
        temp = temp -> next;
    }
    std::cout << temp -> value << "\n";
}

void List::printList(void) {
    if(this -> size == 0) {
        std::cout << " The list is empty \n";
        return;
    }
    Node* temp = this -> head;
    int timer = 0;
    while (temp -> next != nullptr) {
        std::cout << "List Node[" << timer << "] = " << temp -> value << "\n";
        temp = temp -> next;
        ++timer;
    }
    std::cout << "List Node[" << timer << "] = " << temp -> value << "\n";
}

List::List(int countElements) {
    if (countElements == 0) {
        this -> head = nullptr;
        this -> tail = nullptr;
        this -> size = 0;
    }
    while (countElements != 0) {
        pushBack(0);
        --countElements;
    }
}

void List::popBack(void) {
    if(this -> size == 0) {
        std::cout << "the list is empty" << "\n";
        return;
    }
    Node* temp = this -> head;
    for(int i = 0; i < this -> size - 2; ++i) {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
    this -> tail = temp;
    --this -> size;
}

void List::clear(void) {
    while (this -> size != 0) {
        --this -> size;
        popBack();
    }
}
List::~List(void) {
}
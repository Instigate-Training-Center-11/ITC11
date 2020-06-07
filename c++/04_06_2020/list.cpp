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

List::List(int countElements) {
    if (countElements == 0) {
        this -> head = nullptr;
        this -> size = 0;
    }
    while (countElements != 0) {
        pushBack(0);
        --countElements;
    }
}

void List::pushBack(int value) {
    if (size == 0) {
        Node* newNode = new Node();
        this -> head = newNode;
        newNode -> value = value;
        newNode -> next = nullptr;
        ++this -> size;
    } else {
        Node* temp = this -> head;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }
        Node* newNode = new Node();
        temp -> next = newNode;
        newNode -> next = nullptr;
        newNode -> value = value;
        ++this -> size;
    }
}

void List::setAtIndex(unsigned int index,int value) {
    if (index == 0 && this->size == 0) {
        std::cout << " The list is empty \n";
        return;
    }
    if(index == 0 && this->size != 0) {
        this->head->value = value;
        return;
    }
    if (index < 0) {
        std::cout << "Negative index " << "\n";
        return;
    } else if (index >= size && size != 0) {
        std::cout<< "Index must be smaller size" << "\n";
        return;
    }
    Node* temp = this -> head;
    for (int i = 0; i < index; ++i) {
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
        delete temp;
        this->head = nullptr;
    } else if (size == 2 && index == 1) {
        temp = temp->next;
        delete temp;
    } else if (index == 0 && this->size > 1) {
        ++this->size;
        popFront();
    } else {
        for(int i = 1; i < index; ++i) {
            temp = temp->next;
        }
        Node* tmp = temp -> next;
        temp -> next = tmp -> next;
        this -> tail = temp;
        delete tmp;
        tmp = nullptr;
    }
    --this -> size;
}

void List::insertAtIndex(unsigned int index,int value) {
    if(index == 0 && size != 0) {
        Node* newNode = new Node();
        newNode->next = this->head->next;
        this->head->next = newNode;
        newNode->value =value;
        ++this->size;
        return;
    }
    if (index < 0) {
        std::cout << "Negative index " << "\n";
        return;
    } else if (index > size) {
        std::cout << "Index must be smaller or equally size" << "\n";
        return;
    } else if (index == size && index != 0) {
        this->pushBack(value);
    } else if (index == 0 && size == 0) {
        Node* newNode = new Node();
        newNode->value = value;
        this->head = newNode;
        newNode->next = nullptr;
        ++this->size;
    } else {
        Node* temp = this->head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        Node* newNode = new Node();
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->value = value;
        ++this->size;
    }
}

int List::operator[](unsigned int index) const {
    if(index == 0) {
        return head->value;
    }
    if (index < 0) {
        std::cout << "Negative index " << "\n";
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

void List::printList(void) const {
    if(this->size == 0) {
        std::cout << " The list is empty \n";
        return;
    }
    int index = 0;
    Node* temp = this->head;
    while (temp->next != nullptr) {
        std::cout << "List Node[" << index << "] = " << temp->value << "\n";
        temp = temp->next;
        ++index;
    }
    std::cout << "List Node[" << index << "] = " << temp->value << "\n";
}

void List::popFront(void) {
    if(this -> size == 0) {
        std::cout << "the list is empty" << "\n";
        return;
    }
    Node* temp = this->head->next;
    delete this->head;
    this->head = nullptr;
    this->head = temp;
    --this -> size;
}
void List::pushFront(int value) {
    if (this->size == 0) {
        Node* newNode = new Node();
        newNode->value = value;
        this->head = newNode;
        return;
    }
    Node* newNode = new Node();
    newNode->next = head;
    this->head = newNode;
    newNode->value =value;
    ++this->size;
}
void List::clear(void) {
    while (this -> size != 0) {
        --this -> size;
        popFront();
    }
}

List::~List(void) {
    clear();
}
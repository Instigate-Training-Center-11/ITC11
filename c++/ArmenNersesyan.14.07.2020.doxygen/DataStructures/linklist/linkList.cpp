#include <iostream>
#include "linkList.h"

template <typename Type>
auto DoubleList<Type>::insert(Iterator position, const Type& nodeValue) {
    if (position == nullptr) {
        return nullptr;
    }

    if (position == begin()) {
        pushFront(nodeValue);
        return nullptr;
    }

    if (position == end()) {
        pushBack(nodeValue);
        return nullptr;
    }

    Node* temp = head->Next;
    while (true) {
        if (position == temp) {
            Node* newNode = new Node();
            newNode->value = nodeValue;
            newNode->Next = temp->Next;
            temp->Next->Prev = newNode;
            temp->Next = newNode;
            newNode->Prev = temp;
            ++this->sizeList;
            return nullptr;
        }
        temp = temp->Next;
    }
}

template <typename Type>
auto DoubleList<Type>::erase(Iterator position) {
    if (position == nullptr) {
        return nullptr;
    }

    if (position == begin()) {
        popBack();
        return nullptr;
    }

    if (position == end()) {
        popBack();
        return nullptr;
    }

    Node* temp = head->Next;
    while (true) {
        if (position == temp) {
            temp->Prev->Next = temp->Next;
            temp->Next->Prev = temp->Prev;
            delete temp;
            --this->sizeList;
        }
        if (temp->Next == nullptr) {
            return nullptr;
        }
        temp = temp->Next;
    }
    return nullptr;
}

template <typename Type>
DoubleList<Type>& DoubleList<Type>::operator= (const DoubleList& object) {
    this->sizeList = 0;
    Node* temp1 = object.head;
    unsigned int size = object.size();
    while (size != 0) {
        pushBack(temp1->value);
        temp1 = temp1->Next;
        --size;
    }
    return *this;
}


template <typename Type>
void DoubleList<Type>::remove(const Type& nodeValue) {
    while (head->value == nodeValue || tail->value == nodeValue) {
        if (this->sizeList == 1) {
            popBack();
            return;
        }

        if (head->value == nodeValue) {
            popFront();
        }

        if (tail->value == nodeValue) {
            popBack();
        }

    }

    if (this->sizeList <= 2) {
        return;
    }

    Node* temp1 = nullptr;
    Node* nodeToDelete = head->Next;
    Node* temp2 = nullptr;
    while (nodeToDelete->Next != tail) {
        if (nodeToDelete->value == nodeValue) {
            temp1 = nodeToDelete->Prev;
            temp2 = nodeToDelete->Next;
            temp1->Next = temp2;
            temp2->Prev = temp1;
            nodeToDelete->Next = nullptr;
            nodeToDelete->Prev = nullptr;
            delete nodeToDelete;
            --this->sizeList;
            nodeToDelete = temp2;
        } else {
            nodeToDelete = nodeToDelete->Next;
        }
    }
}

template <typename Type>
void DoubleList<Type>::pushFront(Type NodeValue) {
    if (0 == this->sizeList) {
        Node* newNode = new Node();
        this->head = newNode;
        this->tail = newNode;
        newNode->Next = nullptr;
        newNode->Prev = nullptr;
        newNode->value = NodeValue;
        ++this->sizeList;
    } else {
        Node* newNode = new Node();
        newNode->value = NodeValue;
        newNode->Next = head;
        head->Prev = newNode;
        newNode->Prev = nullptr;
        head = newNode;
        ++this->sizeList;
    }
}

template <typename Type>
void DoubleList<Type>::popFront(void) {
    if (empty()) {
        return;
    }

    if (1 == this->sizeList) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --this->sizeList;
        return;
    }

    Node* temp1 = head;
    Node* nodeToDelete = temp1;
    temp1 = temp1->Next;
    temp1->Prev = nullptr;
    delete nodeToDelete;
    head = temp1;
    --this->sizeList;

}

template <typename Type>
unsigned int DoubleList<Type>::size(void) const {
    return this->sizeList;
}

template <typename Type>
bool DoubleList<Type>::empty(void) const{
    if (0 == this->sizeList) {
        std::cout << "The list is empty" << std:: endl;
        return true;
    } else {
        return false;
    }
}

template <typename Type>
void DoubleList<Type>::popBack(void) {
    if (empty()) {
        return;
    }

    if (1 == this->sizeList) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --this->sizeList;
        return;
    }

    Node* temp1 = tail;
    Node* nodeToDelete = temp1;
    temp1 = temp1->Prev;
    temp1->Next = nullptr;
    delete nodeToDelete;
    tail = temp1;
    --this->sizeList;

}

template <typename Type>
void DoubleList<Type>::print(void) const {
    Node* temp1 = this->head;
    while(!(temp1 == nullptr)) {
        std::cout << temp1->value << std::endl;
        temp1 = temp1->Next;
    }
}

template <typename Type>
void DoubleList<Type>::pushBack(Type NodeValue) {
    if (0 == this->sizeList) {
        Node* newNode = new Node();
        this->head = newNode;
        this->tail = newNode;
        newNode->Next = nullptr;
        newNode->Prev = nullptr;
        newNode->value = NodeValue;
        ++this->sizeList;
    } else {
        Node* newNode = new Node();
        newNode->value = NodeValue;
        newNode->Next = nullptr;
        newNode->Prev = tail;
        tail->Next = newNode;
        tail = newNode;
        ++this->sizeList;
    }
}

template <typename Type>
DoubleList<Type>::DoubleList(unsigned int countNode, Type NodeValue) {
    this->sizeList = 0;
        if (countNode == 0) {
            Node* newNode = new Node();
            newNode = nullptr;
        } else {
            while (countNode != 0) {
                pushBack(NodeValue);
                --countNode;
            }
        }
}

template <typename Type>
DoubleList<Type>::DoubleList(const DoubleList<Type> &object) {
    *this = object;
}

template <typename Type>
DoubleList<Type>::~DoubleList() {
    while (!empty()) {
        popBack();
    }
}
#include <iostream>
#include "list.hpp"
#include <thread>
#include <mutex>
#include <chrono>

template <typename Type>
List<Type>::List(void) {
    this->head = nullptr;
    this->size = 0;
}

template <typename Type>
unsigned int List<Type>::getSize(void) const {
    return this->size;
}

std::mutex m;
template <typename Type>
void List<Type>::deleteThread(unsigned int index) {
    m.lock();
    std::cout <<"thread removeAtIndex\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "threadId = " << this_id <<"\n";
    std::thread th(&List<Type>::removeAtIndex, this,index);
    m.unlock();
    th.join();
}

std::mutex t;
template <typename Type>
void List<Type>::insertAtIndexThread(unsigned int index, int value) {
    t.lock();
    std::cout <<"thread insertAtIndex\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "threadId = " << this_id <<"\n";
    std::thread th1(&List<Type>::insertAtIndex,this,index,value);
    t.unlock();
    th1.join();
}

template <typename Type>
List<Type>::List(int countElements) {
    if (0 == countElements) {
        this->head = nullptr;
        this->size = 0;
    }
    this->size = 0;
    if (1 == countElements) {
        insertAtIndex(this->size, 0);
    }
    while (countElements != 0) {
        insertAtIndex(0, 0);
        --countElements;
    }
}

template <typename Type>
void List<Type>::setAtIndex(unsigned int index, Type value) {
    if (0 == index &&  0 == this->size) {
        std::cout << " Type the list is empty \n";
        return;
    }
    if (0 == index && this->size != 0) {
        this->head->value = value;
        return;
    }
    if (index < 0) {
        std::cout << "Negative index "<< "\n";
        return;
    }
    else if (index >= size && size != 0) {
        std::cout << "Index must be smaller size"<< "\n";
        return;
    }
    Node *temp = this->head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    temp->value = value;
}

template <typename Type>
void List<Type>::removeAtIndex(unsigned index) {
    if (index < 0) {
        return;
    }
    else if (index >= size && size != 0) {
        std::cout << "Index must be smaller or equally  size"<< "\n";
        return;
    }
    else if (0 == this->size) {
        std::cout << "Type the list is empty"<< "\n";
        return;
    }
    Node *temp = this->head;
    if (1 == size) {
        delete temp;
        this->head = nullptr;
    }
    else if (2 == size && 1 == index) {
        temp = temp->next;
        delete temp;
    }
    else if (0 == index && this->size > 1) {
        this->head = this->head->next;
        delete temp;
        --this->size;
    }
    else {
        for (int i = 1; i < index; ++i) {
            temp = temp->next;
        }
        Node *tmp = temp->next;
        temp->next = tmp->next;
        delete tmp;
        tmp = nullptr;
    }
}

template <typename Type>
void List<Type>::insertAtIndex(unsigned int index, Type value) {
    if (0 == index && size != 0) {
        Node *newNode = new Node();
        newNode->next = this->head;
        this->head = newNode;
        newNode->value = value;
        ++this->size;
        return;
    }
    if (index < 0) {
        std::cout << "Negative index "<< "\n";
        return;
    }
    else if (index > size) {
        std::cout << "Index must be smaller or equally size"<< "\n";
        return;
    }
    else if (0 == index && 0 == size) {
        Node *newNode = new Node();
        newNode->value = value;
        this->head = newNode;
        newNode->next = nullptr;
        ++this->size;
    }
    else {
        Node *temp = this->head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node *newNode = new Node();
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->value = value;
        ++this->size;
    }
}

template <typename Type>
Type List<Type>::operator[](unsigned int index) const {
    try {
        if (index < 0 || index >= size) {
        throw customException("Invalid index");
        }
    if (index > size && index != 0) {
        std::cout << "Index must be smaller or equally size"<< "\n";
        return 0;
    }
    Node *temp = this->head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->value;
    } catch (customException& Err) {
        std::cerr << "An List exception occurred (" << Err.getError() << " [" << index << "] )\n";
        std::cerr << "List Size = " << this->getSize() << "\n";
    }
}

template <typename Type>
void List<Type>::printList(void) const {
    if ( 0 == this->size) {
        std::cout << " Type the list is empty \n";
        return;
    }
    int index = 0;
    Node *temp = this->head;
    while (temp->next != nullptr) {
        std::cout << "List Node[" << index << "] = " << temp->value << "\n";
        temp = temp->next;
        ++index;
    }
    std::cout << "List Node[" << index << "] = " << temp->value << "\n";
}

template <typename Type>
void List<Type>::clear(void) {
    while (this->size != 0) {
        removeAtIndex(0);
        --this->size;
    }
}

template <typename Type>
List<Type>::~List(void) {
    clear();
}
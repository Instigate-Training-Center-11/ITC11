#include <iostream>
#include "list.hpp"

template <typename Type>
List<Type>::List(void) {
    this->head = nullptr;
    this->size = 0;
}

template <typename Type>
unsigned int List<Type>::getSize(void) const {
    return this->size;
}

template <typename Type>
List<Type>::List(int countElements) {
    try {
        if (countElements < 0) {
            throw customException("Error negative number");
        }
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
    } catch (customException& Err){
        std::cout << Err.what () << std::endl;
    }
}

template <typename Type>
void List<Type>::setAtIndex(unsigned int index, Type value) {
    try {
        if (0 == this->size) {
            throw customException("The list is empty");
        } if (index < 0 || index >= this->size) {
            throw customException("Invalid index");
        } if (0 == index && this->size != 0) {
            this->head->value = value;
            return;
        }
        Node *temp = this->head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->value = value;
    } catch (customException& Err) {
        std::cout << Err.what () << std::endl;
    }

}

template <typename Type>
void List<Type>::removeAtIndex(unsigned index) {
    try {
        if (0 == this->size) {
            throw customException("The list is empty");
        } else if (index < 0 || index >= this->size) {
            throw customException("Invalid index");
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
    } catch (customException& Err) {
        std::cout << Err.what () << std::endl;
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
    try {
        if (index < 0 || index > this->size) {
            throw customException("Invalid index");
        } else if (0 == index && 0 == size) {
            Node *newNode = new Node();
            newNode->value = value;
            this->head = newNode;
            newNode->next = nullptr;
            ++this->size;
        } else {
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
    } catch (customException& Err) {
        std::cout << Err.what () << std::endl;
    }
}

template <typename Type>
Type List<Type>::operator[](unsigned int index) const {
    try {
        if (index < 0 || index >= this->size) {
            throw customException("Invalid index");
        }
        Node *temp = this->head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->value;
    } catch (customException& Err) {
        std::cout << Err.what () << std::endl;
    }
}

template <typename Type>
void List<Type>::printList(void) const {
    try {
        if (0 == this->size) {
            throw customException("The list is empty");
        }
        int index = 0;
        Node *temp = this->head;
        while (temp->next != nullptr) {
            std::cout << "Node[" << index << "] = " << temp->value << "\n";
            temp = temp->next;
            ++index;
        }
        std::cout << "Node[" << index << "] = " << temp->value << "\n";
    } catch (customException& Err) {
        std::cout << Err.what () << std::endl;
    }
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
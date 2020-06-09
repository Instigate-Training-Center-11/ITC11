#include <iostream>
#include "list.hpp"

template <typename Type>

List<Type>::List(void)
{
    this->head = nullptr;
    this->size = 0;
}

template <typename Type>

unsigned int List<Type>::getSize(void) const
{
    std::cout << "SIZE = " << this->size << "\n";
    return this->size;
}

template <typename Type>

List<Type>::List(int countElements)
{
    if (countElements == 0)
    {
        this->head = nullptr;
        this->size = 0;
    }
    this->size = 0;
    if (countElements == 1)
    {
        std::cout << this->size << std::endl;
        insertAtIndex(this->size, 0);
    }
    std::cout << this->size << std::endl;
    while (countElements != 0)
    {
        insertAtIndex(0, 0);
        --countElements;
    }
}

template <typename Type>

void List<Type>::setAtIndex(unsigned int index, Type value)
{
    if (index == 0 && this->size == 0)
    {
        std::cout << " Typehe list is empty \n";
        return;
    }
    if (index == 0 && this->size != 0)
    {
        this->head->value = value;
        return;
    }
    if (index < 0)
    {
        std::cout << "Negative index "
                  << "\n";
        return;
    }
    else if (index >= size && size != 0)
    {
        std::cout << "Index must be smaller size"
                  << "\n";
        return;
    }
    Node *temp = this->head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    temp->value = value;
}

template <typename Type>

void List<Type>::removeAtIndex(unsigned index)
{
    if (index < 0)
    {
        return;
    }
    else if (index >= size && size != 0)
    {
        std::cout << "Index must be smaller or equally  size"
                  << "\n";
        return;
    }
    else if (this->size == 0)
    {
        std::cout << "Typehe list is empty"
                  << "\n";
        return;
    }
    Node *temp = this->head;
    if (size == 1)
    {
        delete temp;
        this->head = nullptr;
    }
    else if (size == 2 && index == 1)
    {
        temp = temp->next;
        delete temp;
    }
    else if (index == 0 && this->size > 1)
    {
        --this->size;
        removeAtIndex(0);
    }
    else
    {
        for (int i = 1; i < index; ++i)
        {
            temp = temp->next;
        }
        Node *tmp = temp->next;
        temp->next = tmp->next;
        delete tmp;
        tmp = nullptr;
    }
}

template <typename Type>

void List<Type>::insertAtIndex(unsigned int index, Type value)
{
    if (index == 0 && size != 0)
    {
        Node *newNode = new Node();
        newNode->next = this->head->next;
        this->head->next = newNode;
        newNode->value = value;
        ++this->size;
        return;
    }
    if (index == 1 && this->size == 1)
    {
        Node *newNode = new Node();
        newNode->value = value;
        this->head->next = newNode;
        newNode->next = nullptr;
        ++this->size;
    }
    if (index < 0)
    {
        std::cout << "Negative index "
                  << "\n";
        return;
    }
    else if (index > size)
    {
        std::cout << "Index must be smaller or equally size"
                  << "\n";
        return;
    }
    else if (index == 0 && size == 0)
    {
        Node *newNode = new Node();
        newNode->value = value;
        this->head = newNode;
        newNode->next = nullptr;
        ++this->size;
    }
    else
    {
        Node *temp = this->head;
        for (int i = 0; i < index; ++i)
        {
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

Type List<Type>::operator[](unsigned int index) const
{
    if (index == 0)
    {
        return head->value;
    }
    if (index < 0)
    {
        std::cout << "Negative index "
                  << "\n";
        return 0;
    }
    else if (index > size && index != 0)
    {
        std::cout << "Index must be smaller or equally size,"
                  << "\n";
        return 0;
    }
    Node *temp = this->head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    std::cout << temp->value << "\n";
}

template <typename Type>

void List<Type>::printList(void) const
{
    if (this->size == 0)
    {
        std::cout << " Typehe list is empty \n";
        return;
    }
    int index = 0;
    Node *temp = this->head;
    while (temp->next != nullptr)
    {
        std::cout << "List Node[" << index << "] = " << temp->value << "\n";
        temp = temp->next;
        ++index;
    }
    std::cout << "List Node[" << index << "] = " << temp->value << "\n";
}

template <typename Type>

void List<Type>::clear(void)
{
    while (this->size != 0)
    {
        removeAtIndex(0);
        --this->size;
    }
}

template <typename Type>

List<Type>::~List(void)
{
    clear();
}
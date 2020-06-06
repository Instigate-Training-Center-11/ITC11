#include <iostream>
#include "list.hpp"
#include "queue.hpp"

Queue::Queue() {
    m_head = NULL;
}

void Queue::insertItem(int element) {
    add(element, 0);
    return;
}

void Queue::display() {
    printf();
}

void Queue::deleteItem() {
    remove(0);
}

Queue::~Queue() {
    while (m_head != NULL)
    {
        Node *temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}

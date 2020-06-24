#include <iostream>

void userInput();

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int);
};

/* parametrized constructor of Node class */
Node::Node(int value)
{
    data = value;
    next = prev = NULL;
}

template <typename T>
class List
{
public:
    List();
    List(const List<T>&);
    ~List();
    void push_front(T);
    void push_back(T);
    T pop_front();
    T pop_back();
    void remove(T);
    bool empty();
    void print();
    int size();
    class iterator;
    List<T>::iterator begin();
    List<T>::iterator end();

private:
    Node* head;
    Node* tail;
    int length;
};

/* default constructor of double linked list */
template <typename T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

/* copy constructor of double linked list */
template <typename T>
List<T>::List(const List<T>& list)
{
    if (list.head == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        head = Node(list.head);
        Node* tempNode = list.head->next;
        Node* temp = head;

        while (tempNode != NULL)
        {
            temp->next = new Node*;
            temp = temp->next;
            tempNode = tempNode->next;
        }
        tail = temp;

    }
}

/* destructor of double linked list */
template <typename T>
List<T>::~List()
{
    while (head)
    {
        Node* temp;
        temp = head;
        head = head->next;
        delete temp;
    }
}

/* function to add an element in front of the double linked list */
template <typename T>
void List<T>::push_front(T value)
{
    Node* temp = new Node(value);
    if (head == NULL)
        head = tail = temp;
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }

    length++;
}

/* function to add an element in the end of the double linked list */
template <typename T>
void List<T>::push_back(T value)
{
    Node* temp = new Node(value);
    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    length++;
}

/* function to delete an element from the beginning of the double linked list */
template <typename T>
T List<T>::pop_front()
{
    if (!empty())
    {
        Node* temp = head;
        if (head == tail)
        {
            tail = NULL;
        }

        T delValue = temp->data;
        head = head->next;

        delete temp;
        length--;

        return delValue;
    }
}

/* function to delete an element from the end of the double linked list */
template <typename T>
T List<T>::pop_back()
{
    if (!empty())
    {
        Node* temp = tail;
        if (head == tail)
        {
            head = NULL;
        }

        T delValue = temp->data;
        tail->next = NULL;
        tail = tail->prev;

        delete temp;
        length--;
 
        return delValue;
    }
}

/* function to delete an element from the double linked list by given value */
template <typename T>
void List<T>::remove(T value)
{
    Node* temp;
    temp = head;
    if (head->data == value)
    {
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else if (tail->data == value)
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    while (temp->data != value)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            std::cout << "\nList does not contain such an element." << std::endl;
            return;
        }
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;    
}

/* function to check if the double linked list is empty or not */
template <typename T>
bool List<T>::empty()
{
    if (length <= 0)
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List is not empty." << std::endl;
    }
}

/* function to desplay double linked list element */
template <typename T>
void List<T>::print()
{
    Node* temp = head;

    std::cout << "\n**** List contents ****\n";
    while (temp != NULL)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }

    std::cout << std::endl;
}

/* function to return double linked list size */
template <typename T>
int List<T>::size()
{
    return length;
}

/* returns an iterator pointing to the first element of double linked list */
template <typename T>
typename List<T>::iterator List<T>::begin()
{
    return iterator(head->next);
}

/* returns an iterator pointing to the last element of double linked list */
template <typename T>
typename List<T>::iterator List<T>::end()
{
    return iterator(tail);
}

/* nested class of double linked list */
template <typename T>
class List<T>::iterator
{
    Node* curr;
    public:
        iterator(T* it)
        {
            this->curr = it;
        }

        /* overloading of '==' operator */
        bool operator==(const iterator& equal) const
        {
            return *curr == *equal.curr;
        }

        /* overloading of '!=' operator */
        bool operator!=(const iterator& different) const
        {
            return *curr != *different.curr;
        }

        /* overloading of '++' operator */
        iterator& operator++()
        {
            curr = curr->next;
            return *this;
        }

        /* overloading of '--' operator */
        iterator& operator--()
        {
            curr = curr->prev;
            return *this;
        }

        /* overloading of '++(int)' operator */
        iterator& operator++(int)
        {
            iterator temp = *this;
            Node* tempNode;
            tempNode = tempNode->next;
            return temp;
        }

        /* overloading of '--(int)' operator */
        iterator& operator--(int)
        {
            iterator temp = *this;
            Node* tempNode;
            tempNode = tempNode->prev;
            return temp;
        }

        /* overloading of '*' operator */
        iterator& operator*()
        {
            return *curr;
        }
};

int main()
{
    List<int>* list = new List<int>();

    userInput();
    int userInput = 0;
    int inputNumber = 0;
    do
    {
        std::cout << "\nPlease, choose an action from above list: ";
        std::cin >> userInput;

        switch (userInput)
        {
        case 1:
            std::cout << "Enter a value: ";
            std::cin >> inputNumber;
            list->push_front(inputNumber);
            break;

        case 2:
            std::cout << "Enter a value: ";
            std::cin >> inputNumber;
            list->push_back(inputNumber);
            break;

        case 3:
            std::cout << "Deleted value is: " << list->pop_front();
            break;

        case 4:
            std::cout << "Deleted value is: " << list->pop_back();
            break;

        case 5:
            int value;
            std::cout << "Enter a value: ";
            std::cin >> value;
            list->remove(value);
            break;

        case 6:
            std::cout << "List size: " << list->size();
            break;

        case 7:
            list->print();
            break;

        case 8:
            list->empty();
            break;

        case 9:
            std::cout << "And of actions.\n" << std::endl;
            break;

        default:
            std::cout << "Wrong choice!!!" << std::endl;
            break;
        }
    } while (userInput != 9);
 
    return 0;
}
 
void userInput()
{
    std::cout << "**** Basic actions you can do with your list ****" << std::endl;
    std::cout << "1. Insert an element at FRONT         2. Insert an element at BACK" << std::endl;
    std::cout << "3. Delete an element from FRONT       4. Delete an element from BACK" << std::endl;
    std::cout << "5. Delete an element by given value   6. Desplay list size" << std::endl;
    std::cout << "7. Desplay list content               8. Check if list is empty" << std::endl;
    std::cout << "9. EXIT" << std::endl;
}
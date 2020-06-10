#include <iostream>

template <typename T>
class Node {
    public:
        Node *next;
        T value;
        Node(T value, Node *next = NULL) {
            this->value = value;
            this->next = next;
        }
};

template <typename T>
class List {
    public:
        /*Constructor*/
        List();
        /*Destructor*/
        ~List();
        /*Insert new node from the end of list*/
        void push_back(T value);
        /*Access to the element by index*/
        T& operator[](const int index);
        /*Delete node from front of list*/
        void pop_front();
        /*Check the list empty or not*/
        bool isEmpty();
        /*Get the size of list*/
        int getSize();
        /*Display the list*/
        void printf();
        /*Insert new node from the front of list*/
        void push_front(T value);
        /*Isert the element by index*/
        void add(T value, int index);
        /*Delete the list*/
        void clear();
    private:
        int size;
        Node<T> *head;
};
class myException : public std::exception {
    char* error;
    public:
    myException(char* msg) {
        this->error = msg;
    }
    char* what() {
        return this->error;
    }
};

void printL (List<int>& l) {
    if (0 == l.getSize()) {
        throw myException("List");
    } else {
        std::cout << l.getSize() << std::endl;
    }
}

/*Constructor*/
template <typename T>
List<T>::List() {
    size = 0;
    head = NULL;
}

/*Insert new node from the end of list*/
template <typename T>
void List<T>::push_back(T value) {
    if (NULL == head) {
        head = new Node<T>(value);
    } else {
        Node<T>* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node<T>(value);
    }
    size++;
}

/*Insert new node from the front of list*/
template <typename T>
void List<T>::push_front(T value) {
    head = new Node<T>(value, head);
    size++;
}

/*Access to the element by index*/
template <typename T>
T& List<T>::operator[](const int index) {
    int count = 0;
    Node<T>* current = this->head;
    while (current != NULL) {
        if (count == index) {
            return current->value;
        }
        current = current->next;
        count++;
    }
}

/*Check the list is empty or not*/
template <typename T>
bool List<T>::isEmpty() {
    return NULL == head;
}

/*Delete the node at the front of list*/
template <typename T>
void List<T>::pop_front() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

/*Add a new node by index*/
template <typename T>
void List<T>::add(T value, int index) {
    if (index == 0) {
        push_front(value);
    } else {
        Node<T>* current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T> *newNode = new Node<T>(value, current->next);
        current->next = newNode;
        size++;
    }
}

/*Delete the list*/
template <typename T>
void List<T>::clear() {
    while (size) {
        pop_front();
    }
}

/*Get the size of list*/
template <typename T>
int List<T>::getSize() {
    return size;
}

/*Display the nodes of list*/
template <typename T>
void List<T>::printf() {
    if (NULL == head) {
        return;
    }
    Node<T> *current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

/*Destructor*/
template <typename T>
List<T>::~List() {
    clear();
}

int main()
{
    List<int> l;
    int num = 0;
    std::cout << "How elements do you want to push: ";
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        l.push_back(i);
    }
    std::cout << "After push_back:" << std::endl;
    l.printf();
    std::cout << "Size = " << l.getSize() <<std::endl;

    std::cout << "After push_front:" << std::endl;
    l.push_front(7);
    l.push_front(9);
    l.printf();

    std::cout << "After pop_front:" << std::endl;
    l.pop_front();
    l.printf();

    std::cout << "After add new value:" << std::endl;
    l.add(8,2);
    l.printf();
    l.clear();

    try {
        printL(l);
    }
    catch(myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        l.add(9,10);
    }
    catch(myException& e) {
        std::cout << "out of range" << std::endl;
    }

    return 0;
}


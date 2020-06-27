#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
class Node {
    public:
        Node<T> *prev;
        Node<T> *next;
        T value;
        Node<T>(T value, Node<T> *next = NULL, Node<T> *prev = NULL) {
            this->value = value;
            this->prev = prev;
            this->next = next;
        }
};

template<typename T>
class List {
    private:
        unsigned int length;
        Node<T> *head;
        Node<T> *tail;
    public:
        /*Constructor*/
        List();
        /*Destructor*/
        ~List();
        /*Insert new node from the end of list*/
        void push_back(const T& value);
        /*Insert new node from the front of list*/
        void push_front(const T& value);
        /*Delete node from front of list*/
        void pop_front();
        /*Delete node from back of list*/
        void pop_back();
        /*Check the list empty or not*/
        bool isEmpty();
        /*Get the size of list*/
        unsigned int size() const;
        /*Display the list*/
        void print();
        class iterator;
        iterator begin();
        iterator end();
};

#endif


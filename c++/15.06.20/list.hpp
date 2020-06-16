#ifndef LIST_HPP
#define LIST_HPP

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

#endif

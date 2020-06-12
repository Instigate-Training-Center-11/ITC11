#ifndef LISt_HPP
#define LISt_HPP

class Node {
    public:
        Node *next;
        int value;
        Node(int value, Node *next = NULL) {
            this->value = value;
            this->next = next;
        }
};

class List {
    public:
        /*Constructor*/
        List();
        /*Destructor*/
        ~List();
        /*Insert new node from the end of list*/
        void push_back(int value);
        /*Access into the element by index*/
        int& operator[](const int index);
        /*Delete node from front of list*/
        void pop_front();
        /*Check the list empty or not*/
        bool isEmpty();
        /*Get the size of list*/
        int getSize();
        /*Display the list*/
        void printf();
        /*Insert new node from the front of list*/
        void push_front(int value);
        /*Insert the element by index*/
        void add(int value, int index);
        /*Delete the list*/
        void clear();
        /*Get node by index*/
        int getByIndex (int index);
        /*Delete the element by index*/
        void remove (int index);
        void asyncAdd(int value, int index);
        void asyncRemove(int index);
    private:
        int size;
        Node *head;
};

#endif


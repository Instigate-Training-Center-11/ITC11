#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
class List {
    public:
        /*Default constructor*/
        List();
        /*Destructor*/
        ~List();
        /*Insert new node to list*/
        void push_back(T value);
        /*Get element from list by index*/
        T& operator[](const int index);
        /*Delete node from list*/
        void pop_front();
        /*Check the list empty or not*/
        bool isEmpty();
        /*Get the size of list*/
        int getSize();
        /*Display the list*/
        void printf();

    private:
        template<typename T>
            class Node {
                public:
                    T value;
                    Node *pNext;
                    Node(T value, Node *pNext) {
                        this-> value = value;
                        this-> pNext = pNext;
                    }
            };
        int size;
        Node<T> *head;
};

#endif


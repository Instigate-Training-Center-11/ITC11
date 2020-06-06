#ifndef LIST_HPP
#define LIST_HPP

class List {
    public:
        /*Default constructor*/
        List();
        /*Destructor*/
        ~List();
        /*Insert new node to list by index*/
        void add(int val, int index);
        /*Delete node from list by index*/
        void remove(int index);
        /*Get element from list by index*/
        int getElement(int index);
        /*Check the list empty or not*/
        bool isEmpty();
        /*Get the size of list*/
        int getSize();
        /*Display the list*/
        void printf();

    private:
        struct Node {
            int value;
            Node* next;
            Node(int newValue)
            {
                value = newValue;
                next = NULL;
            }
        };
        Node* m_head;
};

#endif


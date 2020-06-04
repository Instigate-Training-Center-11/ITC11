#ifndef LIST_HPP
#define LIST_HPP

class List
{
    public:
        List(void);
        List(List& list);
        ~List(void);
        void add(int val, int index);
        void remove(int index);
        int getElement(int index);
        bool isEmpty();
        int getSize();
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


#ifndef LIST_H
#define LIST_H

template<typename T> 
struct Node {
	Node(const T& data = T(), Node *prev = 0, Node *next = 0) {
        this->prev = prev;
        this->next = next;
        this->data = data;
    }
	Node* prev;
	Node* next;
	T data;
};

template<typename T>
class List {
    private:
        Node<T> *first;
        Node<T> *last;
        unsigned int length;
    public:
        List();
        List(Node<T>*);
        List(const List&);
        ~List();
        void push_back (const T&);
        void push_front (const T&);
        void pop_front();
        void pop_back();
        unsigned int size() const;
        bool empty() const;
        T& front();
        T& back();
        class iterator;
        iterator begin();
        iterator end();
        void insert(int, T);
};

#endif
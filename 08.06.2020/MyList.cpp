#include <iostream>

/* MyList and Node are public classes*/
template <class T>
class MyList {
    public:
        MyList();
        T MyListSize();
        void PushFront(T data);
        void PushBack(T data);
        void InsertElement(T index, T data);
        T GetElement(T index);
        void PrintList();
        void DestroyList();
        ~MyList();

    private:
        T size;
        class Node {
            public:
                T data;
                Node* next;
                Node(T data, Node *next = NULL) {
                    this->data = data;
                    this->next = next;
                }
        };

        Node *head;
};

/* Following is the constructor of MyList class */
template <class T>
MyList<T>::MyList() {
    head = NULL;
    T size = 0;
}

/* MyListSize is a member function of MyList class
which will return sizo of the creating List */
template <class T>
T MyList<T>::MyListSize() {
    T size = 0;
    return size;
}

/* PushFront is a member function of MyList class
which will push element given to it in front of the creating List */
template <class T>
void MyList<T>::PushFront(T data) {
    head = new Node(data, head);
    size++;
}

/* PushBack is a member function of MyList class
which will push element given to it back to the creating List */
template <class T>
void MyList<T>::PushBack(T data) {
    Node *temp = this->head;

    for (T i = 0; i != (size - 1); ++i) {
        temp = temp->next;
    }

    temp->next = new Node(data, temp->next);
    size++;
}

/* PrintList is a member function of MyList class
which print elements of the List */
template <class T>
void MyList<T>::PrintList() {
    Node *temp = this->head;

    for (T i = 0; i < size; ++i) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

/* InsertElement is a member function of MyList class
which will insert the given element in the given index of List */
template <class T>
void MyList<T>::InsertElement(T index, T data) {
    Node *temp = this->head;
    if (index != 0){
        for (T i = 0; i != (index - 1); ++i) {
            temp = temp->next;
        }
        temp->next = new Node(data, temp->next);
    } else {
        head = new Node (data, head);
    }

    size++;
}

/* GetElement is a member function of MyList class
which will get List element by index */
template <class T>
T MyList<T>::GetElement(T index) {
    Node *temp = this->head;

    for (T i = 0; i != (index); ++i) {
        temp = temp->next;
    }

    std::cout << "List element by given index: " << temp->data << std::endl;
}

/* DestroyList is a member function of MyList class which will delete elements of List */
template <class T>
void MyList<T>::DestroyList() {
    if (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

/* Following is the destructor of MyList class */
template <typename T>
MyList<T>::~MyList() {
    DestroyList();
}

int main() {
    MyList<int> list;

    list.PushFront(2);

    list.PushFront(2);
    list.PushFront(1);
    list.PushBack(4);
    list.InsertElement(2, 3);
    list.GetElement(0);
    list.PrintList();
    
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List {
public:
    /* constructor of class */
    List();
    /*destructor of class */
    ~List();

    void addValue(T data);
    int getSize() {
        return size;
    }
    template <typename T>
    /* Index is a number of element, which we will to return */
    /* counter returns in which element we are */
    T& List<T>::operator[](const int index) {
        int counter = 0;
        Node<T>* current = this->head;
        /* when returns null, then we are in the end */
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            /* we don't find the element */
            current = current->pNext;
            counter++;
        }
    }
private:
    /* Node is pointer on the next element + value current element*/
    template <typename T>
    class Node {
    public:
        Node* pNext;
        T data;
        /* Constructor of class Node */
        /* To avoid uncontrolled values */
        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    /* head is the first node*/
    int size;
    Node<T>* head;
};

template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List() {
}
/* When the head is empty, we will create it as new node element*/
/* else  */
template <typename T>
void List<T>::addValue(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;

        while (current->Next != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    /* After calling addValue the size of list will be ++ */
    size++;
}

int main() {
    List<int> lst;
    lst.addValue(8);
    lst.addValue(2);
    lst.addValue(14);

    /* I don't know why the next line don't working 
    cout << lst[1] << endl; */

    return 0;
}

/* I used the following page to understand and write https://www.youtube.com/watch?v=SajrPhE6FoQ */

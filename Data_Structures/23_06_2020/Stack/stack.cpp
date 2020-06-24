#include <iostream>
#include <exception>

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>
class Stack {
private:
    int len;
    Node<T> *first;
    Node<T> *get_newNode(const T&);
    void remove_all();
public:
    Stack();
    Stack(int, T);
    ~Stack();
    void push(const T&);
    bool pop();
    T top();
    int size();
    bool empty();
};

template <typename T>
Stack<T>::Stack() {
    this->len = 0;
    this->first = nullptr;
}

template <typename T>
Stack<T>::Stack(int len, T value) {
	first = nullptr;
    this->len = len;
	for(int i = 0; i < len; ++i) {
		push(value);
	}
}

template <typename T>
Stack<T>::~Stack() {
    remove_all(); 
}

template <typename T>
Node<T> *Stack<T>::get_newNode(const T &data) {
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void Stack<T>::push(const T &data) {
    this->len++;
    if (!first) {
        Node<T> *newNode = get_newNode(data);
        first = newNode;
        return;
    }
    Node<T> *newNode = get_newNode(data);
    newNode->next = first;
    first = newNode;
    return;
}

template <typename T>
T Stack<T>::top() {
    if (this->len > 0) {
        return this->first->data;
    }
}

template <typename T>
int Stack<T>::size() {
    return this->len;
}

template <typename T>
bool Stack<T>::pop() {
    try {
        if (this->len <= 0 || this->first == nullptr) {
            throw std::runtime_error("Called unlegal operation.");
        }
        Node<T> *temp = first;
        first = first->next;
        delete temp;
        this->len--;
        return true;
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
    return false;
}

template <typename T>
void Stack<T>::remove_all() {
    Node<T> *temp = nullptr;
    while (first) {
        temp = first;
        delete temp;
        first = first->next;
        this->len--;
    }
}

template <typename T>
bool Stack<T>::empty() {
    return this->len > 0 ? false : true;
}

int main() {
    Stack<int> st;

    /* Insrert elements. */
    std::cout << "Inserted 5 elements" << "\n";
    st.push(1111);
    st.push(12);
    st.push(32);
    st.push(42);
    st.push(21);

    /* Remove last element. */
    if(st.pop()) {
        std::cout << "The last element is removed." << "\n";
    }

    /* Empty or not. */
    if(st.empty()) {
        std::cout << "The Stack is empty." << "\n";
    } else {
        std::cout << "The Stack is NOT empty." << "\n";
    }

    /* length */
    std::cout << "The Stack length is: ";
    std::cout << st.size() << "\n";

    /* Get the firts element. */
    std::cout << "The first element is: ";
    std::cout << st.top() << "\n";

    return 0;
}
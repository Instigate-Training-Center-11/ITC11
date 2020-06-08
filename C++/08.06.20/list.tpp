#include <iostream>
#include "list.hpp"

template<typename Type>

List<Type>::List() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename Type>
List<Type>::List(int size,Type value) {
    this-> size = 0;
    this->head = nullptr;
    this->tail = nullptr;
    for (int i = 0; i < size; ++i) {
        push_back(value);
    }
}

template<typename Type>
List<Type>::List(List& copy) {
    Node<Type>* tmpcopy = copy.head;
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (int i = 0; i < copy.get_size(); ++i) {
        push_back(tmpcopy->value);
        tmpcopy = tmpcopy->next;
    }
}

template<typename Type>
List<Type>::~List() {
    clear();
}

template<typename Type>
int List<Type>::get_size() const {
    return size;
}

template<typename Type>
void List<Type>::clear() {
    while (size) {
        pop_front();
    }
}

template<typename Type>
List<Type> List<Type>::operator+(const List<Type>& lst1) {
    Node<Type>* tmp = head;
    Node<Type>* tmp1 = lst1.head;
    List<Type> list_sum;

    for(int i = 0; i < size; ++i) {
        list_sum.push_back(tmp->value);
        tmp = tmp->next;
    }

    for(int j = 0; j < lst1.get_size(); ++j) {
        list_sum.push_back(tmp1->value);
        tmp1 = tmp1->next;
    }
    return list_sum;
}

template<typename Type>
void List<Type>::operator=(const List<Type>& lst1) {
    Node<Type>* tmp = head;
    Node<Type>* tmp1 = lst1.head;
    int big_size = (size > lst1.get_size()) ? size : lst1.get_size();

    for (int i = 0; i < big_size; ++i) {
        if (lst1.get_size() > size && i == size) {
            push_back(tmp1->value);
            tmp1 = tmp1->next;
        } else if (lst1.get_size() < size && i >= lst1.get_size()) {
            pop_back();
        } else {
            tmp->value = tmp1->value;
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }
    }
}

template<typename Type>
const bool List<Type>::operator==(const List<Type>& right) {
    if (size != right.get_size()) {
        return false;
    }

    Node<Type>* tmp = head;
    Node<Type>* tmpright = right.head;

    for (int i = 0; i < right.get_size(); ++i) {
        if (tmp->value != tmpright->value) {
            return false;
        }
        tmp = tmp->next;
        tmpright = tmpright->next;
    }
    return true;
}

template<typename Type>
const bool List<Type>::operator!=(const List<Type>& right) {
    if (size != right.get_size()) {
        return true;
    }
    Node<Type>* tmp = head;
    Node<Type>* tmpright = right.head;

    for (int i = 0; i < right.get_size(); ++i) {
        if (tmp->value != tmpright->value) {
            return true;
        }
        tmp = tmp->next;
        tmpright = tmpright->next;
    }
    return false;
}

template<typename Type>
Type& List<Type>::operator[](const int index) {
    if (index > size || index < 0) {
        std::cout << "list[i]...out of size!\n";
    }

    Node<Type>* tmp = head;

    for (int i = 0; i <= index; ++i) {
        if(i == index) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
}

template<typename Type>
void List<Type>::insert_at_index(Type value, int index){
    if (index == 0) {
        head  = new Node<Type>(value, head);
    } else {
        Node<Type>* tmp = head;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp->next;
        }
        tmp->next = new Node<Type>(value, tmp->next);
    }
    ++size;
}

template<typename Type>
Type List<Type>::get_at_index(int index) {
    if (index > size || index < 0) {
        std::cout << "get_at_index(int >>> " << index << " <<<)...error:" << ERROR_101 << std::endl;
        return Type();
    }

    Node<Type>* tmp = head;

    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp->value;
}

template<typename Type>
void List<Type>::set_at_index(Type value, int index) {
    if (index > size || index < 0) {
        std::cout << "set_at_index(int >>> " << index << " <<<)...error:" << ERROR_101 << std::endl;
        return;
    }

    Node<Type>* tmp = head;

    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    tmp->value = value;
}

template<typename Type>
void List<Type>::remove_at_index(int index) {
    if (index > size || index < 0) {
        std::cout << "remove_at_index(int >>> " << index << " <<<)...error:"<< ERROR_101 << std::endl;
        return;
    }

    if (index == 0) {
	    pop_front();
    } else {
	    Node<Type> *tmp = head;
	    for (int i = 0; i < index - 1; i++) {
		    tmp = tmp->next;
	    }
	    Node<Type> *Node_Delete = tmp->next;
	    tmp->next = Node_Delete->next;
	    delete Node_Delete;
	    --size;
    }

}

template<typename Type>
void List<Type>::push_back(Type value) {
    if (size == 0) {
        head = new Node<Type>(value);
        tail = head;
    } else {
        Node<Type>* tmp  = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node<Type>(value);
        tail = tmp;
    }
    ++size;
}

template<typename Type>
void List<Type>::push_front(Type value) {
    head = new Node<Type>(value, head);
    ++size;
}

template<typename Type>
void List<Type>::pop_back() {
    if (size == 0) {
        std::cout << "pop_back()...size = " << size << "...list is empty." << ERROR_202 << std::endl;
        return;
    }

    Node<Type>* tmp = head;

    for (int i = 0; i < size - 2; ++i) {
        tmp = tmp->next;
    }

    delete tmp->next;
    tmp->next = nullptr;
    --size;
}

template<typename Type>
void List<Type>::pop_front() {
    if (size == 0) {
        std::cout << "pop_front()...size = " << size << "...list is empty." << ERROR_202 << std::endl;
        return;
    }

    Node<Type>* tmp = head;
    head = head->next;
    delete tmp;
    --size;
}

template<typename Type>
Type List<Type>::list_max() const {
    if (size == 0) {
        std::cout << "list_max()...size = " << size << "...list is empty." << ERROR_202 << std::endl;
        return Type();
    }

    Node<Type>* tmp = head;
    Type max = head->value;

    for (int i = 0; i < size; ++i) {
        if (tmp->value > max) {
            max = tmp->value;
        }
        tmp = tmp->next;
    }
    return max;
}

template<typename Type>
Type List<Type>::list_min() const {
    if (size == 0) {
        std::cout << "list_min()...size = " << size << "...list is empty." << ERROR_202 << std::endl;
        return Type();
    }

    Node<Type>* tmp = head;
    Type min = head->value;

    for (int i = 0; i < size; ++i) {
        if (tmp -> value < min) {
            min = tmp->value;
        }
        tmp = tmp->next;
    }
    return min;
}

template<typename Type>
void List<Type>::reverse() {
    if (size == 0) {
        std::cout << "reverse()...size = " << size << "...list is empty." << ERROR_202 << std::endl;
        return;
    }

    Node<Type>* tmp = head;
    int counter = size;

    for (int i = 0; i < counter; ++i) {
        push_front(tmp->value);
        tmp = tmp->next;
    }

    for (int i = 0; i < counter; ++i) {
        pop_back();
    }
}

template<typename Type>
void List<Type>::print() const {
    if (size == 0) {
        std::cout << "print()...size = " << size << "...list is empty." << ERROR_202 << std::endl;
        return;
    }

    Node<Type>* tmp = head;

    for (int i = 0; i < size; ++i) {
        std::cout << "value " << i << " = " << tmp->value << std::endl;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}
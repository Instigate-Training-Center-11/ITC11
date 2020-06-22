#include "iostream"
#define lg long

  
template <class V>
class SimpleVector {
private:
    V* arr;
  
    /* the current capasity */
    lg capacity;
  
    /* length of vector */
    lg length;
  
public:
    SimpleVector(lg = 80);
  
    /* function for pushing, poping elements, resive the size and element of given index */
    lg push_back(V);
    V pop_back();
    lg size();
    /* bool empty(); */
    V& operator[](lg);
    
    class iterator {
    private:
        /* an dynamic array */
        V* ptr;
  
    public:
        iterator() : ptr(nullptr) {
        }
        iterator(V* p) : ptr(p) {
        }
        bool operator==(const iterator& it) const {
            return ptr == it.ptr;
        }
        bool operator!=(const iterator& it) const {
            return !(*this == it);
        }
        V operator*() const {
            return *ptr;
        }
        iterator& operator++() {
            ++ptr;
            return *this;
        }
        iterator operator++(int) {
            iterator temp(*this);
            ++*this;
            return temp;
        }
    };
  
    /* begin iterator */
    iterator begin() const;
  
    /* end iterator */
    iterator end() const;
};
  
/* class to return the size of vector */
template <class V>
SimpleVector<V>::SimpleVector(lg n) : capacity(n), arr(new V[n]), length(0) {
}
  
/* class to insert the element in vector */
template <class V>
lg SimpleVector<V>::push_back(V data) {
    if (length == capacity) {
        V* old = arr;
        arr = new V[capacity = capacity * 2];
        std::copy(old, old + length, arr);
        delete[] old;
    }
    arr[length++] = data;
    return length;
}
  
/* class to return the popped element in vector */
template <class V>
V SimpleVector<V>::pop_back() {
    return arr[length-- - 1];
} 
  
/* bool SimpleVector<V>::empty () {
    if (length == 0) {
        return true;
    } else {
    return false;
    }
}
 
lg SimpleVector<V>::size() { 
if (empty) {
    std::cout << "The vector is empty :(" << std::endl;
} else {
    return length;
    }
} */

/* class to return the size of vector*/
template <class V>
lg SimpleVector<V>::size() {
    return length;
} 

/* class to return the element of vector at given index */
template <class V>
V& SimpleVector<V>::operator[](lg index) {
    /* Print an error when accessing an element whose number is higher then size of vector */
    if (index >= length) {
        std::cout << "Error: Array index out of bound";
        exit(0);
    }
    return arr[index];
}

template <class V>
class SimpleVector<V>::iterator SimpleVector<V>::begin() const {
    return iterator(arr);
}
  
template <class V>
class SimpleVector<V>::iterator SimpleVector<V>::end() const {
    return iterator(arr + length);
}
  
template <class V> void display_vector(V& v) {
    /* Declaration of iterator */
    class V::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        std::cout << *ptr << '\t';
    }
    std::cout << std::endl;
}
  
int main() {
    SimpleVector<int> v;
   
    v.push_back(81);
    v.push_back(5);
    v.push_back(47);
    v.push_back(45);
    v.push_back(11);
    v.push_back(87);
    v.push_back(28);
    v.push_back(23);
    
    SimpleVector<int>::iterator it;

    std::cout << "All elements in vector v are : ";
    display_vector(v);
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "v[2]: " << v[2] << std::endl;
    std::cout << "Popped Element: " << v.pop_back() << std::endl;
    display_vector(v);
                    
    return 0;
} 

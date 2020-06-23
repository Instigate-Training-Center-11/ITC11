#include "Vector.h"

/* Default constructor */
template<typename T>
Vector<T>::Vector() {
    this->length = 0;
    this->elem = 0;
    this->total = 0;
}

/* Parametrize constructor */
template<typename T>
Vector<T>::Vector(int val) {
    this->length = val;
    this->elem = new T[val];
    this->total = val;
	for (int i = 0; i < length; ++i) {
		elem[i] = T(); 
    }
}

/* Copy constructor */
template<typename T>
Vector<T>::Vector(const Vector& arg) {
    this->length = arg.length;
    this->elem = new T[arg.length];
	for (int i = 0; i < arg.length; ++i) {
		elem[i] = arg.elem[i];
    }
}

/* Destructor */
template<typename T>
Vector<T>::~Vector() {
    delete[] elem;
}

/*  Add a new element at the end */
template<typename T>
void Vector<T>::push_back(const T& el) {
    /*
    If the vector is empty, give him total length = 5, if the size and total
    is equal, then double the size.
    */
	if (0 == total) {
		reserve(5);
    } else if (length == total) {
		reserve(2 * total);
    }
    /* Add element in the end and incrase the size of the new by 1. */
	elem[length] = el;
	++length;
}

/* Removes the last element from vector. */
template<typename T>
void Vector<T>::pop_back() {
    /*
    Create new dinamic array with size (length - 1) and copy in it the content
    of old vector.
    */
    T *ar = new T[length - 1];
    for (int i = 0; i < length - 1; ++i) {
        ar[i] = elem[i];
    }
    /* Delete the old vector reduce the size of the new by 1. */
    delete[] elem;
    elem = ar;
    length--;
}

/* Return the length, that is filled with elements. */
template<typename T>
unsigned int Vector<T>::size() const {
	return length;
}

/* Return the total length. */
template<typename T>
unsigned int Vector<T>::capacity() const {
	return total;
}

/* Chesk is empti the vector. */
template<typename T>
bool Vector<T>::empty() const {
	return (length == 0);
}

/* Incrase the size of vector by the given size. */
template<typename T>
void Vector<T>::resize(int newSize, T val) {
	reserve(newSize);
	for (int i = length; i < newSize; ++i) {
		elem[i] = T();
        length = newSize;
    }
}

/* Requests that the vector capacity. */
template<typename T>
void Vector<T>::reserve(int newTotal) {
    /*
    If the given new length less, then the total length, then the length does
    not change.
    */
	if (newTotal <= total) {
        return;
    } else {
        /* Otherwise, we create an arraywith the specified total length. */
        T *ar = new T[newTotal];
        for (int i = 0; i < length; ++i) {
            ar[i] = elem[i];
        }
        delete[] elem;
        elem = ar;
        total = newTotal;
    }
}

/* Equation the length and total length, if they are different. */
template<typename T>
void Vector<T>::shrink_to_fit() {
    if (total > length) {
        total = length;
    }
}

/* Assigns new contents to the container, replacing its current contents. */
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& el) {
	if (this == &el) {
        return *this;
    } else if (el.length <= total) {
		for (int i = 0; i < el.length; ++i) {
			elem[i] = el.elem[i];
			length = el.length;
			return *this;
		}
	}

	T *ar = new T[el.length];
	for (int i = 0; i < el.length; ++i) {
		ar[i] = el.elem[i];
    }

	delete[] elem;
	length = el.length;
	total = el.length;
	elem = ar;
	return *this;
}

/* Return the element of the [index] position. */
template<typename T>
T& Vector<T>::operator[](int index) {
	return elem[index];
}

/* Returns the iterator pointing to the first element. */
template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {	
	return Vector<T>::iterator(&elem[0]);
}

/* Returns the iterator pointing to the last element. */
template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
	return Vector<T>::iterator(&elem[length]);
}
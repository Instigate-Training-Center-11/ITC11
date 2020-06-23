#ifndef VECTOR_H
#define VECTOR_H

/* This is header file describing user-defined type Vector. */
template<typename T>
class Vector {
    private:
    /* The length of vector elements. */
    unsigned int length;
    /* First element of vector. */
    T *elem;
    /* Total size used by vector. */
    unsigned int total;
    public:
        Vector();
        Vector(int);
        Vector(const Vector&);
        ~Vector();
        void push_back(const T&);
        void pop_back();
        unsigned int size() const;
        unsigned int capacity() const;
        bool empty() const;
        void resize(int, T val = T());
        void reserve(int);
        void shrink_to_fit();
        Vector<T>& operator=(const Vector<T>&);
        T& operator[](int);
        class iterator;
        iterator begin();
        iterator end();
};

#endif
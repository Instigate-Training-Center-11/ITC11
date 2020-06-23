#ifndef VECTOR_H
#define VECTOR_H

typedef unsigned int size_type;

/* created a vector class */
template <typename T>
class vector {
    int *arr;
    int Size;
    int current;

    public:
    vector();
    vector(const vector& data);
    ~vector();
    void push_back(T value);
    void pop_back();
    size_type size() const;
    size_type capacity() const;
    bool empty();
    void resize(size_type n, T value);
    void reserve(size_type n);
    void shrink_to_fit();
    void print();
    T& operator[](int index);
    typename vector<T>::iterator begin();
    typename vector<T>::iterator end();
    class iterator;
};

#endif


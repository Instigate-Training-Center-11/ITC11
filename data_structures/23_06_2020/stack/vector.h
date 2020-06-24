#ifndef VECTOR_H
#define VECTOR_H

    /*
    Here is implemented the vector.h file for the vector<T> class created by the user.
    */
    template<typename T>
    class Vector {
        public:
            Vector();
            Vector(int, T);
            Vector(const Vector&);
            ~Vector();
            bool empty() const;
            void push_back(const T& d);
            void pop_back();
            unsigned int size() const;
            Vector<T>& operator=(const Vector<T>&);
            class iterator;
            iterator begin();
            iterator end();
            unsigned int capacity() const;
            void reserve(int);
            void resize(int, T val = T());
            void shrink_to_fit();
            T& operator[](int i);
        private:
            unsigned int len;
            T* elements;
            unsigned int space;
            int number;
    };

#endif
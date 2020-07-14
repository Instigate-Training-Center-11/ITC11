#include "vector.h"

#ifndef ITERATOR_H
#define IRERATOR_H

    /**
    * @brief Implimentation iterator of vector
    * @version 1.0.0
    */
    template<typename T>
    class Vector<T>::iterator {
        public:
            iterator(T* p) : current(p) {}

            /**
             * @brief Pre incremented iterator
             * @return Return iterator
             */
            iterator& operator++() {
                current++;
                return *this;
            }

            /**
             * @brief Post incremented iterator
             * @return Return iterator
             */
            iterator& operator++(int value) {
                iterator *temp = *this;
                current++;
                return *temp;
            }

            /**
             * @brief Pre decremented iterator
             * @return Return iterator
             */
            iterator& operator--() {
                current--;
                return *this;
            }

            /**
             * @brief Post decremented iterator
             * @return Return iterator
             */
            iterator& operator--(int value) {
                iterator *temp = *this;
                current--;
                return *temp;
            }


            T& operator*() {
                return *current;
            }

            bool operator==(const iterator& b) const {
                return *current == *b.current;
            }

            bool operator!=(const iterator& b) const {
                return *current != *b.current;
            }

        private:
            T* current;
    };

#endif
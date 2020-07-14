#include <iostream>

/**
 * @brief Map class
 * @version 1.0.0
 */

class Map {
    public:
        /**
         * @brief Add element in the end of List
         * @param value1 - Value, which will be added in the Map
         * @param value2 - Index, where the element will be added
         * @return Value, that will be returned (void)
         * @todo This function have status In Progress 20%
         * @deprecated This function already deprecated
         * @throw memory error in case of insufficient memory
         */
        void insert(int, int);
        /**
         * @brief Delete element from end of List
         * @param value - Index, which element will be deleted
         * @return Value, that will be returned (void)
         * @todo This function have status In Progress 80%
         * @warning Dont use this function more, then 2 arguments
         * @throw memory error in case of insufficient memory
         * 
         * @code
         *  void Map::erase(int value, int index) {
                std::cout << "This function will delete value from given index of map" << "\n"; 
            }
         * @endcode 
         */
        void erase(int);
};
/** \author Armenuhi Kocharyan
   * \version 1.0
   * \date 2020-07-04
   * \brief The programm sorts arrays and displayes arrays after sorting algorithms
   */

class SearchAndSort{

public:
int size = 0; ///< The size of an array that we will to sort and search element

 /**
 * @brief Creating function for swap elements of array
 * @param  Two pointers to two elements that need to swap
 * @return The functon is void
 * @todo We need olso to check size: it not will be negative value
 */
void swap(int &a, int &b);

/**
 * @brief Creating function for displaying elements of array
 * @param  An array and size of array 
 * @return The functon is void
 */
void display(int arr[], int size);

/**
 * @brief Creating function for sorting elements of array by selection
 * @param  An array and size of array 
 * @return The functon is void
 */
void selectionSort(int arr[], int size);


/**
 * @brief Creating function for searchibg elements in array by linear searching algorithm
 * @param  An array and size of array 
 * @return The functon is void
 */
int linearSearch(int arr[], int size, int num);

};

/** \author Armenuhi Kocharyan
   * \version 1.0
   * \date 2020-07-04
   * \brief the programm changes differences of two strings and displayed them
   */

class myClass
{
public:
   /**
 * @brief The function displays elements of vector
 * @param  vector fpr patameter
 * @return The functon is void
 */
   void display(std::vector<char>);

   /**
 * \brief The function changes the characters of two strings
 * @param  first string and second string for change and an variable for iteration
 * @return The functon is void
 */
   void move(std::string str1, std::string str2, int i);

   /**
 * \brief The function compares the characters of two strings
 * @param  first string and second string for comparing 
 * @return The functon is void
 */
   void compare(std::string str1, std::string str2);
};
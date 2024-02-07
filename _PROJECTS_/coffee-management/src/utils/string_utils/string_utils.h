#ifndef STRING_UTILS_H_INCLUDED
#define STRING_UTILS_H_INCLUDED

#include <iostream>
#include <vector>

namespace CoffeeShop {
namespace Utils {
namespace String {

/** \brief Convert a normal-case to upper-case of a string.
 *
 * \param s The original string.
 * \return a upper-case string.
 *
 * This function will take a string and iterate this string in `std::transform` and use
 * `std::toupper` to change a char to upper-case char one by one.
 */
std::string ToUpperCase(std::string s);

/** \brief Use to split a string.
 *
 * \param str A string that be wanted to split.
 * \param seperator A string that use to determine the point to split.
 * \return A vector<string>
 *
 * This function will take 2 strings (str and seperator) and use seperator to cut the string.
 */
std::vector<std::string> Split(std::string str, std::string seperator = "/");
};
};
};


#endif // STRING_UTILS_H_INCLUDED

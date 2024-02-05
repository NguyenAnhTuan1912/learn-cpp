#ifndef STRING_UTILS_H_INCLUDED
#define STRING_UTILS_H_INCLUDED

#include <iostream>

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

};
};
};


#endif // STRING_UTILS_H_INCLUDED

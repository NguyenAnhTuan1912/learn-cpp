#ifndef NUMBER_UTILS_H_INCLUDED
#define NUMBER_UTILS_H_INCLUDED

namespace CoffeeShop {
namespace Utils {
namespace Number {

/** \brief Use to get random number from 0 to mx - 1
 *
 * \param mx A maximun of random number, but not include it.
 * \return
 *
 */
int GetRandom(int mx);

/** \brief Use to get random number from mn to mx
 *
 * \param mn A minimum of random number.
 * \param mx A maximum of random number.
 * \return
 *
 */
int GetRandom(int mn, int mx);

};
};
};

#endif // NUMBER_UTILS_H_INCLUDED

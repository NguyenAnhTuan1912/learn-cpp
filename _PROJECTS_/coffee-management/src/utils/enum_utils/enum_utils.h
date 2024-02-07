#ifndef ENUM_UTILS_H_INCLUDED
#define ENUM_UTILS_H_INCLUDED

#include <iostream>

// Add enums
#include "../../enums/enums.h"

namespace CoffeeShop {
namespace Utils {
namespace Enum {

/** \brief Use to get a text by ShiftsEnum::Core
 *
 * \param enumerator A member of ShiftsEnum::Core
 * \return
 *
 */
std::string GetShiftEnumStr(ShiftsEnum::Core enumerator);

/** \brief Use to get a text by DrinkSizesEnum::Core
 *
 * \param enumerator A member of DrinkSizesEnum::Core
 * \return
 *
 */
std::string GetDrinkSizeEnumStr(DrinkSizesEnum::Core enumerator);

/** \brief Use to get a text by DrinkTypesEnum::Core
 *
 * \param enumerator A member of DrinkTypesEnum::Core
 * \return
 *
 */
std::string GetDrinkTypeEnumStr(DrinkTypesEnum::Core enumerator);

/** \brief Use to get a text by SnackTypesEnum::Core
 *
 * \param enumerator A member of SnackTypesEnum::Core
 * \return
 *
 */
std::string GetSnackTypeEnumStr(SnackTypesEnum::Core enumerator);

/** \brief Use to get a text by UnitsEnum::Core
 *
 * \param enumerator A member of UnitsEnum::Core
 * \return
 *
 */
std::string GetUnitEnumStr(UnitsEnum::Core enumerator);
};
};
};

#endif // ENUM_UTILS_H_INCLUDED

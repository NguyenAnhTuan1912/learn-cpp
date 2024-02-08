#ifndef ENUM_UTILS_H_INCLUDED
#define ENUM_UTILS_H_INCLUDED

#include <iostream>

// Add enums
#include "../../enums/enums.h"

// Add types
#include "../../types/keys.types.h"

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
/** \brief Use to get a ShiftEnum item from keyboard
 *
 * \param key A key value (ASCII) from keyboard
 * \return
 *
 */
ShiftsEnum::Core GetShiftEnum();

/** \brief Use to get a text by DrinkSizesEnum::Core
 *
 * \param enumerator A member of DrinkSizesEnum::Core
 * \return
 *
 */
std::string GetDrinkSizeEnumStr(DrinkSizesEnum::Core enumerator);
/** \brief Use to get a DrinkSizesEnum item from keyboard
 *
 * \param key A key value (ASCII) from keyboard
 * \return
 *
 */
DrinkSizesEnum::Core GetDrinkSizeEnum();

/** \brief Use to get a text by DrinkTypesEnum::Core
 *
 * \param enumerator A member of DrinkTypesEnum::Core
 * \return
 *
 */
std::string GetDrinkTypeEnumStr(DrinkTypesEnum::Core enumerator);
/** \brief Use to get a DrinkTypesEnum item from keyboard
 *
 * \param key A key value (ASCII) from keyboard
 * \return
 *
 */
DrinkTypesEnum::Core GetDrinkTypeEnum();

/** \brief Use to get a text by SnackTypesEnum::Core
 *
 * \param enumerator A member of SnackTypesEnum::Core
 * \return
 *
 */
std::string GetSnackTypeEnumStr(SnackTypesEnum::Core enumerator);
/** \brief Use to get a SnackTypesEnum item from keyboard
 *
 * \param key A key value (ASCII) from keyboard
 * \return
 *
 */
SnackTypesEnum::Core GetSnackTypeEnum();

/** \brief Use to get a text by UnitsEnum::Core
 *
 * \param enumerator A member of UnitsEnum::Core
 * \return
 *
 */
std::string GetUnitEnumStr(UnitsEnum::Core enumerator);
/** \brief Use to get a UnitsEnum item from keyboard
 *
 * \param key A key value (ASCII) from keyboard
 * \return
 *
 */
UnitsEnum::Core GetUnitEnum();

};
};
};

#endif // ENUM_UTILS_H_INCLUDED

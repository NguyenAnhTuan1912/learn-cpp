#include "enum_utils.h"

namespace CoffeeShop {
namespace Utils {
namespace Enum {

std::string GetShiftEnumStr(ShiftsEnum::Core enumerator) {
  switch(enumerator) {
    case ShiftsEnum::FullTime: return "FullTime";
    case ShiftsEnum::PartTime: return "PartTime";
    default: return "";
  };
};

std::string GetDrinkSizeEnumStr(DrinkSizesEnum::Core enumerator) {
  switch(enumerator) {
    case DrinkSizesEnum::SizeM: return "M";
    case DrinkSizesEnum::SizeL: return "L";
    case DrinkSizesEnum::SizeXL: return "XL";
    default: return "";
  };
};

std::string GetDrinkTypeEnumStr(DrinkTypesEnum::Core enumerator) {
  switch(enumerator) {
    case DrinkTypesEnum::Coffee: return "Coffee";
    case DrinkTypesEnum::Juice: return "Juice";
    case DrinkTypesEnum::Soda: return "Soda";
    case DrinkTypesEnum::Yaourt: return "Yaourt";
    default: return "";
  };
};

std::string GetSnackTypeEnumStr(SnackTypesEnum::Core enumerator) {
  switch(enumerator) {
    case SnackTypesEnum::Salty: return "Salty";
    case SnackTypesEnum::Sweety: return "Sweety";
    default: return "";
  };
};

std::string GetUnitEnumStr(UnitsEnum::Core enumerator) {
  switch(enumerator) {
    case UnitsEnum::Miligram: return "Miligram";
    case UnitsEnum::Gram: return "Gram";
    case UnitsEnum::Kilogram: return "Kilogram";
    case UnitsEnum::Mililitre: return "Mililitre";
    case UnitsEnum::Litre: return "Litre";
    case UnitsEnum::Kilolitre: return "Kilolitre";
    default: return "";
  };
};

};
};
};

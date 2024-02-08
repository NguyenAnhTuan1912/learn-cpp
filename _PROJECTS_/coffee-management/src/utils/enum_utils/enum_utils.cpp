#include <conio.h>

// Add macros
#include "../../macros/keys.h"

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
ShiftsEnum::Core GetShiftEnum() {
  Types::LimitedKeyCode key;

  std::cout << "1. " << GetShiftEnumStr(ShiftsEnum::FullTime) << std::endl;
  std::cout << "2. " << GetShiftEnumStr(ShiftsEnum::PartTime) << std::endl;

  key = getch();

  switch(key) {
    case KEY_1: return ShiftsEnum::FullTime;
    case KEY_2: return ShiftsEnum::PartTime;
    default: return ShiftsEnum::FullTime;
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
DrinkSizesEnum::Core GetDrinkSizeEnum() {
  Types::LimitedKeyCode key;

  std::cout << "1. " << GetDrinkSizeEnumStr(DrinkSizesEnum::SizeL) << std::endl;
  std::cout << "2. " << GetDrinkSizeEnumStr(DrinkSizesEnum::SizeM) << std::endl;
  std::cout << "3. " << GetDrinkSizeEnumStr(DrinkSizesEnum::SizeXL) << std::endl;

  key = getch();

  switch(key) {
    case KEY_1: return DrinkSizesEnum::SizeL;
    case KEY_2: return DrinkSizesEnum::SizeM;
    case KEY_3: return DrinkSizesEnum::SizeXL;
    default: return DrinkSizesEnum::SizeM;
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

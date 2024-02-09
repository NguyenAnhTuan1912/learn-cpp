#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

namespace CoffeeShop {
namespace ShiftsEnum {
enum Core {
  Empty,
  PartTime,
  FullTime
};
};

namespace DrinkSizesEnum {
enum Core {
  Empty,
  SizeM,
  SizeL,
  SizeXL
};
};

namespace DrinkTypesEnum {
enum Core {
  Empty,
  Soda,
  Yaourt,
  Coffee,
  Juice
};
};

namespace SnackTypesEnum {
enum Core {
  Empty,
  Sweety,
  Salty
};
};

namespace UnitsEnum {
enum Core {
  Empty,
  Miligram,
  Gram,
  Kilogram,
  Mililitre,
  Litre,
  Kilolitre
};
};
};

#endif // ENUMS_H_INCLUDED

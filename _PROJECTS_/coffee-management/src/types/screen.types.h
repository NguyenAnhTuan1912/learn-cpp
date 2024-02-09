#ifndef SCREEN_TYPES_H_INCLUDED
#define SCREEN_TYPES_H_INCLUDED

#include <iostream>
#include <map>

#include "../objects/screen/Screen.h"

namespace CoffeeShop {
// Re-declare clase Screen
class Screen;

namespace Types {

typedef std::map<std::string, Screen*> LinkedScreenMap;

};
};

#endif // SCREEN_TYPES_H_INCLUDED

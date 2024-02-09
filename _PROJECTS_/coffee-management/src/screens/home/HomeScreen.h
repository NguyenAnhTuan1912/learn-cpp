#ifndef HOMESCREEN_H_INCLUDED
#define HOMESCREEN_H_INCLUDED

// Add objects
#include "../../objects/screen/Screen.h"

namespace CoffeeShop {

class HomeScreen : public Screen {
public:
  HomeScreen(): Screen("Home") {};
  void Render();
};

};

#endif // HOMESCREEN_H_INCLUDED

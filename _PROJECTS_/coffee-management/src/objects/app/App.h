#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include<iostream>
#include<vector>

#include "../screen/Screen.h"

namespace CoffeeShop {

/*
  Declare a class that creates an instance to manage app.
*/
class App {
private:
  Screen* _default_screen_;

public:
  App() = default;
  App(
    Screen* default_screen
  );

  // Other methods
  void Start();
};

};

#endif // APP_H_INCLUDED

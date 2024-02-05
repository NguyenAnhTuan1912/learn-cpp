#include <iostream>

#include "App.h"
#include "../screen/Screen.h"

/*
  Define a class that creates an instance to manage app.
*/
namespace CoffeeShop {

App::App(Screen* default_screen) {
  this->_default_screen_ = default_screen;
};

// Other methods
void App::Start() {
  this->_default_screen_->Print();
};

};

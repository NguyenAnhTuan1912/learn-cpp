#include <iostream>

// Add macros
#include "../../macros/keys.h"

#include "App.h"

/*
  Define a class that creates an instance to manage app.
*/
namespace CoffeeShop {

App::App(Screen* default_screen) {
  this->_default_screen_ = default_screen;
  this->_current_screen_ = default_screen;
};

// Other methods
void App::Start() {
  this->_current_screen_->Print();
};

void App::Render(Types::LimitedKeyCode key) {
  this->_current_screen_->Print();

  // List selections
  // App's selections
  switch(key) {
    case KEY_n: {
      // Render all navigable screens of current screen.
      std::cout << "WTF???" << std::endl;
      return;
    };

    default: {
      // If don't match any key, render default.

      std::cout << "Selections:\n";
      std::cout << "[n]. Navigation\n";
      return;
    };
  };

  // Screen's selections
};

};

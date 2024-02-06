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

bool App::Select(Types::LimitedKeyCode key) {
  switch(key) {
    case KEY_n: {
      // Render all navigable screens of current screen.
      std::string id = this->_current_screen_->GetNavigableScreenId();

      std::cout << "Id: " << id << std::endl;

      // If user don't want to navigate, return true;
      if(id == "") return true;

      this->_current_screen_ = (&this->_current_screen_->GetLinkedScreen(id));
      return true;
    };

    default: {
      // If don't match any key, render default.
      std::cout << "Selections:\n";
      std::cout << "[n]. Navigation\n";
      return false;
    };
  };
};

void App::Render(Types::LimitedKeyCode key) {
  this->_current_screen_->Print();
  // std::cout << "Address of current screen: " << this->_current_screen_ << std::endl;

  // List selections
  // App's selections
  bool is_select_done = this->Select(key);

  // Screen's selections for user
  if(!is_select_done)
    is_select_done = this->_current_screen_->SelectFeature(key);

  this->_is_performed_selection_ = is_select_done;
  return;
};

};

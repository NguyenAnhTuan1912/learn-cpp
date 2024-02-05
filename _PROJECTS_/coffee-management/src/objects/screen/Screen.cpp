#include <stdlib.h>
#include <iostream>

#include "Screen.h"

#include "../../utils/string_utils/string_utils.h"

/*
  Define a class that creates an instance to manage screen.
*/
namespace CoffeeShop {

Screen::Screen(
  std::string id,
  std::string name
) {
  this->_id_ = id;
  this->_name_ = name;
};

void Screen::AddLinkedScreen(Screen* screen) {
  this->_linked_screens_[screen->GetId()] = screen;
};

void Screen::Print() {
  // Clear screen
  system("cls");

  std::cout << "In screen - " << Utils::String::ToUpperCase(this->_name_) << std::endl;
  std::cout << "===================\n";

  // Content

  std::cout << "===================\n";
  std::cout << "Navigate to: " << std::endl;
};

Screen& Screen::NavigateTo(std::string screen_id) {
  Screen* s = this->_linked_screens_[screen_id];
  s->Print();
  return *s;
};

};

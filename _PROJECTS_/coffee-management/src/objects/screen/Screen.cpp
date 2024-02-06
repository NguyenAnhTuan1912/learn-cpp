#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "Screen.h"

// Add macros
#include "../../macros/keys.h"

// Add types
#include "../../types/screen.types.h"

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

std::string Screen::GetNavigableScreenId() {
  // List linked screens
  // Get iterator
  Types::LinkedScreenMap::iterator itr = this->_linked_screens_.begin();
  Types::LimitedKeyCode key = 0;
  std::vector<std::string> map_keys;
  int index = 1, select = 0, s = 0;

  // Loop
  std::cout << "Navigate to: \n";
  while(itr != this->_linked_screens_.end()) {
    std::cout << index << ". " << itr->second->GetName() << std::endl;
    map_keys.push_back(itr->first);
    index++;
    itr++;
  };

  std::cout << "c. Cancel\n";

  // Get selection
  key = getch();
  // Convert to int
  select = key - '0' - 1;
  s = map_keys.size();

  if(key != KEY_c && select >= 0 && select < s) return map_keys.at(select);

  return "";
};

void Screen::Render() { std::cout << "Default content of " << this->_name_ << " screen." << std::endl; };
bool Screen::SelectFeature(Types::LimitedKeyCode key) { std::cout << "Feature." << std::endl; return false; };

};

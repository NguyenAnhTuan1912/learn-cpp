#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "Screen.h"

// Add macros
#include "../../macros/keys_macros.h"

// Add types
#include "../../types/screen.types.h"

/*
  Define a class that creates an instance to manage screen.
*/
namespace CoffeeShop {

Screen::Screen(
  std::string name
) {
  this->_name_ = name;
};

// Getters
std::string Screen::GetId() { return this->_id_; };
std::string Screen::GetName() { return this->_name_; };
Types::LimitedKeyCode Screen::GetPreviousFeatureKey() { return this->_previous_feature_key_; };
Screen& Screen::GetLinkedScreen(std::string screen_id) {
  return *(this->_linked_screens_[screen_id]);
};

// Setters
void Screen::SetPreviousFeatureKey(Types::LimitedKeyCode key)  { this->_previous_feature_key_ = key; };
// Other methods
void Screen::AddLinkedScreen(Screen* screen) {
  this->_linked_screens_[screen->GetId()] = screen;
};

void Screen::Print() {
  // Clear screen
  system("cls");

  std::cout << "In screen - " << Utils::String::ToUpperCase(this->_name_) << std::endl;
  std::cout << "=====\n";
  // Content
  this->Render();
  std::cout << "\n=====\n";
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

bool Screen::DeciseToContinue() {
  Types::LimitedKeyCode key;
  std::cout << "Press [c] to continue; any key to stop\n";
  key = getch();
  if(key != KEY_c) {
    this->_previous_feature_key_ = 0;
    return false;
  };
  return true;
};

void Screen::Render() { std::cout << "Default content of " << this->_name_ << " screen. Id: " << this->_id_ << std::endl; };
bool Screen::SelectFeature(Types::LimitedKeyCode key) { std::cout << "Feature." << std::endl; return false; };

};

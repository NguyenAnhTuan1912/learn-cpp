#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <map>

namespace CoffeeShop {

/*
  Declare a class that creates an instance to manage screen.
*/
class Screen {
private:
  std::string _id_;
  std::string _name_;
  std::map<std::string, Screen*> _linked_screens_;

public:
  Screen() = default;
  Screen(
    std::string id,
    std::string name
  );

  void AddLinkedScreen(Screen* screen);

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetName() final { return this->_name_; };

  // Other methods
  void Print();
  Screen& NavigateTo(std::string screen_id);
};

};

#endif // SCREEN_H_INCLUDED

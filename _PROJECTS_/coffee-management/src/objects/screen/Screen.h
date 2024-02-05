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

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetName() final { return this->_name_; };

  // Other methods
  /** \brief Use to add a linked screen
   *
   * \param screen A pointer of navigable screen
   * \return void
   *
   * When this method is execute, it require 1 arg is a pointer of navigable screen
   * then screen instance will add this pointer to list.
   */
  void AddLinkedScreen(Screen* screen);

  /** \brief Use to print the content of screen
   *
   * \return void
   *
   * When this method is executed, the content of this screen will be printed
   * on console.
   */
  void Print();

  /** \brief Use to print another screen
   *
   * \param screen_id An id of a screen
   * \return A reference of screen
   *
   * When this method is executed, new content of new screen will be printed.
   * USE WITH APP INSTANCE.
   */

  Screen& NavigateTo(std::string screen_id);
};

};

#endif // SCREEN_H_INCLUDED

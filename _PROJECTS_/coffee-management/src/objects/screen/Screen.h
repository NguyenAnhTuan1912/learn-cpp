#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <vector>

// Add utils
#include "../../utils/string_utils/string_utils.h"

// Add types
#include "../../types/screen.types.h"
#include "../../types/keys.types.h"

namespace CoffeeShop {

/*
  Declare a class that creates an instance to manage screen.
*/
class Screen {
private:
  std::string _id_ = Utils::String::GenerateRandom("screen");
  std::string _name_;
  Types::LinkedScreenMap _linked_screens_;

public:
  Screen() = default;
  Screen(
    std::string name
  );

  // Getters

  /** \brief Use to get id of screen
   *
   * \return An string of screen id
   *
   */
  virtual std::string GetId() final { return this->_id_; };

  /** \brief Use to get name of screen
   *
   * \return A string of screen name
   *
   */
  virtual std::string GetName() final { return this->_name_; };

  /** \brief Use to get a pointer of linked screen
   *
   * \param screen_id An id of a screen
   * \return A pointer of screen
   *
   */
  virtual Screen& GetLinkedScreen(std::string screen_id) final {
    return *(this->_linked_screens_[screen_id]);
  };

  // Other methods
  /** \brief Use to add a linked screen
   *
   * \param screen A pointer of navigable screen
   * \return void
   */
  virtual void AddLinkedScreen(Screen* screen) final {
    this->_linked_screens_[screen->GetId()] = screen;
  };

  /** \brief Use to print the content of screen
   *
   * \return void
   *
   * When this method is executed, the content of this screen will be printed
   * on console.
   */
  virtual void Print() final {
    // Clear screen
    system("cls");

    std::cout << "In screen - " << Utils::String::ToUpperCase(this->_name_) << std::endl;
    std::cout << "=====\n";
    // Content
    this->Render();
    std::cout << "=====\n";
  };

  /** \brief Use to render the content of screen
   *
   * \return
   *
   * When this method is executed, particular instructions will print
   * content to the console. This method need to be defined specifically.
   */
  void Render();

  /** \brief Use to get id of navigable screen
   *
   * \param key A key is selected from keyboard.
   * \return
   *
   * When this method is executed, the screen will list the linked
   * screen and return a string depend on user's choice.
   */
  std::string GetNavigableScreenId();

  /** \brief Use to render the particular selections of screen
   *
   * \param key A key is selected from keyboard.
   * \return
   *
   * When this method is executed, particular instructions will print
   * features to the console. This method need to be defined specifically.
   */
  bool SelectFeature(Types::LimitedKeyCode key);
};

};

#endif // SCREEN_H_INCLUDED

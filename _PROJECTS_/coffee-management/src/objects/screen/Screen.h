#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <vector>

// Add macros
#include "../../macros/keys.h"

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
  Types::LimitedKeyCode _previous_feature_key_;

public:
  Screen() = default;
  Screen(
    std::string name
  );

  // Getters
  virtual std::string GetId() final;
  virtual std::string GetName() final;
  virtual Screen& GetLinkedScreen(std::string screen_id) final;
  virtual Types::LimitedKeyCode GetPreviousFeatureKey() final;

  // Setters
  virtual void SetPreviousFeatureKey(Types::LimitedKeyCode key) final;

  // Other methods
  virtual void AddLinkedScreen(Screen* screen) final;

  /** \brief Use to print the content of screen
   *
   * \return void
   *
   * When this method is executed, the content of this screen will be printed
   * on console.
   */
  virtual void Print() final;

  /** \brief Use to render the content of screen
   *
   * \return
   *
   * When this method is executed, particular instructions will print
   * content to the console. This method need to be defined specifically.
   */
  virtual void Render();

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
  virtual bool SelectFeature(Types::LimitedKeyCode key);

  /** \brief Use to print 2 decisions about continue perform a feature.
   *
   * \return void
   *
   * When perform a feature, there is maybe error occur. So this method
   * use to get user's decision to continue or not.
   */
  virtual bool DeciseToContinue() final;
};

};

#endif // SCREEN_H_INCLUDED

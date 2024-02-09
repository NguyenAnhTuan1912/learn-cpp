#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include<iostream>
#include<vector>

#include "../screen/Screen.h"

#include "../../types/keys.types.h"

namespace CoffeeShop {

/*
  Declare a class that creates an instance to manage app.
*/
class App {
private:
  Screen* _default_screen_;
  Screen* _current_screen_;
  bool _is_performed_selection_ = false;

public:
  App() = default;
  App(
    Screen* default_screen
  );

  // Getters
  virtual bool GetIsPerformedSelectionStatus() final { return this->_is_performed_selection_; };

  // Setters
  virtual void SetIsPerformedSelectionStatus(bool status) final { this->_is_performed_selection_ = status; };

  // Other methods
  /** \brief Use to start
   *
   * \return void
   *
   * When this method is executed, app will render the first time with default screen.
   */
  void Start();

  /** \brief Use to render
   *
   * \param key A key is selected from keyboard.
   * \return void
   *
   * When this method is executed, app will perform actions and re-print something.
   */
  void Render(Types::LimitedKeyCode key);

  /** \brief Use to render selections and get result of them
   *
   * \param key A key is selected from keyboard.
   * \return
   *
   * When this method is executed, app will get information that it need and print
   * to console. Then it will wait for the action from screen or other object and
   * get it result.
   */
  bool Select(Types::LimitedKeyCode key);
};

};

#endif // APP_H_INCLUDED

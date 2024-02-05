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

public:
  App() = default;
  App(
    Screen* default_screen
  );

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
   * \param
   * \param
   * \return void
   *
   * When this method is executed, app will perform actions and re-print something.
   */
  void Render(Types::LimitedKeyCode key);
};

};

#endif // APP_H_INCLUDED

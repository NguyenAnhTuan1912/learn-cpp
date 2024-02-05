#include <iostream>
#include <conio.h>

// Add macros
#include "macros/keys.h"

// Add objects
#include "objects/app/App.h"
#include "objects/screen/Screen.h"

// Add types
#include "types/keys.types.h"

using namespace std;
using namespace CoffeeShop;

int main()
{
  Types::LimitedKeyCode key = 0;

  // Init screens
  Screen home("screen_01", "Home");

  // Init app
  App app(&home);

  // Start app
  app.Start();

  while(key != KEY_ESC) {
    app.Render(key);
    key = getch();
  };

  return 0;
}

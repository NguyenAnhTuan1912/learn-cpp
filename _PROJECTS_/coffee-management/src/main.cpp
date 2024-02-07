#include <iostream>
#include <conio.h>

// Add macros
#include "macros/keys.h"

// Add objects
#include "objects/app/App.h"
#include "objects/screen/Screen.h"
#include "objects/datetime/Datetime.h"

// Add types
#include "types/keys.types.h"

using namespace std;
using namespace CoffeeShop;

int main()
{
  Types::LimitedKeyCode key = 0;

  // Init screens
  Screen home("screen_01", "Home");
  Screen employee("screen_02", "Employee");

  home.AddLinkedScreen(&employee);
  employee.AddLinkedScreen(&home);

  // Init app
  App app(&home);

  // Start app
  app.Start();

  while(key != KEY_ESC) {
    app.Render(key);
    // cout << "Address of home: " << (&home) << endl;

    // If there is any action is performed, skip this statement.
    if(!app.GetIsPerformedSelectionStatus())
      key = getch();
    else {
      // Reset
      app.SetIsPerformedSelectionStatus(false);
      key = 0;
    };
  };

  return 0;
}

#include <iostream>

#include "objects/app/App.h"
#include "objects/screen/Screen.h"

using namespace std;
using namespace CoffeeShop;

int main()
{
  // Init screens
  Screen home("screen_01", "Home");

  App app(&home);

  // Start app
  app.Start();

  return 0;
}

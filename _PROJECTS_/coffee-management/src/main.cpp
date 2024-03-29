#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>

// Add macros
#include "macros/keys_macros.h"

// Add objects
#include "objects/datetime/Datetime.h"
#include "objects/data_list/DataList.h"
#include "objects/app/App.h"

// Add screen
#include "screens/home/HomeScreen.h"
#include "screens/employee/EmployeeScreen.h"
#include "screens/ingredient/IngredientScreen.h"
#include "screens/product/ProductScreen.h"

// Add types
#include "types/keys.types.h"

using namespace std;
using namespace CoffeeShop;

int main()
{
  srand(time(nullptr));

  Types::LimitedKeyCode key = 0;

  // Init screens
  HomeScreen home;
  EmployeeScreen employee;
  IngredientScreen ingredient;
  ProductScreen product;

  // Home link
  home.AddLinkedScreen(&employee);
  home.AddLinkedScreen(&ingredient);
  home.AddLinkedScreen(&product);

  // Employee link
  employee.AddLinkedScreen(&home);
  employee.AddLinkedScreen(&ingredient);
  employee.AddLinkedScreen(&product);

  // Ingredient link
  ingredient.AddLinkedScreen(&home);
  ingredient.AddLinkedScreen(&employee);
  ingredient.AddLinkedScreen(&product);

  // Product link
  product.AddLinkedScreen(&home);
  product.AddLinkedScreen(&ingredient);
  product.AddLinkedScreen(&employee);

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

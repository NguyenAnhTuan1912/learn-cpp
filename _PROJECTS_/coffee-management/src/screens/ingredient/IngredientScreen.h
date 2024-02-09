#ifndef INGREDIENTSCREEN_H_INCLUDED
#define INGREDIENTSCREEN_H_INCLUDED

// Add macros
#include "../../macros/keys_macros.h"

// Add objects
#include "../../objects/screen/Screen.h"
#include "../../objects/ingredient/Ingredient.h"
#include "../../objects/data_list/DataList.h"
#include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/keys.types.h"

namespace CoffeeShop {

class IngredientScreen : public Screen {
private:
  DataList<std::string, Ingredient> _data_;
  Ingredient _igd_holder_;

public:
  IngredientScreen(): Screen("Ingredient") {};

  /** \brief Use to perform "add ingredient" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformAddIngredient();

  /** \brief Use to perform "delete ingredient" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformDeleteIngredient();

  /** \brief Use to perform "update ingredient" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformUpdateIngredient();

  void Render();
  bool SelectFeature(Types::LimitedKeyCode key);
};

};

#endif // INGREDIENTSCREEN_H_INCLUDED

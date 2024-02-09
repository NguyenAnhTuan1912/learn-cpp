#ifndef PRODUCTSCREEN_H_INCLUDED
#define PRODUCTSCREEN_H_INCLUDED

// Add macros
#include "../../macros/keys_macros.h"

// Add objects
#include "../../objects/screen/Screen.h"
#include "../../objects/product/Product.h"
#include "../../objects/data_list/DataList.h"
#include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/keys.types.h"

namespace CoffeeShop {

class ProductScreen : public Screen {
private:
  DataList<std::string, Employee> _data_;
  Drink _drk_holder_;
  Snack _snk_holder_;

public:
  ProductScreen(): Screen("Product") {};

  // Other methods
  /** \brief Use to check age of person is suitable for work
   *
   * \param datetime A datetime as string that wanted to check
   * \return
   *
   */
  bool IsAgeSuitableForWork(std::string datetime);

  /** \brief Use to perform "add employee" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformAddEmployee();

  /** \brief Use to perform "delete employee" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformDeleteEmployee();

  /** \brief Use to perform "update employee" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformUpdateEmployee();

  void Render();
  bool SelectFeature(Types::LimitedKeyCode key);
};

};

#endif // PRODUCTSCREEN_H_INCLUDED

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
  DataList<std::string, Drink> _drink_data_;
  DataList<std::string, Snack> _snack_data_;
  Drink _drk_holder_;
  Snack _snk_holder_;

public:
  ProductScreen(): Screen("Product") {};

  // Other methods
  /** \brief Use to perform "add product" action.
   *
   * \param prod A product that want to be added
   * \return
   *
   * View more in source file.
   */
  void PerformAddProduct(Product& prod);

  /** \brief Use to perform "add snack" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformAddSnack();

  /** \brief Use to perform "add drink" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformAddDrink();

  /** \brief Use to perform "delete product" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformDeleteProduct(auto& data);

  /** \brief Use to perform "delete snack" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformDeleteSnack();

  /** \brief Use to perform "delete drink" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformDeleteDrink();

  /** \brief Use to perform "update product" action.
   *
   * \param prod A product that want to be updated
   * \return
   *
   * View more in source file.
   */
  Product* PerformUpdateProduct(auto& data);

  /** \brief Use to perform "update snack" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformUpdateSnack();

  /** \brief Use to perform "update drink" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformUpdateDrink();

  void Render();
  bool SelectFeature(Types::LimitedKeyCode key);
};

};

#endif // PRODUCTSCREEN_H_INCLUDED

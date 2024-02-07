#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <vector>
#include <ctime>

// Add objects
#include "../ingredient/Ingredient.h"

// Add enums
#include "../../enums/enums.h"

namespace CoffeeShop {

class Product {
private:
  std::string _id_;
  std::string _name_;
  std::vector<Ingredient*> _ingredients_;
  unsigned short _base_cost_;

public:
  Product() = default;

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetName() final { return this->_name_; };
  virtual unsigned short GetBaseCost() final { return this->_base_cost_; };

  // Setters

  // Other methods
};

};

#endif // PRODUCT_H_INCLUDED

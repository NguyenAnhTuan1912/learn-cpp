#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include <ctime>

// Add objects
#include "../datetime/Datetime.h"

// Add enums
#include "../../enums/enums.h"

namespace CoffeeShop {

class Ingredient {
private:
  std::string _id_;
  std::string _name_;
  Datetime _inbouding_date_;
  Datetime _manufacturing_date_;
  Datetime _expiry_date_;
  unsigned short _amount_;
  unsigned short _cost_per_unit_;
  UnitsEnum::Core _unit_;

public:
  Ingredient() = default;

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetName() final { return this->_name_; };
  virtual unsigned short GetAmount() final { return this->_amount_; };
  virtual unsigned short GetCostPerUnit() final { return this->_cost_per_unit_; };
  virtual std::string GetUnit() final { return ""; };

  // Setters

  // Other methods
};

};

#endif // INGREDIENT_H_INCLUDED

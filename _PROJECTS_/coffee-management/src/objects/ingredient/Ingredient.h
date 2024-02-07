#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include <ctime>

// Add enums
#include "../../enums/enums.h"
#include "../../utils/string_utils/string_utils.h"

// Add objects
#include "../datetime/Datetime.h"

// Add utils
#include "../../utils/enum_utils/enum_utils.h"

namespace CoffeeShop {

class Ingredient {
private:
  std::string _id_ = Utils::String::GenerateRandom("ingredient");
  std::string _name_;
  Datetime _inbouding_date_;
  Datetime _manufacturing_date_;
  Datetime _expiry_date_;
  unsigned short _amount_;
  unsigned short _cost_per_unit_;
  UnitsEnum::Core _unit_;

public:
  Ingredient() = default;
  Ingredient(
    std::string name,
    Datetime inbouding_date,
    Datetime manufacturing_date,
    Datetime expiry_date,
    unsigned short amount,
    unsigned short cost_per_unit,
    UnitsEnum::Core unit
  );

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetName() final { return this->_name_; };
  virtual Datetime GetInboudingDate() final { return this->_inbouding_date_; };
  virtual Datetime GetManufacturingDate() final { return this->_manufacturing_date_; };
  virtual Datetime GetExpiryDate() final { return this->_expiry_date_; };
  virtual unsigned short GetAmount() final { return this->_amount_; };
  virtual unsigned short GetCostPerUnit() final { return this->_cost_per_unit_; };
  virtual UnitsEnum::Core GetUnit() final { return this->_unit_; };

  // Setters
  virtual void SetName(std::string name) final { this->_name_ = name; };
  virtual void SetInboudingDate(std::string date) final { this->_inbouding_date_ = Datetime(date); };
  virtual void SetManufacturingDate(std::string date final { this->_manufacturing_date_ = Datetime(date); };
  virtual void SetExpiryDate(std::string date) final { this->_expiry_date_ = Datetime(date); };
  virtual void SetAmount(unsigned short amount) final { this->_amount_ = amount; };
  virtual void SetCostPerUnit(unsigned short cpu) final { this->_cost_per_unit_ = cpu; };
  virtual void SetUnit(UnitsEnum::Core en) final { this->_unit_ = en; };

  // Other methods
  virtual std::string GetUnitStr() final { return Utils::Enum::GetUnitEnumStr(this->_unit_); };
};

};

#endif // INGREDIENT_H_INCLUDED

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
  Datetime _inbounding_date_;
  Datetime _manufacturing_date_;
  Datetime _expiry_date_;
  float _amount_ = 0;
  float _cost_per_unit_ = 0;
  UnitsEnum::Core _unit_ = UnitsEnum::Empty;

public:
  Ingredient() = default;
  Ingredient(
    std::string name,
    std::string inbounding_date,
    std::string manufacturing_date,
    std::string expiry_date,
    float amount = 0,
    float cost_per_unit = 0,
    UnitsEnum::Core unit = UnitsEnum::Empty
  );

  // Getters
  virtual std::string GetId() final;
  virtual std::string GetName() final;
  virtual Datetime* GetInboundingDate() final;
  virtual Datetime* GetManufacturingDate() final;
  virtual Datetime* GetExpiryDate() final;
  virtual float GetAmount() final;
  virtual float GetCostPerUnit() final;
  virtual UnitsEnum::Core GetUnit() final;

  // Setters
  virtual void SetName(std::string name) final;
  virtual void SetInboundingDate(std::string date) final;
  virtual void SetManufacturingDate(std::string date) final;
  virtual void SetExpiryDate(std::string date) final;
  virtual void SetAmount(float amount) final;
  virtual void SetCostPerUnit(float cpu) final;
  virtual void SetUnit(UnitsEnum::Core en) final;

  // Other methods
  virtual std::string GetUnitStr() final;
  virtual void Print() final;
  virtual void PrintOnlyData() final;
};

};

#endif // INGREDIENT_H_INCLUDED

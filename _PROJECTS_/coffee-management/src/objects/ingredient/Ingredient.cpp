#include "Ingredient.h"

// Add utils
#include "../../utils/enum_utils/enum_utils.h"

namespace CoffeeShop {

Ingredient::Ingredient(
  std::string name,
  std::string inbounding_date,
  std::string manufacturing_date,
  std::string expiry_date,
  float amount,
  float cost_per_unit,
  UnitsEnum::Core unit
) {
  this->_name_ = name;
  this->_inbounding_date_ = Datetime(inbounding_date);
  this->_manufacturing_date_ = Datetime(manufacturing_date);
  this->_expiry_date_ = Datetime(expiry_date);
  this->_amount_ = amount;
  this->_cost_per_unit_ = cost_per_unit;
  this->_unit_ = unit;
};

// Getters
std::string Ingredient::GetId() { return this->_id_; };
std::string Ingredient::GetName() { return this->_name_; };
Datetime* Ingredient::GetInboundingDate() { return &this->_inbounding_date_; };
Datetime* Ingredient::GetManufacturingDate() { return &this->_manufacturing_date_; };
Datetime* Ingredient::GetExpiryDate() { return &this->_expiry_date_; };
float Ingredient::GetAmount() { return this->_amount_; };
float Ingredient::GetCostPerUnit() { return this->_cost_per_unit_; };
UnitsEnum::Core Ingredient::GetUnit() { return this->_unit_; };

// Setters
void Ingredient::SetName(std::string name) { this->_name_ = name; };
void Ingredient::SetInboundingDate(std::string date) { this->_inbounding_date_ = Datetime(date); };
void Ingredient::SetManufacturingDate(std::string date) { this->_manufacturing_date_ = Datetime(date); };
void Ingredient::SetExpiryDate(std::string date) { this->_expiry_date_ = Datetime(date); };
void Ingredient::SetAmount(float amount) { this->_amount_ = amount; };
void Ingredient::SetCostPerUnit(float cpu) { this->_cost_per_unit_ = cpu; };
void Ingredient::SetUnit(UnitsEnum::Core en) { this->_unit_ = en; };

// Other methods
std::string Ingredient::GetUnitStr() { return Utils::Enum::GetUnitEnumStr(this->_unit_); };
void Ingredient::Print() {
  std::cout
    << "Name: " << this->_name_ << ";  "
    << "IB Date: " << this->GetInboundingDate()->GetDateStr() << ";  "
    << "Manu Date: " << this->GetManufacturingDate()->GetDateStr() << ";  "
    << "Exp Date: " << this->GetExpiryDate()->GetDateStr() << ";  "
    << "Amount: " << this->_amount_ << ";  "
    << "Unit: " << this->GetUnitStr() << ";  "
    << "Cost/Unit: " << this->_cost_per_unit_ << "\n";
};

void Ingredient::PrintOnlyData() {
  std::cout
    << this->_name_ << ";  "
    << this->GetInboundingDate()->GetDateStr() << ";  "
    << this->GetManufacturingDate()->GetDateStr() << ";  "
    << this->GetExpiryDate()->GetDateStr() << ";  "
    << this->_amount_ << ";  "
    << this->GetUnitStr() << ";  "
    << this->_cost_per_unit_ << "\n";
};

};

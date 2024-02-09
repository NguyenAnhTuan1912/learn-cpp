#include <iterator>

#include "Product.h"

// Add utils
#include "../../utils/enum_utils/enum_utils.h"

namespace CoffeeShop {

//
// Product
//
Product::Product(
  std::string name,
  unsigned short base_cost
) {
  this->_name_ = name;
  this->_base_cost_ = base_cost;
};

// Getters
std::string Product::GetId() { return this->_id_; };
std::string Product::GetName() { return this->_name_; };
unsigned short Product::GetBaseCost() { return this->_base_cost_; };

// Setters
void Product::SetName(std::string name) { this->_name_ = name; };
void Product::SetBaseCost(unsigned short bc) { this->_base_cost_ = bc; };

// Other methods
void Product::Print() {
  std::cout
    << "Name: " << this->_name_ << ";  "
    << "Cost: " << this->_base_cost_ << "\n";
};
void Product::PrintOnlyData() {
  std::cout
    << this->_name_ << ";  "
    << this->_base_cost_ << "\n";
};

//
// Drink
//
Drink::Drink(
  std::string name,
  DrinkTypesEnum::Core type_of_drink,
  unsigned short base_cost
): Product(name, base_cost) {
  this->_type_of_drink_ = type_of_drink;
};

// Getters
DrinkSizesEnum::Core Drink::GetSizeOfDrink() { return this->_size_of_drink_; };
DrinkTypesEnum::Core Drink::GetTypeOfDrink() { return this->_type_of_drink_; };

// Setters
void Drink::SetSizeOfDrink(DrinkSizesEnum::Core en) { this->_size_of_drink_ = en; };
void Drink::SetTypeOfDrink(DrinkTypesEnum::Core en) { this->_type_of_drink_ = en; };

// Other methods
std::string Drink::GetSizeOfDrinkStr() { return Utils::Enum::GetDrinkSizeEnumStr(this->_size_of_drink_); };
std::string Drink::GetTypeOfDrinkStr() { return Utils::Enum::GetDrinkTypeEnumStr(this->_type_of_drink_); };
void Drink::Print() {
  std::cout
    << "Name: " << this->GetName() << ";  "
    << "Cost: " << this->GetBaseCost() << ";  "
    << "Size: " << Utils::Enum::GetDrinkSizeEnumStr(this->_size_of_drink_) << ";  "
    << "Type of drink: " << Utils::Enum::GetDrinkTypeEnumStr(this->_type_of_drink_) << "\n";
};
void Drink::PrintOnlyData() {
  std::cout
    << this->GetName() << ";  "
    << this->GetBaseCost() << ";  "
    << Utils::Enum::GetDrinkSizeEnumStr(this->_size_of_drink_) << ";  "
    << Utils::Enum::GetDrinkTypeEnumStr(this->_type_of_drink_) << "\n";
};

//
// Snack
//
Snack::Snack(
  std::string name,
  SnackTypesEnum::Core type_of_snack,
  unsigned short base_cost
): Product(name, base_cost) {
  this->_type_of_snack_ = type_of_snack;
};

// Getters
SnackTypesEnum::Core Snack::GetTypeOfSnack() { return this->_type_of_snack_; };

// Setters
void Snack::SetTypeOfSnack(SnackTypesEnum::Core en) { this->_type_of_snack_ = en; };

// Other methods
std::string Snack::GetTypeOfSnackStr() { return Utils::Enum::GetSnackTypeEnumStr(this->_type_of_snack_); };
void Snack::Print() {
  std::cout
    << "Name: " << this->GetName() << ";  "
    << "Cost: " << this->GetBaseCost() << ";  "
    << "Type of snack: " << Utils::Enum::GetSnackTypeEnumStr(this->_type_of_snack_) << "\n";
};
void Snack::PrintOnlyData() {
  std::cout
    << this->GetName() << ";  "
    << this->GetBaseCost() << ";  "
    << Utils::Enum::GetSnackTypeEnumStr(this->_type_of_snack_) << "\n";
};

};

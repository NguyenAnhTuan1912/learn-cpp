#include "Product.h"

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
std::vector<Ingredient>* Product::GetIngredients() { return &this->_ingredients_; };
unsigned short Product::GetBaseCost() { return this->_base_cost_; };

// Setters
void Product::SetName(std::string name) { this->_name_ = name; };
void Product::SetBaseCost(unsigned short bc) { this->_base_cost_ = bc; };

// Other methods
void Product::AddIngredient(Ingredient& idg) { this->_ingredients_.push_back(idg); };

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
std::vector<DrinkSizesEnum::Core> Drink::GetSizeOfDrink() { return this->_size_of_drink_; };
DrinkTypesEnum::Core Drink::GetTypeOfDrink() { return this->_type_of_drink_; };

// Setters
void Drink::SetTypeOfDrink(DrinkTypesEnum::Core en) { this->_type_of_drink_ = en; };

// Other methods
std::string Drink::GetTypeOfDrinkStr() { return Utils::Enum::GetDrinkTypeEnumStr(this->_type_of_drink_); };
void Drink::AddSize(DrinkSizesEnum::Core s) { this->_size_of_drink_.push_back(s); };

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
};

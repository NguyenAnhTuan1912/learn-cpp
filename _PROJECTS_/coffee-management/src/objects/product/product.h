#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <vector>
#include <ctime>

// Add enums
#include "../../enums/enums.h"

// Add objects
#include "../ingredient/Ingredient.h"

namespace CoffeeShop {

class Product {
private:
  std::string _id_;
  std::string _name_;
  std::vector<Ingredient*> _ingredients_;
  unsigned short _base_cost_;

public:
  Product() = default;
  Product(
    std::string name,
    unsigned short base_cost
  );

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetName() final { return this->_name_; };
  virtual td::vector<Ingredient*> GetIngredients() final { return this->_ingredients_; };
  virtual unsigned short GetBaseCost() final { return this->_base_cost_; };

  // Setters
  virtual void SetName(std::string name) final { this->_name_ = name; };
  virtual void SetBaseCost(unsigned short bc) final { this->_base_cost_ = bc; };

  // Other methods
  virtual void AddIngredient(Ingredient& idg) final { this->_ingredients_.push_back(idg); };
};

class Drink : public Product {
private:
  std::vector<DrinkSizesEnum::Core> _size_of_drink_;
  DrinkTypesEnum::Core _type_of_drink_;

public:
  Drink() = default;
  Drink(
    std::string name,
    DrinkTypesEnum::Core type_of_drink,
    unsigned short base_cost
  );

  // Getters
  virtual std::vector<DrinkSizesEnum::Core> GetSizeOfDrink() final { return this->_size_of_drink_; };
  virtual DrinkTypesEnum::Core GetTypeOfDrink() final { return this->_type_of_drink_; };

  // Setters
  virtual void SetTypeOfDrink(DrinkTypesEnum::Core en) final { this->_type_of_drink_ = en; };

  // Other methods
  virtual std::string GetTypeOfDrinkStr() final { return Utils::Enum::GetDrinkTypeEnumStr(this->_type_of_drink_); };
  virtual DrinkSizesEnum::Core AddSize(DrinkSizesEnum::Core s) final { this->_size_of_drink_.push_back(s); };
};

class Snack : public Product {
private:
  SnackTypesEnum::Core _type_of_snack_;

public:
  Snack() = default;
  Snack(
    std::string name,
    SnackTypesEnum::Core type_of_snack,
    unsigned short base_cost
  );

  // Getters
  virtual SnackTypesEnum::Core GetTypeOfSnack() final { return this->_type_of_snack_; };

  // Setters
  virtual void SetTypeOfSnack(SnackTypesEnum::Core en) final { this->_type_of_snack_ = en; };

  // Other methods
  virtual std::string GetTypeOfSnackStr() final { return Utils::Enum::GetSnackTypeEnumStr(this->_type_of_snack_); };
};

};

#endif // PRODUCT_H_INCLUDED

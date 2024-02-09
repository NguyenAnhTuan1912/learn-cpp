#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <vector>
#include <ctime>

// Add enums
#include "../../utils/string_utils/string_utils.h"
#include "../../enums/enums.h"

// Add objects
#include "../ingredient/Ingredient.h"

namespace CoffeeShop {

class Product {
private:
  std::string _id_ = Utils::String::GenerateRandom("Product");
  std::string _name_;
  unsigned short _base_cost_ = 0;

public:
  Product() = default;
  Product(
    std::string name,
    unsigned short base_cost
  );

  // Getters
  virtual std::string GetId() final;
  virtual std::string GetName() final;
  virtual unsigned short GetBaseCost() final;

  // Setters
  virtual void SetName(std::string name) final;
  virtual void SetBaseCost(unsigned short bc) final;

  // Other methods
  virtual void Print();
  virtual void PrintOnlyData();
};

class Drink : public Product {
private:
  DrinkSizesEnum::Core _size_of_drink_ = DrinkSizesEnum::Empty;
  DrinkTypesEnum::Core _type_of_drink_ = DrinkTypesEnum::Empty;

public:
  Drink() = default;
  Drink(
    std::string name,
    DrinkTypesEnum::Core type_of_drink,
    unsigned short base_cost
  );

  // Getters
  virtual DrinkSizesEnum::Core GetSizeOfDrink() final;
  virtual DrinkTypesEnum::Core GetTypeOfDrink() final;

  // Setters
  virtual void SetSizeOfDrink(DrinkSizesEnum::Core en) final;
  virtual void SetTypeOfDrink(DrinkTypesEnum::Core en) final;

  // Other methods
  virtual std::string GetSizeOfDrinkStr() final;
  virtual std::string GetTypeOfDrinkStr() final;
  virtual void Print();
  virtual void PrintOnlyData();
};

class Snack : public Product {
private:
  SnackTypesEnum::Core _type_of_snack_ = SnackTypesEnum::Empty;

public:
  Snack() = default;
  Snack(
    std::string name,
    SnackTypesEnum::Core type_of_snack,
    unsigned short base_cost
  );

  // Getters
  virtual SnackTypesEnum::Core GetTypeOfSnack() final;

  // Setters
  virtual void SetTypeOfSnack(SnackTypesEnum::Core en) final;

  // Other methods
  virtual std::string GetTypeOfSnackStr() final;
  virtual void Print();
  virtual void PrintOnlyData();
};

};

#endif // PRODUCT_H_INCLUDED

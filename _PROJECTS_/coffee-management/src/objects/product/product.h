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
  std::vector<Ingredient> _ingredients_;
  unsigned short _base_cost_;

public:
  Product() = default;
  Product(
    std::string name,
    unsigned short base_cost
  );

  // Getters
  virtual std::string GetId() final;
  virtual std::string GetName() final;
  virtual std::vector<Ingredient>* GetIngredients() final;
  virtual unsigned short GetBaseCost() final;

  // Setters
  virtual void SetName(std::string name) final;
  virtual void SetBaseCost(unsigned short bc) final;

  // Other methods
  virtual void AddIngredient(Ingredient& idg) final;
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
  virtual std::vector<DrinkSizesEnum::Core> GetSizeOfDrink() final;
  virtual DrinkTypesEnum::Core GetTypeOfDrink() final;

  // Setters
  virtual void SetTypeOfDrink(DrinkTypesEnum::Core en) final;

  // Other methods
  virtual std::string GetTypeOfDrinkStr() final;
  virtual void AddSize(DrinkSizesEnum::Core s);
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
  virtual SnackTypesEnum::Core GetTypeOfSnack() final;

  // Setters
  virtual void SetTypeOfSnack(SnackTypesEnum::Core en) final;

  // Other methods
  virtual std::string GetTypeOfSnackStr() final;
};

};

#endif // PRODUCT_H_INCLUDED

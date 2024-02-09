#include <conio.h>
#include <string>
#include <exception>

#include "ProductScreen.h"

// Add objects
// #include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/types.h"

// Add utils
#include "../../utils/string_utils/string_utils.h"
#include "../../utils/enum_utils/enum_utils.h"

// Hidden from Translation Units
namespace {

CoffeeShop::Types::DataListPrintCallBack<CoffeeShop::Snack>
PrintSnackData = [](CoffeeShop::Snack& item, int index) {
  std::cout << index << ". ";
  item.Print();
  std::cout << "\n";
};

CoffeeShop::Types::DataListPrintCallBack<CoffeeShop::Drink>
PrintDrinkData = [](CoffeeShop::Drink& item, int index) {
  std::cout << index << ". ";
  item.Print();
  std::cout << "\n";
};

};

namespace CoffeeShop {

void ProductScreen::Render() {
  std::cout << "Snacks: \n";
  if(this->_snack_data_.GetData()->size() == 0)
    std::cout << "Snack List is empty. Please add some products to start!!!\n";
  else {
    this->_snack_data_.Print(::PrintSnackData);
    std::cout << "Page: " << this->_snack_data_.GetCurrentPage() << " | ";
    std::cout << "q. Previous; p. Next\n";
  };

  std::cout << "-----\n";

  std::cout << "Drinks: \n";
  if(this->_drink_data_.GetData()->size() == 0)
    std::cout << "Snack List is empty. Please add some products to start!!!\n";
  else {
    this->_drink_data_.Print(::PrintDrinkData);
    std::cout << "Page: " << this->_drink_data_.GetCurrentPage() << " | ";
    std::cout << "a. Previous; l. Next\n";
  };
};

void ProductScreen::PerformAddProduct(Product& prod) {
  std::string text_tmp;

  std::cout << "~~Add Product~~" << std::endl;

  // Get name
  std::cout << "Enter name: ";
  // If lastname is empty, fill to text_tmp and set lastname.
  if(Utils::String::IsStringEmpty(prod.GetName())) {
      std::getline(std::cin, text_tmp);
      prod.SetName(text_tmp);
  }
  else std::cout << prod.GetName() << std::endl;

  // Get base cost
  std::cout << "Enter base cost: ";
  if(prod.GetBaseCost() == 0) {
    std::getline(std::cin, text_tmp);
    prod.SetBaseCost(std::stoi(text_tmp));
  }
};

bool ProductScreen::PerformAddDrink() {
  try {
    this->PerformAddProduct(this->_drk_holder_);

    std::cout << "Enter drink type: \n";
    if(this->_drk_holder_.GetTypeOfDrink() == DrinkTypesEnum::Empty)
      this->_drk_holder_.SetTypeOfDrink(Utils::Enum::GetDrinkTypeEnum());
    else std::cout << "Selected: " << this->_drk_holder_.GetTypeOfDrinkStr() << std::endl;

    std::cout << "Enter drink size: \n";
    if(this->_drk_holder_.GetSizeOfDrink() == DrinkSizesEnum::Empty)
      this->_drk_holder_.SetSizeOfDrink(Utils::Enum::GetDrinkSizeEnum());
    else std::cout << "Selected: " << this->_drk_holder_.GetSizeOfDrinkStr() << std::endl;

    // Add to list
    this->_drink_data_.AddItem(this->_drk_holder_.GetId(), this->_drk_holder_);
    this->_drk_holder_ = Drink();

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    if(!this->DeciseToContinue()) this->_drk_holder_ = Drink();
    return true;
  }
};

bool ProductScreen::PerformAddSnack() {
  try {
    this->PerformAddProduct(this->_snk_holder_);

    std::cout << "Enter snack type: \n";
    if(this->_snk_holder_.GetTypeOfSnack() == SnackTypesEnum::Empty)
      this->_snk_holder_.SetTypeOfSnack(Utils::Enum::GetSnackTypeEnum());
    else std::cout << "Selected: " << this->_snk_holder_.GetTypeOfSnackStr() << std::endl;

    // Add to list
    this->_snack_data_.AddItem(this->_snk_holder_.GetId(), this->_snk_holder_);
    this->_snk_holder_ = Snack();

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    if(!this->DeciseToContinue()) this->_snk_holder_ = Snack();
    return true;
  }
};

bool ProductScreen::PerformDeleteProduct(auto& data) {
  try {
    if(data.GetData()->size() == 0) {
      std::cout << "There aren't snacks or drinks in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Types::LimitedKeyCode confirm_key;
    int num;
    std::cout << "~~Delete Product~~" << std::endl;
    std::cout << "Enter the snack or drink's number that you want to delete: ";
    std::cin >> num;

    std::cout << "Are you sure? 1. Yes; 2. No\n";

    // Waiting for user to enter key
    while(confirm_key != KEY_1 && confirm_key != KEY_2) {
      confirm_key = getch();
      if(confirm_key == KEY_1) {
          data.DeleteItem(num - 1);
          std::cout << "Deleted\n";
      };
      if(confirm_key == KEY_2) continue;
    };

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    this->DeciseToContinue();
    return true;
  };
};

bool ProductScreen::PerformDeleteSnack() {
  return this->PerformDeleteProduct(this->_snack_data_);
};

bool ProductScreen::PerformDeleteDrink() {
  return this->PerformDeleteProduct(this->_drink_data_);
};

Product* ProductScreen::PerformUpdateProduct(auto& data) {
  int num;

  std::cout << "~~Update product~~" << std::endl;
  std::cout << "If has any field don't need to change, please press [Enter] (or depend on guide) to skip.\n";
  std::cout << "Enter the employee's number that you want to UPDATE: ";
  std::cin >> num;

  Product* ptr_prod = data.GetItem(num - 1);
  std::string text_tmp = "";

  std::cout << "Old data: \n"; ptr_prod->PrintOnlyData(); std::cout << std::endl;

  // Change data flow below
  // Update last name
  std::cout << "Update name: ";
  std::cin.ignore();
  std::getline(std::cin, text_tmp);
  if(!Utils::String::IsStringEmpty(text_tmp)) {
    ptr_prod->SetName(text_tmp);
  };

  std::cout << "Update base cost: ";
  std::getline(std::cin, text_tmp);
  if(!Utils::String::IsStringEmpty(text_tmp)) {
    ptr_prod->SetBaseCost(std::stoi(text_tmp));
  };

  return ptr_prod;
};

bool ProductScreen::PerformUpdateDrink() {
  try {
    if(this->_drink_data_.GetData()->size() == 0) {
      std::cout << "There aren't drinks in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Drink* ptr_drk = (Drink*)this->PerformUpdateProduct(this->_drink_data_);

    Types::LimitedKeyCode select;

    // Update type
    std::cout << "Update drink type (Press [any] except [Enter] to modify):\n";
    select = getch();
    if(!Utils::String::IsStringEmpty(std::string(1, select))) {
      ptr_drk->SetTypeOfDrink(Utils::Enum::GetDrinkTypeEnum());
    };

    // Update size
    std::cout << "Update drink size (Press [any] except [Enter] to modify):\n";
    select = getch();
    if(!Utils::String::IsStringEmpty(std::string(1, select))) {
      ptr_drk->SetSizeOfDrink(Utils::Enum::GetDrinkSizeEnum());
    };

    std::cout << "Update done! Press any key to continue.\n";
    getch();

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    this->DeciseToContinue();
    return true;
  };
};

bool ProductScreen::PerformUpdateSnack() {
  try {
    if(this->_snack_data_.GetData()->size() == 0) {
      std::cout << "There aren't drinks in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Snack* ptr_snk = (Snack*)this->PerformUpdateProduct(this->_snack_data_);

    Types::LimitedKeyCode select;

    // Update type
    std::cout << "Update snack type (Press [any] except [Enter] to modify):\n";
    select = getch();
    if(!Utils::String::IsStringEmpty(std::string(1, select))) {
      ptr_snk->SetTypeOfSnack(Utils::Enum::GetSnackTypeEnum());
    };

    std::cout << "Update done! Press any key to continue.\n";
    getch();

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    this->DeciseToContinue();
    return true;
  };
};

bool ProductScreen::SelectFeature(Types::LimitedKeyCode key) {
  switch(this->GetPreviousFeatureKey() != 0 ? this->GetPreviousFeatureKey() : key) {
    case KEY_1: {
      return this->PerformAddDrink();
    };

    case KEY_2: {
      return this->PerformDeleteDrink();
    };

    case KEY_3: {
      return this->PerformUpdateDrink();
    };

    case KEY_4: {
      return this->PerformAddSnack();
    };

    case KEY_5: {
      return this->PerformDeleteSnack();
    };

    case KEY_6: {
      return this->PerformUpdateDrink();
    };

    case KEY_q: {
      this->_snack_data_.Previous();
      this->SetPreviousFeatureKey(0);
      return true;
    };

    case KEY_p: {
      this->_snack_data_.Next();
      this->SetPreviousFeatureKey(0);
      return true;
    };

    case KEY_a: {
      this->_drink_data_.Previous();
      this->SetPreviousFeatureKey(0);
      return true;
    };

    case KEY_l: {
      this->_drink_data_.Next();
      this->SetPreviousFeatureKey(0);
      return true;
    };

    default: {
      std::cout << "Snack management features:\n";
      std::cout << "1. Add new drink\n";
      std::cout << "2. Delete a drink\n";
      std::cout << "3. Update a drink\n";
      std::cout << "4. Add new snack\n";
      std::cout << "5. Delete a snack\n";
      std::cout << "6. Update a snack\n";
      return false;
    };
  };
};

};

#include <conio.h>
#include <string>
#include <exception>

#include "IngredientScreen.h"

// Add objects
// #include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/types.h"

// Add utils
#include "../../utils/string_utils/string_utils.h"
#include "../../utils/enum_utils/enum_utils.h"

// Hidden from Translation Units
namespace {

CoffeeShop::Types::DataListPrintCallBack<CoffeeShop::Ingredient>
PrintData = [](CoffeeShop::Ingredient& item, int index) {
  std::cout << index << ". ";
  item.Print();
  std::cout << "\n";
};

bool IsManufacturingValid(std::string date) {
  CoffeeShop::Datetime t(time(0)), manuf_date(date);
  return !(manuf_date >= t);
};

};

namespace CoffeeShop {

void IngredientScreen::Render() {
  if(this->_data_.GetData()->size() == 0)
    std::cout << "Ingredient List is empty. Please add some ingredients to start!!!\n";
  else {
    this->_data_.Print(::PrintData);
  };
};

bool IngredientScreen::PerformAddIngredient() {
  try {
    std::string text_tmp;

    std::cout << "~~Add Ingredient~~" << std::endl;


    // Get last name
    std::cout << "Enter name: ";
    // If lastname is empty, fill to text_tmp and set lastname.
    if(Utils::String::IsStringEmpty(this->_igd_holder_.GetName())) {
        std::getline(std::cin, text_tmp);
        this->_igd_holder_.SetName(text_tmp);
    }
    else std::cout << this->_igd_holder_.GetName() << std::endl;

    // Get manufacturing date
    std::cout << "Enter manufacturing date: ";
    if(this->_igd_holder_.GetManufacturingDate()->IsNull()) {
      std::getline(std::cin, text_tmp);

      if(!(::IsManufacturingValid(text_tmp)))
        throw std::runtime_error("Manufacturing date cannot larger than now");

      // If match, set new birthdate
      this->_igd_holder_.SetManufacturingDate(text_tmp);
    }
    else std::cout << this->_igd_holder_.GetManufacturingDate()->GetDateStr() << std::endl;

    // Get expiry date
    std::cout << "Enter expiry date: ";
    if(this->_igd_holder_.GetExpiryDate()->IsNull()) {
      std::getline(std::cin, text_tmp);

      // If expiry date is equal to or less than manufacturing date,
      // expiry is invalid.
      if(*(this->_igd_holder_.GetManufacturingDate()) >= text_tmp)
        throw std::runtime_error("Expiry date must be larger than manufacturing date");

      // If match, set new birthdate
      this->_igd_holder_.SetExpiryDate(text_tmp);
    }
    else std::cout << this->_igd_holder_.GetExpiryDate()->GetDateStr() << std::endl;

    // Get inbouding date
    std::cout << "Enter inbounding date: ";
    if(this->_igd_holder_.GetInboundingDate()->IsNull()) {
      std::getline(std::cin, text_tmp);

      if(
         *(this->_igd_holder_.GetManufacturingDate()) >= text_tmp ||
         *(this->_igd_holder_.GetExpiryDate()) <= text_tmp
      )
        throw std::runtime_error("Indounding date is invalid. Cannot import products when it haven't product yet or expiried.");

      // If match, set new birthdate
      this->_igd_holder_.SetInboundingDate(text_tmp);
    }
    else std::cout << this->_igd_holder_.GetInboundingDate()->GetDateStr() << std::endl;

    // Get amount
    std::cout << "Enter amount: ";
    if(this->_igd_holder_.GetAmount() == 0) {
      std::getline(std::cin, text_tmp);
      this->_igd_holder_.SetAmount(std::stoi(text_tmp));
    }
    else std::cout << this->_igd_holder_.GetAmount() << std::endl;

    // Get cost per unit
    std::cout << "Enter cost/unit: ";
    if(this->_igd_holder_.GetCostPerUnit() == 0) {
      std::getline(std::cin, text_tmp);
      this->_igd_holder_.SetCostPerUnit(std::stoi(text_tmp));
    }
    else std::cout << this->_igd_holder_.GetCostPerUnit() << std::endl;

    // Get unit type
    std::cout << "Enter unit type: \n";
    if(this->_igd_holder_.GetUnit() == UnitsEnum::Empty)
      this->_igd_holder_.SetUnit(Utils::Enum::GetUnitEnum());
    else std::cout << "Selected: " << this->_igd_holder_.GetUnitStr() << std::endl;

    this->_data_.AddItem(this->_igd_holder_.GetId(), this->_igd_holder_);
    // Reset the holder when it is added to list.
    this->_igd_holder_ = Ingredient();

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    if(!this->DeciseToContinue()) this->_igd_holder_ = Ingredient();
    return true;
  }
};

bool IngredientScreen::PerformDeleteIngredient() {
  try {
    if(this->_data_.GetData()->size() == 0) {
      std::cout << "There aren't ingredients in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Types::LimitedKeyCode confirm_key;
    int num;
    std::cout << "~~Delete Ingredients~~" << std::endl;
    std::cout << "Enter the ingredient's number that you want to delete: ";
    std::cin >> num;

    std::cout << "Are you sure? 1. Yes; 2. No\n";

    // Waiting for user to enter key
    while(confirm_key != KEY_1 && confirm_key != KEY_2) {
      confirm_key = getch();
      if(confirm_key == KEY_1) {
          this->_data_.DeleteItem(num - 1);
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

bool IngredientScreen::PerformUpdateIngredient() {
  try {
    if(this->_data_.GetData()->size() == 0) {
      std::cout << "There aren't ingredients in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Types::LimitedKeyCode unit_type_key;
    int num;

    std::cout << "~~Update Ingredient~~" << std::endl;
    std::cout << "If has any field don't need to change, please press [Enter] (or depend on guide) to skip.\n";
    std::cout << "Enter the ingredient's number that you want to UPDATE: ";
    std::cin >> num;

    Ingredient* ptr_igd = this->_data_.GetItem(num - 1);
    std::string text_tmp = "";

    std::cout << "Old data: \n"; ptr_igd->PrintOnlyData(); std::cout << std::endl;

    // Change data flow below
    // Update name
    std::cout << "Update name: ";
    std::cin.ignore();
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_igd->SetName(text_tmp);
    };

    // Update manufacturing date
    std::cout << "Update manufacturing date: ";
    std::getline(std::cin, text_tmp);
    if(!(::IsManufacturingValid(text_tmp)))
      throw std::runtime_error("Manufacturing date cannot larger than now");

    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_igd->SetManufacturingDate(text_tmp);
    };

    // Update expiry date
    std::cout << "Update expiry date: ";
    std::getline(std::cin, text_tmp);

    if(!(::IsManufacturingValid(text_tmp)))
      throw std::runtime_error("Manufacturing date cannot larger than now");

    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_igd->SetExpiryDate(text_tmp);
    };

    // Update inbounding date
    std::cout << "Update inbounding date: ";
    std::getline(std::cin, text_tmp);

    if(
      *(this->_igd_holder_.GetManufacturingDate()) >= text_tmp ||
      *(this->_igd_holder_.GetExpiryDate()) <= text_tmp
    )
      throw std::runtime_error("Indounding date is invalid. Cannot import products when it haven't product yet or expiried.");

    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_igd->SetInboundingDate(text_tmp);
    };

    // Get amount
    std::cout << "Update amount: ";
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_igd->SetAmount(std::stoi(text_tmp));
    };

    // Get cost/unit
    std::cout << "Update cost/unit: ";
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_igd->SetCostPerUnit(std::stoi(text_tmp));
    };

    // Get unit type
    std::cout << "Update unit type (Press [any] except [Enter] to modify):\n";
    unit_type_key = getch();
    if(!Utils::String::IsStringEmpty(std::string(1, unit_type_key))) {
      ptr_igd->SetUnit(Utils::Enum::GetUnitEnum());
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

bool IngredientScreen::SelectFeature(Types::LimitedKeyCode key) {
  switch(this->GetPreviousFeatureKey() != 0 ? this->GetPreviousFeatureKey() : key) {
    case KEY_1: {
      return this->PerformAddIngredient();
    };

    case KEY_2: {
      return this->PerformDeleteIngredient();
    };

    case KEY_3: {
      return this->PerformUpdateIngredient();
    };

    default: {
      std::cout << "Ingredient management features:\n";
      std::cout << "1. Add new ingredient\n";
      std::cout << "2. Delete an ingredient\n";
      std::cout << "3. Update an ingredient\n";
      return false;
    };
  };
};

};

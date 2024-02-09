#include <conio.h>
#include <string>
#include <exception>

#include "EmployeeScreen.h"

// Add objects
// #include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/types.h"

// Add utils
#include "../../utils/string_utils/string_utils.h"
#include "../../utils/enum_utils/enum_utils.h"

// Hidden from Translation Units
namespace {

CoffeeShop::Types::DataListPrintCallBack<CoffeeShop::Employee>
PrintData = [](CoffeeShop::Employee& item, int index) {
  std::cout << index << ". ";
  item.Print();
  std::cout << "\n";
};

bool IsBirthDateValid(CoffeeShop::Datetime& dt) {
  CoffeeShop::Datetime t(time(0));
  return !(t.GetDateStr() == dt.GetDateStr());
};

};

namespace CoffeeShop {

bool EmployeeScreen::IsAgeSuitableForWork(std::string datetime) {
  Datetime test(datetime);

  if(this->_employee_max_birthdate_ > test) return false;
  if(this->_employee_min_birthdate_ < test) return false;

  return true;
};

void EmployeeScreen::Render() {
  std::cout << "Employees: \n";
  if(this->_data_.GetData()->size() == 0)
    std::cout << "Employee List is empty. Please add some employees to start!!!\n";
  else {
    this->_data_.Print(::PrintData);
  };
};

bool EmployeeScreen::PerformAddEmployee() {
  try {
    Types::LimitedKeyCode gender_key;
    std::string text_tmp;

    std::cout << "~~Add Employee~~" << std::endl;


    // Get last name
    std::cout << "Enter last name: ";
    // If lastname is empty, fill to text_tmp and set lastname.
    if(Utils::String::IsStringEmpty(this->_emp_holder_.GetLastName())) {
        std::getline(std::cin, text_tmp);
        this->_emp_holder_.SetLastName(text_tmp);
    }
    else std::cout << this->_emp_holder_.GetLastName() << std::endl;

    // Get first name
    std::cout << "Enter first name: ";
    // If firstname is empty, fill to text_tmp and set firstname.
    if(Utils::String::IsStringEmpty(this->_emp_holder_.GetFirstName())) {
        std::getline(std::cin, text_tmp);
        this->_emp_holder_.SetFirstName(text_tmp);
    }
    else std::cout << this->_emp_holder_.GetFirstName() << std::endl;

    // Get birthday
    std::cout << "Enter birthday: ";
    if(!(::IsBirthDateValid(*(this->_emp_holder_.GetBirthDate())))) {
      std::getline(std::cin, text_tmp);

      // Is birthdate of this person is match with requirement?
      if(!this->IsAgeSuitableForWork(text_tmp))
        throw std::runtime_error("This person's age isn't suitable for work!!!");

      // If match, set new birthdate
      this->_emp_holder_.SetBirthDate(text_tmp);
    }
    else std::cout << this->_emp_holder_.GetBirthDateStr() << std::endl;

    // Get salary/hour
    std::cout << "Enter salary/hour: ";
    if(this->_emp_holder_.GetSalaryPerHour() == 0) {
      std::getline(std::cin, text_tmp);
      this->_emp_holder_.SetSalaryPerHour(std::stoi(text_tmp));
    }
    else std::cout << this->_emp_holder_.GetSalaryPerHour() << std::endl;

    // Get gender
    std::cout << "Enter gender: ";
    std::cout << "1. Male; [any]. Female\n";
    gender_key = getch();
    if(gender_key == KEY_1) this->_emp_holder_.SetGender(true);
    else this->_emp_holder_.SetGender(false);

    // Get shift type
    std::cout << "Enter shift type: \n";
    if(this->_emp_holder_.GetShiftType() == ShiftsEnum::Empty)
      this->_emp_holder_.SetShiftType(Utils::Enum::GetShiftEnum());
    else std::cout << "Selected: " << this->_emp_holder_.GetShiftTypeStr() << std::endl;

    this->_data_.AddItem(this->_emp_holder_.GetId(), this->_emp_holder_);
    // Reset the holder when it is added to list.
    this->_emp_holder_ = Employee();

    this->SetPreviousFeatureKey(0);

    return true;
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    // Reset if doesn't continue.
    if(!this->DeciseToContinue()) this->_emp_holder_ = Employee();
    return true;
  }
};

bool EmployeeScreen::PerformDeleteEmployee() {
  try {
    if(this->_data_.GetData()->size() == 0) {
      std::cout << "There aren't employees in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Types::LimitedKeyCode confirm_key;
    int num;
    std::cout << "~~Delete Employee~~" << std::endl;
    std::cout << "Enter the employee's number that you want to delete: ";
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

bool EmployeeScreen::PerformUpdateEmployee() {
  try {
    if(this->_data_.GetData()->size() == 0) {
      std::cout << "There aren't employees in list. Press any key to continue!!!\n";
      getch();
      this->SetPreviousFeatureKey(0);
      return true;
    }

    Types::LimitedKeyCode gender_key, shift_type_key;
    int num;

    std::cout << "~~Update Employee~~" << std::endl;
    std::cout << "If has any field don't need to change, please press [Enter] (or depend on guide) to skip.\n";
    std::cout << "Enter the employee's number that you want to UPDATE: ";
    std::cin >> num;

    Employee* ptr_emp = this->_data_.GetItem(num - 1);
    std::string text_tmp = "";

    std::cout << "Old data: \n"; ptr_emp->PrintOnlyData(); std::cout << std::endl;

    // Change data flow below
    // Update last name
    std::cout << "Update last name: ";
    std::cin.ignore();
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_emp->SetLastName(text_tmp);
    };

    // Update first name
    std::cout << "Update first name: ";
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_emp->SetFirstName(text_tmp);
    };

    // Update birthdate
    std::cout << "Update birthdate: ";
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_emp->SetBirthDate(text_tmp);
    };

    // Get salary/hour
    std::cout << "Update salary/hour: ";
    std::getline(std::cin, text_tmp);
    if(!Utils::String::IsStringEmpty(text_tmp)) {
      ptr_emp->SetSalaryPerHour(std::stoi(text_tmp));
    };

    // Get gender
    std::cout << "Update gender: ";
    std::cout << "1. Male; 2. Female; [any] to skip \n";
    gender_key = getch();
    if(gender_key == KEY_1) ptr_emp->SetGender(true);
    if(gender_key == KEY_2) ptr_emp->SetGender(false);

    // Get shift type
    std::cout << "Update shift type (Press [any] except [Enter] to modify):\n";
    shift_type_key = getch();
    if(!Utils::String::IsStringEmpty(std::string(1, shift_type_key))) {
      ptr_emp->SetShiftType(Utils::Enum::GetShiftEnum());
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

bool EmployeeScreen::SelectFeature(Types::LimitedKeyCode key) {
  switch(this->GetPreviousFeatureKey() != 0 ? this->GetPreviousFeatureKey() : key) {
    case KEY_1: {
      return this->PerformAddEmployee();
    };

    case KEY_2: {
      return this->PerformDeleteEmployee();
    };

    case KEY_3: {
      return this->PerformUpdateEmployee();
    };

    default: {
      std::cout << "Employee management features:\n";
      std::cout << "1. Add new employee\n";
      std::cout << "2. Delete an employee\n";
      std::cout << "3. Update an employee\n";
      return false;
    };
  };
};

};

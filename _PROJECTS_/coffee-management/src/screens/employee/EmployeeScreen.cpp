#include <conio.h>
#include <string>
#include <exception>

#include "EmployeeScreen.h"

// Add objects
// #include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/types.h"

// Add utils
#include "../../utils/enum_utils/enum_utils.h"

// Hidden from Translation Units
namespace {

CoffeeShop::Types::DataListPrintCallBack<CoffeeShop::Employee>
PrintData = [](CoffeeShop::Employee& item, int index) {
  std::cout << index << ". ";
  item.Print();
  std::cout << "\n";
};

bool IsValidBirthDate(CoffeeShop::Datetime& dt) {
  CoffeeShop::Datetime t;
  return !(t.GetDateStr() == dt.GetDateStr());
};

};

namespace CoffeeShop {

void EmployeeScreen::Render() {
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
    if(this->_emp_holder_.GetLastName() == "" || this->_emp_holder_.GetLastName().length() == 0) {
        std::getline(std::cin, text_tmp);
        this->_emp_holder_.SetLastName(text_tmp);
    }
    else std::cout << this->_emp_holder_.GetLastName() << std::endl;

    // Get first name
    std::cout << "Enter first name: ";
    if(this->_emp_holder_.GetFirstName() == "" || this->_emp_holder_.GetFirstName().length() == 0) {
        std::getline(std::cin, text_tmp);
        this->_emp_holder_.SetFirstName(text_tmp);
    }
    else std::cout << this->_emp_holder_.GetFirstName() << std::endl;

    // Get birthday
    std::cout << "Enter birthday: ";
    if(!(::IsValidBirthDate(*(this->_emp_holder_.GetBirthDate())))) {
      std::getline(std::cin, text_tmp);
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
    // Reset
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
  std::cout << "Delete Employee - Press any key to continute." << std::endl;
  getch();
  return true;
};

bool EmployeeScreen::PerformUpdateEmployee() {
  std::cout << "Update Employee - Press any key to continute." << std::endl;
  getch();
  return true;
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

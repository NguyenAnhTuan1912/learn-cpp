#include <conio.h>

#include "EmployeeScreen.h"

// Hidden from Translation Units
namespace {

};

namespace CoffeeShop {

void EmployeeScreen::Render() {
  if(this->_data_.GetData()->size() == 0)
    std::cout << "Employee List is empty. Please add some employees to start!!!\n";
  else {

  };
};

bool EmployeeScreen::PerformAddEmployee() {
  std::cout << "Add Employee - Press any key to continute." << std::endl;
  getch();
  return true;
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
  switch(key) {
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

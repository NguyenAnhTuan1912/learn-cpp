#ifndef EMPLOYEESCREEN_H_INCLUDED
#define EMPLOYEESCREEN_H_INCLUDED

// Add macros
#include "../../macros/keys.h"

// Add objects
#include "../../objects/screen/Screen.h"
#include "../../objects/data_list/DataList.h"
#include "../../objects/employee/Employee.h"

// Add types
#include "../../types/keys.types.h"

namespace CoffeeShop {

class EmployeeScreen : public Screen {
private:
  DataList<std::string, Employee> _data_;

public:
  EmployeeScreen(): Screen("Employee") {};

  // Other methods
  bool PerformAddEmployee();
  bool PerformDeleteEmployee();
  bool PerformUpdateEmployee();

  void Render();
  bool SelectFeature(Types::LimitedKeyCode key);
};

};

#endif // EMPLOYEESCREEN_H_INCLUDED

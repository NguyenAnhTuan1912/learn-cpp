#ifndef EMPLOYEESCREEN_H_INCLUDED
#define EMPLOYEESCREEN_H_INCLUDED

// Add macros
#include "../../macros/employee_macros.h"
#include "../../macros/keys_macros.h"

// Add objects
#include "../../objects/screen/Screen.h"
#include "../../objects/employee/Employee.h"
#include "../../objects/data_list/DataList.h"
#include "../../objects/datetime/Datetime.h"

// Add types
#include "../../types/keys.types.h"

namespace CoffeeShop {

class EmployeeScreen : public Screen {
private:
  DataList<std::string, Employee> _data_;
  Employee _emp_holder_;
  Datetime _employee_min_birthdate_ = Datetime("01/01/2004");
  Datetime _employee_max_birthdate_ = Datetime("01/01/1970");

public:
  EmployeeScreen(): Screen("Employee") {};

  // Other methods
  /** \brief Use to check age of person is suitable for work
   *
   * \param datetime A datetime as string that wanted to check
   * \return
   *
   */
  bool IsAgeSuitableForWork(std::string datetime);

  /** \brief Use to perform "add employee" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformAddEmployee();

  /** \brief Use to perform "delete employee" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformDeleteEmployee();

  /** \brief Use to perform "update employee" action.
   *
   * \return
   *
   * View more in source file.
   */
  bool PerformUpdateEmployee();

  void Render();
  bool SelectFeature(Types::LimitedKeyCode key);
};

};

#endif // EMPLOYEESCREEN_H_INCLUDED

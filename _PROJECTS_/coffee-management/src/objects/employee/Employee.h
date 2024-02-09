#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <ctime>

// Add enums
#include "../../enums/enums.h"

// Add objects
#include "../datetime/Datetime.h"

// Add utils
#include "../../utils/enum_utils/enum_utils.h"
#include "../../utils/string_utils/string_utils.h"

namespace CoffeeShop {

class Employee {
private:
  std::string _id_ = Utils::String::GenerateRandom("employee");
  std::string _last_name_;
  std::string _first_name_;
  Datetime _birth_date_;
  bool _gender_ = NULL;
  ShiftsEnum::Core _shift_type_ = ShiftsEnum::Empty;
  unsigned short _salary_per_hour_ = 0;

public:
  Employee() = default;
  Employee(
    std::string last_name,
    std::string first_name,
    std::string birth_date,
    bool gender = true,
    ShiftsEnum::Core shift_type = ShiftsEnum::FullTime,
    unsigned short salary_per_hour = 20
  );

  // Getters
  virtual std::string GetId() final;
  virtual std::string GetLastName() final;
  virtual std::string GetFirstName() final;
  virtual Datetime* GetBirthDate() final;
  virtual bool GetGender() final;
  virtual ShiftsEnum::Core GetShiftType() final;
  virtual unsigned short GetSalaryPerHour() final;

  // Setters
  virtual void SetLastName(std::string last_name) final;
  virtual void SetFirstName(std::string first_name) final;
  virtual void SetBirthDate(std::string birth_date) final;
  virtual void SetGender(bool gender) final;
  virtual void SetShiftType(ShiftsEnum::Core en) final;
  virtual void SetSalaryPerHour(unsigned short sph) final;

  // Other methods
  virtual std::string GetBirthDateStr() final;
  virtual std::string GetShiftTypeStr() final;
  virtual std::string GetGenderStr() final;
  virtual std::string GetFullName() final;
  virtual int GetAge() final;

  /** \brief Use to print full information of Employee
   *
   * \return
   *
   */

  virtual void Print() final;

  /** \brief Use to print only data, seperate by ";"
   *
   * \return
   *
   */
  virtual void PrintOnlyData() final;
};

};

#endif // EMPLOYEE_H_INCLUDED

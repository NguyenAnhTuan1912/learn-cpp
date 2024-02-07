#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <ctime>

// Add objects
#include "../datetime/Datetime.h"

// Add enums
#include "../../enums/enums.h"

namespace CoffeeShop {

class Employee {
private:
  std::string _id_;
  std::string _last_name_;
  std::string _first_name_;
  Datetime _birth_date_;
  bool _gender_;
  ShiftsEnum::Core _shift_type_;
  unsigned short _salary_per_hour_;

public:
  Employee() = default;

  // Getters
  virtual std::string GetId() final { return this->_id_; };
  virtual std::string GetLastName() final { return this->_last_name_; };
  virtual std::string GetFirstName() final { return this->_first_name_; };
  virtual std::string GetFullName() final { return this->_last_name_ + " " + this->_first_name_; };
  virtual std::string GetBirthDate() final { return this->_birth_date_; };
  virtual int GetAge() final {};
  virtual std::string GetGenderText() final { return this->_gender_ == true ? "Male" : "Female"; };
  virtual std::string GetShiftsType() final { return ""; };
  virtual unsigned short GetSalaryPerHour() final { return->_salary_per_hour_; };

  // Setters

  // Other methods
};

};

#endif // EMPLOYEE_H_INCLUDED

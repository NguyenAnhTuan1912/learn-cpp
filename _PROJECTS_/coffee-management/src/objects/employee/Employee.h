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

namespace CoffeeShop {

class Employee {
private:
  std::string _id_ = Utils::String::GenerateRandom("employee");
  std::string _last_name_;
  std::string _first_name_;
  Datetime _birth_date_;
  bool _gender_;
  ShiftsEnum::Core _shift_type_;
  unsigned short _salary_per_hour_;

public:
  Employee() = default;
  Employee(
    std::string last_name,
    std::string first_name,
    std::string birth_date,
    bool gender,
    ShiftsEnum::Core shift_type,
    unsigned short salary_per_hour
  );

  // Getters
  virtual std::string GetLastName() final { return this->_last_name_; };
  virtual std::string GetFirstName() final { return this->_first_name_; };
  virtual Datetime GetBirthDate() final { return this->_birth_date_; };
  virtual bool void GetGender() final { this->_gender_; };
  virtual ShiftsEnum::Core GetShiftType() final { return this->_shift_type_; };
  virtual unsigned short GetSalaryPerHour() final { return this->_salary_per_hour_; };

  // Setters
  virtual void SetLastName(std::string last_name) final { this->_last_name_ = last_name; };
  virtual void SetFirstName(std::string first_name) final { this->_first_name_ = first_name; };
  virtual void SetBirthDate(std::string birth_date) final { this->_birth_date_ = Datetime(birth_date); };
  virtual void SetGender(bool gender) final { this->_gender_ = gender; };
  virtual void SetShiftType(ShiftsEnum::Core en) final { this->_shift_type_ = en; };
  virtual void SetSalaryPerHour(unsigned short sph) final { this->_salary_per_hour_ = sph; };

  // Other methods
  virtual std::string GetBirthDateStr() final { return this->_birth_date_.GetDateStr(); };
  virtual std::string GetShiftTypeStr() final { return Utils::Enum::GetShiftEnumStr(this->_shift_type_); };
  virtual std::string GetGenderStr() final { return this->_gender_ == true ? "Male" : "Female"; };
  virtual std::string GetFullName() final { return this->_last_name_ + " " + this->_first_name_; };
  virtual int GetAge() final {
    Datetime now;
    double distance = now.Distance(this->_birth_date_);

    // Need to be converted to year
    distance /= (356 * 24 * 60 * 60);

    return distance;
  };
};

};

#endif // EMPLOYEE_H_INCLUDED

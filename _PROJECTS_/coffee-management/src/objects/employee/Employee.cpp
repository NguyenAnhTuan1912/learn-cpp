#include "Employee.h"

namespace CoffeeShop {

Employee::Employee(
  std::string last_name,
  std::string first_name,
  std::string birth_date,
  bool gender,
  ShiftsEnum::Core shift_type,
  unsigned short salary_per_hour
) {
  this->_last_name_ = last_name;
  this->_first_name_ = first_name;
  this->_birth_date_ = Datetime(birth_date);
  this->_gender_ = gender;
  this->_shift_type_ = shift_type;
  this->_salary_per_hour_ = salary_per_hour;
};

// Getters
std::string Employee::GetId() { return this->_id_; };
std::string Employee::GetLastName() { return this->_last_name_; };
std::string Employee::GetFirstName() { return this->_first_name_; };
Datetime* Employee::GetBirthDate() { return &this->_birth_date_; };
bool Employee::GetGender() { return this->_gender_; };
ShiftsEnum::Core Employee::GetShiftType() { return this->_shift_type_; };
unsigned short Employee::GetSalaryPerHour() { return this->_salary_per_hour_; };

// Setters
void Employee::SetLastName(std::string last_name) { this->_last_name_ = last_name; };
void Employee::SetFirstName(std::string first_name) { this->_first_name_ = first_name; };
void Employee::SetBirthDate(std::string birth_date) { this->_birth_date_ = Datetime(birth_date); };
void Employee::SetGender(bool gender) { this->_gender_ = gender; };
void Employee::SetShiftType(ShiftsEnum::Core en) { this->_shift_type_ = en; };
void Employee::SetSalaryPerHour(unsigned short sph) { this->_salary_per_hour_ = sph; };

// Other methods
std::string Employee::GetBirthDateStr() { return this->_birth_date_.GetDateStr(); };

std::string Employee::GetShiftTypeStr() { return Utils::Enum::GetShiftEnumStr(this->_shift_type_); };

std::string Employee::GetGenderStr() { return this->_gender_ == true ? "Male" : "Female"; };

std::string Employee::GetFullName() { return this->_last_name_ + " " + this->_first_name_; };

int Employee::GetAge() {
  Datetime now;
  double distance = now.GetDistance(this->_birth_date_);

  // Need to be converted to year
  distance /= (356 * 24 * 60 * 60);

  return distance;
};

void Employee::Print() {
  std::cout << "Full name: " << this->GetFullName() << ";  ";
  std::cout << "Gender: " << this->GetGenderStr() << ";  ";
  std::cout << "Birthday: " << this->GetBirthDateStr() << ";  ";
  std::cout << "Age: " << this->GetAge() << ";  ";
  std::cout << "Shift: " << this->GetShiftTypeStr() << ";  ";
  std::cout << "Salary/Hour: " << this->_salary_per_hour_ << ";  ";
};

};

#include "Person.h"

using namespace std;

// Định nghĩa hành vi cho default constructor.
Person::Person()
{
  this->name_ = "";
  this->age_ = 0;
}

// Định nghĩa hành vi cho params constructor.
Person::Person(string name, unsigned short age) {
  this->name_ = name;
  this->age_ = age;
}

// Định nghĩa hành vi cho destructor (hiện tại chưa có gì).
Person::~Person()
{
  //dtor
}

/**
 * Dùng hàm này để nhập vào thông tin cho Person.
 * Bao gồm có name và age.
 * @return
 *
 */
void Person::InputInformation() {
  cout << "Input name: ";
  getline(cin, this->name_); cout << endl;

  cout << "Input age: ";
  cin >> this->age_; cout << endl;
}

/**
 * Dùng hàm này để in ra màn hình thông tin giới thiệu của Person.
 * @return
 */
void Person::PrintInformation() {
  cout << "Hello, my name is " << this->name_ << ". I'm " << this->age_ <<"\n";
}

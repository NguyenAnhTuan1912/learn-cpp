/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về polymorphims.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

class Person {
public:
  // Constructor
  Person() = default;
  Person(string f, string l, short a, bool g):
    first_name_{f}, last_name_{l},
    age_{a}, gender_{g} {};

  // Properties
  string first_name_;
  string last_name_;
  short age_;
  bool gender_;

  // Methods
  virtual void Print() = 0;

  // Không cho phép override hàm này.
  virtual string GetFullName() final {
    return last_name_ + " " + first_name_;
  };

  virtual string GetGenderText() final {
    return (gender_ == true) ? "Male" : "Female";
  };
};

class Employee: public Person {
public:
  Employee() = default;
  Employee(
    string f, string l,
    short a, bool g,
    short s, string c,
    float ye
  ): Person(f, l, a, g),
  salary_{s}, company_{c}, years_experience_{ye} {};

  // Properties
  short salary_;
  float years_experience_;
  string company_;

  // Methods
  virtual void StartWork() = 0;
  virtual void EndWork() = 0;

  /*
    Override hàm GetFullName sẽ có lỗi

    Uncomment để thấy lỗi
  */
  // string GetFullName() {};
};

class Developer: public Employee {
public:
  Developer() = default;
  Developer(
    string f, string l,
    short a, bool g,
    short s, string c,
    short ye
  ): Employee(f, l, a, g, s, c, ye) {};

  // Methods
  void Print() {
    cout << "My basic info: \n";
    cout << "===========\n";
    cout
      << "Full name: " << this->GetFullName() << endl
      << "Age: " << this->age_ << endl
      << "Gender: " << this->GetGenderText() << endl;
    cout << endl;
    cout << "My career info: \n";
    cout << "===========\n";
    cout
      << "Job: Developer\n"
      << "Company: " << this->company_ << endl
      << "Years Experience: " << this->years_experience_ << endl;
  };

  void StartWork() {
    cout << "Getting tasks...\n";
    cout << "Coding...\n";
    cout << "Debugging...\n";
  };

  void EndWork() {
    cout << "Adding change to local git...\n";
    cout << "Committing to remote git...\n";
    cout << "End.\n";
  };
};

class Designer: public Employee {
public:
  Designer() = default;
  Designer(
    string f, string l,
    short a, bool g,
    short s, string c,
    float ye
  ): Employee(f, l, a, g, s, c, ye) {};

  // Methods
  void Print() {
    cout << "My basic info: \n";
    cout << "===========\n";
    cout
      << "Full name: " << this->GetFullName() << endl
      << "Age: " << this->age_ << endl
      << "Gender: " << this->GetGenderText() << endl;
    cout << endl;
    cout << "My career info: \n";
    cout << "===========\n";
    cout
      << "Job: Designer\n"
      << "Company: " << this->company_ << endl
      << "Years Experience: " << this->years_experience_ << endl;
  };

  void StartWork() {
    cout << "Getting tasks...\n";
    cout << "Getting references...\n";
    cout << "Drawing...\n";
    cout << "Designing...\n";
  };

  void EndWork() {
    cout << "Giving artwork to leader for reviewing...\n";
    cout << "Saving artwork...\n";
    cout << "End.\n";
  };
};

int main() {
  // Khởi tạo các instance
  Developer dev("Nguyen", "Anh Tuan", 21, true, 1200, "Bosch", 1);
  Designer des("Tran", "Lan Anh", 22, false, 800, "VNG", 1.2);

  // In các thông tin
  cout << "Print information of dev\n";
  dev.Print();
  cout << endl;

  cout << "Print information of des\n";
  des.Print();
  cout << endl;

  cout << "One day working of dev\n";
  dev.StartWork();
  dev.EndWork();
  cout << endl;

  cout << "One day working of des\n";
  des.StartWork();
  des.EndWork();
  cout << endl;

  return 0;
};

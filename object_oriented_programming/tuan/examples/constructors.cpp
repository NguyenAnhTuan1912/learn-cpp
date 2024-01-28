/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về constructor

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
  //
  // Constructors
  //
  // Khởi tạo default constructor
  Person() = default;
  // Person() {}; // Hoặc
  // Person() = delete; // Ngăn compiler tạo một hàm khởi tạo mặc định cho class
  // Khởi tạo initializer list constructor
  Person(string n, short a, bool g, short h, short w)
    : name_(n), age_(a), gender_(g), height_(h), weight_(w)
  {};
  /*
    Lỗi
      Đại loại là lỗi overload của hàm khởi tạo.

    Uncomment để thấy lỗi.
  */
  /*
  Person(string name, short age, bool gender, short height, short weight) {
    this->name_ = name;
    this->age_ = age;
    this->gender_ = gender;
    this->height_ = height;
    this->weight_ = weight;
  };
  */

  // Poperties
  string name_;
  short age_;
  bool gender_;
  short height_;
  short weight_;

  // Method
  void Print() {
    cout
      << "(Name: " << name_ << ","
      << " Age: " << age_ << ","
      << " Gender: " << (gender_ ? "Male" : "Female") << ","
      << " Height: " << height_ << ","
      << " Weight: " << weight_ << ")\n";
  };
};

class Menu {
public:
  Menu(initializer_list<string> food): foods_(food), number_of_foods(food.size()) {};

  void Print() {
    cout << "Nunmber of foods: " << this->number_of_foods << endl;
    cout << "Menu: \n";
    int N = this->foods_.size();
    for(int i = 0; i < N; i++) {
      cout << this->foods_[i] << endl;
    };
  };

private:
  std::vector<string> foods_;
  int number_of_foods;
};

int main() {
  // Khởi tạo các instance của Person
  // Mình có thể gọi được các hàm khởi tạo như sau
  Person p_01;
  Person p_02();
  Person p_03{};
  Person p_04{ "Nguyen Anh Tuan", 21, true, 175, 93 };
  Person p_05("Nguyen Van A", 99, true, 200, 120);
  Person p_06 = Person("Hoang Thi C", 25, false, 171, 50);
  Person p_07 = Person{"Le D", 50, false, 180, 58};

  cout << "Information of p_01\n";
  cout << "Type of p_01: " << typeid(p_01).name() << endl;
  p_01.Print();
  cout << "\n";

  cout << "Information of p_02\n";
  cout << "Type of p_02: " << typeid(p_02).name() << endl;
  /*
    Lỗi
      request for member 'Print' in 'p_02'

    Uncomment để thấy lỗi
  */
  // p_02.Print();
  cout << "\n";

  cout << "Information of p_03\n";
  cout << "Type of p_03: " << typeid(p_03).name() << endl;
  p_03.Print();
  cout << "\n";

  cout << "Information of p_04\n";
  cout << "Type of p_04: " << typeid(p_04).name() << endl;
  p_04.Print();
  cout << "\n";

  cout << "Information of p_05\n";
  cout << "Type of p_05: " << typeid(p_05).name() << endl;
  p_05.Print();
  cout << "\n";

  cout << "Information of p_06\n";
  cout << "Type of p_06: " << typeid(p_06).name() << endl;
  p_06.Print();
  cout << "\n";

  cout << "Information of p_07\n";
  cout << "Type of p_07: " << typeid(p_07).name() << endl;
  p_07.Print();

  cout << "\n";

  cout << "Create instance with initializer list as parameter.\n";
  Menu m{ "Fried Chicken", "Potato", "Soup", "Pho", "Hu tieu" };

  m.Print();

  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ cơ bản về inheritance

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

namespace Example_01 {

// Khai báo và định nghĩa một số lớp Base
class Base {
private:
  int _hidden_value_ = 999;
public:
  string text_ = "This is prop of Base";
};

class Base_02 {
public:
  int number_ = 1000;
};

// Khai báo và định nghĩa các lớp được kế thừa
class Single : private Base {
public:
  string prop_of_single_ = "This is a prop of Single";

  void Print() {
    cout << "Properties of Single instance: \n";
    cout << "text_ (Base): " << this->text_ << endl;
    cout << "prop_of_single_ (owned): " << this->prop_of_single_ << endl;
  };
};

class Multi : public Base, Base_02 {
public:
  string prop_of_multi_ = "This is a prop of Multi";

  void Print() {
    cout << "Properties of Multi instance: \n";
    cout << "text_ (Base): " << this->text_ << endl;
    cout << "number_ (Base_02): " << this->number_ << endl;
    cout << "prop_of_multi_ (owned): " << this->prop_of_multi_ << endl;
  };
};

};

namespace Example_02 {

// Khai báo và định nghĩa một số lớp Base
class Base {
private:
  int _hidden_value_ = 999;
public:
  Base() = default;
  Base(string t): text_(t) {};

  string text_;
};

class Base_02 {
public:
  Base_02() = default;
  Base_02(int n): number_(n) {};

  int number_;
};

// Khai báo và định nghĩa các lớp được kế thừa
class Single : private Base {
public:
  Single() = default;
  // Gọi hàm khởi tạo của lớp kế thừa.
  Single(string t, string pos): Base(t), prop_of_single_(pos) {};

  string prop_of_single_;

  void Print() {
    cout << "Properties of Single instance: \n";
    cout << "text_ (Base): " << this->text_ << endl;
    cout << "prop_of_single_ (owned): " << this->prop_of_single_ << endl;
  };
};

class Multi : public Base, Base_02 {
public:
  Multi() = default;
  Multi(string t, int n, string pom): Base(t), Base_02(n), prop_of_multi_(pom) {};

  string prop_of_multi_ = "This is a prop of Multi";

  void Print() {
    cout << "Properties of Multi instance: \n";
    cout << "text_ (Base): " << this->text_ << endl;
    cout << "number_ (Base_02): " << this->number_ << endl;
    cout << "prop_of_multi_ (owned): " << this->prop_of_multi_ << endl;
  };
};

};

int main() {
  // Khởi tạo các instances từ Single và Multi của namespace Example_01
  Example_01::Single s;
  Example_01::Multi m;

  s.Print();
  cout << endl;
  m.Print();

  cout << endl;

  // Một số lưu ý
  /*
    1. Không thể access vào members của Base từ s trong Main Scope,
    hoặc là từ bất kì scope nào khác ngoài Class kế thừa private Base.
  */
  // s.text_;
  // s._hidden_value_
  /*
    2. Không thể access vào private members của Base.
  */
  // m._hidden_value_;

  // Khởi tạo các instances từ Single và Multi của namespace Example_02
  Example_02::Single s_02("Thuoc tinh text_ duoc ke thua tu Base", "Day la thuoc tinh rieng cua s_02");
  Example_02::Multi m_02("Gia tri cua text_", 15000, "Day la gia tri cua thuoc tinh rieng");

  s_02.Print();
  cout << endl;
  m_02.Print();

  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Function Templates.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

class Base {
public:
  Base() = default;
  Base(int v): value_(v) {};

  int value_;
};

class A: public Base {
public:
  A(int v): Base(v) {};
};
class B: public Base {
public:
  B(int v): Base(v) {};

  // Operator+
  int operator+(const Base& b) {
    return this->value_ + b.value_;
  };
};

/*
  Khai báo thêm một operator+ ở bên ngoài để nhận vào
  tham số const Base&, const Base&
*/
int operator+(const Base& a, const Base& b) {
  return a.value_ + b.value_;
};

namespace Example_01 {

template<typename T>
T GetSum(const T& a, const T& b) {
  return a + b;
};

};

int main() {
  // Khởi tạo các biến, instances
  int i_01 = 12, i_02 = 13;
  float f_01 = 2.34, f_02 = 32.21;
  string str_01 = "Hello, ", str_02 = "World!!!";
  A a_01(23), a_02(50);
  B b_01(100), b_02(900);


  cout << "With scalar type\n";
  cout << "Sum of i_01 and i_02: " << Example_01::GetSum(i_01, i_02) << endl;
  cout << "Sum of f_01 and f_02: " << Example_01::GetSum(f_01, f_02) << endl;
  cout << endl;

  cout << "With non-scalar type\n";
  cout << "Sum of str_01 and str_02: " << Example_01::GetSum(str_01, str_02) << endl;
  cout << endl;

  cout << "With UDT\n";
  cout << "Sum of b_01 and b_02: " << Example_01::GetSum<B>(b_01, b_02).value_ << endl;
  // Note 1 - (liên quan tới Error 3)
  cout << "Sum of a_01 and b_01: " << Example_01::GetSum<Base>(a_01, b_01).value_ << endl;
  // Note 1 - (liên quan tới Error 3)
  cout << "Sum of b_01 and a_02: " << b_01 + a_02 << endl;
  // Note 3 - (liên quan tới Error 2)
  cout << "Sum of a_01 and a_02: " << Example_01::GetSum<Base>(a_01, a_02).value_ << endl;
  cout << endl;

  // Một số trường hợp lỗi
  // Uncomment để thấy lỗi.
  // Error 1
  // cout << "Sum of i_01 and f_02: " << Example_01::GetSum(i_01, f_02) << endl;
  // cout << "Sum of f_01 and str_01: " << Example_01::GetSum(f_01, str_01) << endl;
  // Error 2
  // cout << "Sum of a_01 and a_02: " << Example_01::GetSum(a_01, a_02).value_ << endl;
  // Error 3
  // cout << "Sum of b_01 and a_02: " << Example_01::GetSum<B>(b_01, a_02).value_ << endl;

  return 0;
};

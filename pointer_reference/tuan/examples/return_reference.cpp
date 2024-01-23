/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về return reference.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

struct Point {
  int x_;
  int y_;

  void Print() {
    cout << "(" << this->x_ << ", " << this->y_ << ")" << endl;
  }
};

// Overload của f
void f(const Point& p) {
  cout << "Trong ham f(const Point& a)\n";
};

void f(Point&& p) {
  cout << "Trong ham f(Point&& a)\n";
};

// Các hàm lấy point
Point& GetPointRef(Point &p) {
  // p sẽ dược xem như là lvalue.
  cout << "Trong ham Point& GetPoint(Point &p)\n";
  p.y_ += 1;

  // Gọi hàm f
  f(p);
  return p;
};

Point&& GetPointRvalRef(Point& p) {
  // p sẽ dược xem như là lvalue.
  cout << "Trong ham Point&& GetPoint(Point &p)\n";
  p.x_ += 1;

  // Gọi hàm f
  f(p);
  return move(p);
};

int main() {
  // Tạo point
  cout << "Tao p\n";
  Point p{ 0, 0 };
  cout << "\n";
  cout << "Tao bien moi\n";
  // Biến mới
  Point p_02 = GetPointRef(p);
  cout << "\n";

  cout << "Tao reference cho p\n";
  // Reference của p
  Point& ref_p_01 = GetPointRef(p);
  cout << "\n";

  cout << "Tao rvalue reference cho p\n";
  // Rvalue Reference của p
  Point&& ref_p_02 = GetPointRvalRef(p);
  cout << "\n";
  /*
    Uncomment để thấy lỗi
  */
  // Point& ref_p_03 = GetPointRvalRef(p);

  p_02.x_ = 5;
  ref_p_01.x_ = 10;

  cout << "Change value x_ of p with ref_p_01\n";
  cout << "Value of p: "; p.Print(); cout << endl;
  cout << "\n";

  ref_p_02.x_ = 15;

  f(GetPointRef(p));

  cout << "Value of p: "; p.Print(); cout << endl;

  f(GetPointRvalRef(p));

  cout << "Value of p: "; p.Print(); cout << endl;

  cout << "\n";

  cout << "Addresses\n";
  cout << "Address of p: " << &p << endl;
  cout << "Address of p_02: " << &p_02 << endl;
  cout << "Address of ref_p_01: " << &ref_p_01 << endl;
  cout << "Address of ref_p_02: " << &ref_p_02 << endl;

  cout << "\n";

  // Cả ref_p_01 và ref_p_02 là lvalue.
  f(ref_p_01);
  f(ref_p_02);

  return 0;
};

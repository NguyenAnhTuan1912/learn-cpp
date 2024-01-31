/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Type của template dùng trong:
    - Class member
    - Argument của function

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include<iostream>

using namespace std;

template<typename T>
class Checker {
public:
  T* ptr_value_;

  Checker() {
    cout << "Type of ptr_value_: " << typeid(ptr_value_).name() << endl;
  };
};

template<typename T>
void CheckType(T t) {
  cout << "Type of t: " << typeid(t).name() << endl;
};

int main() {
  // Khai báo một số biến và instances
  int a = 10;
  int& ref_a = a;
  int* ptr_a = &a;
  const char* b = "Nguyen Anh Tuan";
  char* c = "Nguyen Tuan";

  // Check type với CheckType
  // Output: "Type of t: i"
  CheckType(a);
  // Output: "Type of t: i"
  CheckType(ref_a);
  // Output: "Type of t: Pi"
  CheckType(ptr_a);
  // Output: "Type of t: PKc"
  CheckType(b);
  // Output: "Type of t: Pc"
  CheckType(c);

  // Check type với Checker
  // Output: "Type of ptr_value_: Pi" (i -> Pi)
  Checker<int> c_01;
  // Output: "Type of ptr_value_: PPi" (Pi -> PPi)
  Checker<int*> c_02;
  // Output: "Type of ptr_value_: PPKc" (PKc -> PPKc)
  Checker<const char*> c_03;
  // Output: "Type of ptr_value_: PPc" (Pc -> PPc)
  Checker<char*> c_04;
  /*
    Lỗi
      forming pointer to reference type 'int&'
  */
  // Checker<int&> c_05;

  return 0;
};

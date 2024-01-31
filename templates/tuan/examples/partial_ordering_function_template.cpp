/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Abstract Class.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Khai báo toàn cục
int g_a = 999;

namespace Example_01 {

template<typename T>
void Perform(T t) {
  t += 10;
  cout << "General Case\n";
};

template<typename T>
void Perform(T* ptr) {
  // Thay đổi giá trị của ptr
  ptr = &g_a;
  cout << "Specific case: pointer\n";
};

template<typename T>
void Perform(const T* ptr_const) {
  // Thay đổi giá trị của ptr_const
  ptr_const = &g_a;
  // Lỗi
  // *ptr_const = 10;
  cout << "Specific case: pointer of constant\n";
};

// Khi có typename T thì không nên định nghĩa như thế này.
/*
template<typename T>
void Perform(T& t) {
  cout << "Specific case (without T t): Reference\n";
};

template<typename T>
void Perform(T&& t) {
  cout << "Specific case (without T t): Rvalue\n";
};

template<typename T>
void Perform(const T& t) {
  cout << "Specific case (without T t): Constant of Reference\n";
};
*/

};

namespace Example_02 {

template<typename T>
void Perform(T t) {
  cout << "General Case\n";
};

template<typename T>
void Perform(T* ptr) {
  cout << "Specific case: pointer\n";
};

template<typename T>
void Perform(const T* ptr_const) {
  cout << "Specific case: pointer of constant\n";
};

};

namespace Example_03 {

template<typename T>
void Perform(T*& ptr) {
  // Thay đổi giá trị của ptr
  ptr = &g_a;
  cout << "Specific case: reference of pointer\n";
};

template<typename T>
void Perform(const T*& ptr_const) {
  // Thay đổi giá trị của ptr_const
  ptr_const = &g_a;
  cout << "Specific case: reference of pointer of constant\n";
};

};

int GetRvalue() {
  return 40;
};

int main() {
  // Khởi tạo một số biến.
  int a = 10;
  const int const_a = 100;
  int* ptr_a = &a;
  const int* ptr_const_a = &const_a;
  const int* const const_ptr_const_a = &const_a;

  // Gọi hàm Perform
  cout << "Call with Partial Ordering\n";
  Example_01::Perform(a);
  Example_01::Perform(const_a);
  Example_01::Perform(ptr_a);
  Example_01::Perform(ptr_const_a);
  Example_01::Perform(const_ptr_const_a);

  Example_01::Perform(GetRvalue());
  cout << endl;

  cout << "Explicit Instantiation\n";
  // Lỗi
  // Example_01::Perform<const>(a);
  // Example_01::Perform<const>(const_a);
  // Example_01::Perform<int* const>(ptr_a);
  // Example_01::Perform<const int* const>(ptr_const_a);
  // Example_01::Perform<const int* const>(const_ptr_const_a);

  // Hợp lệ
  Example_02::Perform<const>(a);
  Example_02::Perform<const>(const_a);
  Example_02::Perform<int* const>(ptr_a);
  Example_02::Perform<const int* const>(ptr_const_a);
  Example_02::Perform<const int* const>(const_ptr_const_a);
  cout << endl;

  cout << "Change data with explicit instantiation\n";
  cout << "Value of a: " << a << endl;
  cout << "Value of &g_a: " << &g_a << endl;
  cout << "Value of ptr_a: " << ptr_a << endl;
  cout << "Value of ptr_const_a: " << ptr_const_a << endl;
  cout << endl;

  Example_01::Perform<int&>(a);
  Example_03::Perform(ptr_a);
  Example_03::Perform(ptr_const_a);

  cout << endl;
  cout << "Value of a: " << a << endl;
  cout << "Value of ptr_a: " << ptr_a << endl;
  cout << "Value of ptr_const_a: " << ptr_const_a << endl;

  return 0;
};

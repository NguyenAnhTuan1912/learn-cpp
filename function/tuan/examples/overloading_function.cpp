/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Overloading

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

// Khai báo namespace
namespace OverloadingFunctionExamples {

// Add Overload
int Add(int a, int b) {
  return a + b;
};

float Add(float a, float b) {
  return a + b;
};

// Max04 Overload
int Max04(int &a, int &b) {
  return a > b ? a : b;
};

int Max04(const int &a, const int &b) {
  return a > b ? a : b;
};

int Max04(volatile int &a, volatile int &b) {
  return a > b ? a : b;
};

/*
  Các hàm dưới đây khi gọi sẽ gây ra lỗi.
  Một số hàm sẽ gây ra lỗi khi:
  - Được gọi.
  - Khai báo (uncomment để thấy lỗi).
*/

// Lỗi Ambiguous
int Max01(int a, int b) {
  return a > b ? a : b;
};

int Max01(int &a, int &b) {
  return a > b ? a : b;
};

// Lỗi Redefinition
/*
int Max02(int a, int b) {
  return a > b ? a : b;
};

int Max02(const int a, const int b) {
  return a > b ? a : b;
};

int Max03(int a, int b) {
  return a > b ? a : b;
};

int Max03(volatile int a, volatile int b) {
  return a > b ? a : b;
};
*/

};

using namespace std;
using namespace OverloadingFunctionExamples;

int main() {
  int a = 10, b = 15;
  float c = 20.245, d = 2.121;

  cout << "Tong cua a va b: " << Add(a, b) << endl;
  cout << "Tong cua c va d: " << Add(c, d) << endl;
  // Output: "So lon nhat trong giua a va b: 15"
  cout << "So lon nhat trong giua a va b: " << Max04(a, b) << endl;
  /*
    Các hàm dưới đây khi được gọi thì nó sẽ gây ra lỗi.
  */
  // Lỗi Ambiguous
  // cout << "So lon nhat trong giua a va b: " << Max01(a, b) << endl;

  return 0;
};

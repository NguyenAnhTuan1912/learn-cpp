/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử gán.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  float
    s_num_01 = 21,
    s_num_02 = 15,
    s_num_03 = -32,
    s_num_04 = 9,
    result_01 = 2,
    result_02 = 3,
    result_03 = 13,
    result_04 = 4;

  // Bắt đầu tính toán.
  // Tương đương: result_01 = result_01 + s_num_01;
  result_01 += s_num_01;
  // Tương đương: result_02 = result_02 - s_num_01;
  result_02 -= s_num_02;
  // Tương đương: result_03 = result_03 * s_num_01;
  result_03 *= s_num_03;
  // Tương đương: result_04 = result_04 / s_num_01;
  result_04 /= s_num_04;

  // Value: "Value of result_01: 23"
  cout << "Value of result_01: " << result_01 << endl;
  // Value: "Value of result_02: -12"
  cout << "Value of result_02: " << result_02 << endl;
  // Value: "Value of result_03: -416"
  cout << "Value of result_03: " << result_03 << endl;
  // Value: "Value of result_04: 0.444444"
  cout << "Value of result_04: " << result_04 << endl;

  return 0;
};

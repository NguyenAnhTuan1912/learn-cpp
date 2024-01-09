/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử số học kiểu binary.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  // Phép cộng
  short short_num_01 = 12;
  short short_num_02 = 23;

  // Output: 12 + 23 = 35
  cout << "short_num_01 + short_num_02 = " << (short_num_01 + short_num_02) << endl;

  // Phép trừ
  short short_num_03 = -99;
  short short_num_04 = 12;

  // Output: -99 - 12 = -111
  cout << "short_num_03 - short_num_04 = " << (short_num_03 - short_num_04) << endl;

  // Phép nhân
  short short_num_05 = -100;
  short short_num_06 = 45;

  // Output: -100 * 45 = -4500
  cout << "short_num_05 * short_num_06 = " << (short_num_05 * short_num_06) << endl;

  // Phép chia
  short short_num_07 = 98;
  short short_num_08 = 14;

  // Output: 98 / 14 = 7
  cout << "short_num_07 / short_num_08 = " << (short_num_07 / short_num_08) << endl;

  // Phép tính căng hơn.
  short short_num_09 = 21;
  short short_num_10 = 12;
  float result_01 = (float)((short_num_09 + short_num_10) * (short_num_05 / short_num_06) + (short_num_03 - short_num_01));
  float result_02 = (float)((short_num_06 - short_num_03) / (short_num_03 * short_num_04) - short_num_02);

  // Output: "Value of result_01: -177"
  cout << "Value of result_01: " << result_01 << endl;
  // Output: "Value of result_02: -23"
  cout << "Value of result_02: " << result_02 << endl;

  // Convert type với phép * với 1.0
  short short_num_11 = 10;
  short short_num_12 = 3;
  float result_03 = short_num_11 / short_num_12;
  float result_04 = 1.0 * short_num_11 / short_num_12;

  // Output: "Value of result_03: 3"
  cout << "Value of result_03: " << result_03 << endl;
  // Output: "Value of result_04: 3.33333"
  cout << "Value of result_04: " << result_04 << endl;

  return 0;
};

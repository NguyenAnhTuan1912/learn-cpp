
/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử số học kiểu unary.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  // Khai báo hai biến và sử dụng unary
  short s_num_01 = 1;
  short s_num_02 = 10;

  // Output: "Value of s_num_01++: 1"
  cout << "Value of s_num_01++: " << s_num_01++ << endl;
  // Output: "Value of s_num_01++: 10"
  cout << "Value of s_num_02--: " << s_num_02-- << endl;

  // Giờ thì đặt thử lần lượt 2 toàn từ này ở vị trí trước toán hạng
  // Output: "Value of s_num_01++: 3"
  cout << "Value of ++s_num_01: " << ++s_num_01 << endl;
  // Output: "Value of s_num_01++: 8"
  cout << "Value of --s_num_02: " << --s_num_02 << endl;

  // Thử các phép tính phức tạp hơn.
  short n = 2, m = 4;
  short result_01 = (++n - 1) + ((--m + n++) + 2 * n++);
  short result_02 = (5 * n - 2 * m) + (--m + ++n + m-- * 2);

  // Output: "Value of result_01: 16"
  cout << "Value of result_01: " << result_01 << endl;
  // Output: "Value of result_02: 31"
  cout << "Value of result_02: " << result_02 << endl;

  // Output: "n and m: 6, 1"
  cout << "n and m: " << n << ", " << m << endl;

  return 0;
};

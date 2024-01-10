/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về nạp chồng toán cục 2 toán tử + và -.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Định nghĩa một class đơn giản.
class Custom {
public:
  Custom(short v) {
    this->value_ = v;
  };
  short value_;
};

// Định nghĩa hàm toán tử (Global).
// Custom sẽ + với Custom
short operator+(Custom x, Custom y) {
  return x.value_ + y.value_;
};

// Nạp chồng thêm một hàm nữa.
// Custom sẽ + với một scalar
short operator+(Custom x, short y) {
  return x.value_ + y;
};

// Nạp chống thêm các hàm -
short operator-(Custom x, Custom y) {
  return x.value_ - y.value_;
};

// Nạp chồng thêm một hàm nữa.
// Custom sẽ + với một scalar
short operator-(Custom x, short y) {
  cout << "When perform operator- with x and short y\n";
  cout << "Value of x.value_: " << x.value_ << endl;
  cout << "Value of y: " << y << endl;
  return x.value_ - y;
};

/*
  Khi định nghĩa operator- ở trên, thì thằng này sẽ không có.
  Nhưng khi phép tính short y - Custom x xuất hiện thì buộc C++
  phải tạo ra hàm này để tình toán.

  Nhờ vào việc có thể in trong thân hàm toán tử, mình có thể chứng minh được.
  (Xem thêm trong tài liệu).

  Mở và đóng comment hàm này sẽ hiểu thêm.
*/
short operator-(short y, Custom x) {
  cout << "When perform operator- short y and with x\n";
  cout << "Value of x.value_: " << x.value_ << endl;
  cout << "Value of y: " << y << endl;
  return y - x.value_ - 10;
};

int main() {
  Custom
    cus_01(5),
    cus_02(10);

  short y = 100;

  short
    // Tính tổng cus_01 + cus_02
    result_01 = cus_01 + cus_02,
    // Tính tổng của cus_01 + y
    result_02 = cus_01 + y,
    // Tính tổng của cus_02 + y
    result_03 = cus_02 + y,
    // Tính tổng cus_01 - cus_02
    result_04 = cus_01 - cus_02,
    // Tính tổng của cus_01 - y
    result_05 = cus_01 - y,
    // Tính tổng của y - cus_02
    result_06 = y - cus_02;

  // Output: "Value of result_01: 15"
  cout << "Value of result_01: " << result_01 << endl;
  // Output: "Value of result_02: 105"
  cout << "Value of result_02: " << result_02 << endl;
  // Output: "Value of result_03: 110"
  cout << "Value of result_03: " << result_03 << endl;
  // Output: "Value of result_04: -5"
  cout << "Value of result_04: " << result_04 << endl;
  // Output: "Value of result_05: -95"
  cout << "Value of result_05: " << result_05 << endl;
  // Output: "Value of result_06: 90"
  cout << "Value of result_06: " << result_06 << endl;

  return 0;
};

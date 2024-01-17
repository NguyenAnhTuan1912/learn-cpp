/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Overloading Operator

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Khai báo một lớp đối tượng.
class N {

public:
  N(float value) {
    _value_ = value;
  }

  float GetValue() {
    return _value_;
  }

  void SetValue(float value) {
    _value_ = value;
  }

  // Nạp chồng toán tử
  // Ở đây mình sẽ nạp chồng +, -, *, /
  // Quy tắc 5
  float operator+(float n) {
    return _value_ + n;
  }

  float operator-(float n) {
    return _value_ - n;
  }
  /*
    Lỗi quy tắc 5

    Hàm toán tử đôi có hai tham số khi nó được khai báo toàn cục.
    Uncomment để thấy lỗi.
  */
  /*
  float operator-(float n, N a) {
    return a.GetValue() - n;
  }
  */

  float operator*(float n) {
    return _value_ * n;
  }

  float operator/(float n) {
    return _value_ / n;
  }

  /*
    Lỗi quy tắc 2

    Uncomment để thấy lỗi.
  */
  /*
  static float operator++() {
    float temp = _value_;
    _value_ += 2;
    return temp;
  }
  */

private:
  float _value_;

};

/*
  Lỗi quy tắc 1 & 9

  - Vì không thể áp dụng các toán tử lên các kiểu dữ liệu mặc định.
  - Phải có đối số là UDT.

  Uncomment để thấy lỗi.
*/
/*
int operator+(int a, int b) {
  return a + a;
}
*/

// (1) Khai báo thêm hàm toán tử cho phép + của N.
float operator+(float n, N a) {
  return a.GetValue() + n;
};
/*
  Lỗi quy tắc 7

  n được gán với giá trị mặc định là 45.
  Uncomment để thấy lỗi.
*/
/*
float operator-(N a, float n = 45) {
  return a.GetValue() - n;
};
*/

int main() {
  // Khai báo một đối tượng N và một biến
  N a(45);
  float b = 5;

  // Cùng chiều
  cout << a.GetValue() << " + " << b << " = " << a + b << endl;
  cout << a.GetValue() << " - " << b << " = " << a - b << endl;
  cout << a.GetValue() << " * " << b << " = " << a * b << endl;
  cout << a.GetValue() << " / " << b << " = " << a / b << endl;
  cout << "\n";

  // Ngược chiều
  // (1) Hàm toán tử này đã được khai báo ở trên
  cout << b << " + " << a.GetValue() << " = " << b + a << endl;
  /*
    Lỗi quy tắc 9

    - Đối số đầu tiênn không phải là UDT.

    Chỉ có operator + là không có lỗi bởi vì nó có thêm một hàm ở bên ngoài nữa
    để có thể tính ngược chiều. Các toán tử còn lại vì không có nên sẽ lỗi.
    Uncomment để thấy lỗi.
  */
  /*
  cout << b << " - " << a.GetValue() << " = " << b - a << endl;
  cout << b << " * " << a.GetValue() << " = " << b * a << endl;
  cout << b << " / " << a.GetValue() << " = " << b / a << endl;
  */

  return 0;
};

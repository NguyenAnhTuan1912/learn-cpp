/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về tạo một template.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Thay vì mình viết các overload như này
// WOT = WithoutTemplate
namespace WOT {

int GetSum(const int& a, const int& b) {
  return a + b;
};

float GetSum(const float& a, const float& b) {
  return a + b;
};

double GetSum(const double& a, const double& b) {
  return a + b;
};

};
// Thì giờ mình viết như thế này
// WT = WithTemplate
namespace WT {

template<typename T>
T GetSum(const T& a, const T& b) {
  return a + b;
};

};

int main() {
  // Khai báo các biến
  int i_01 = 20, i_02 = 3;
  float f_01 = 12.4, f_02 = -3.34;
  double d_01 = 23.4125, d_02 = 32.47827;

  cout << "Compare result\n";
  cout << "Without Template (Use overload)\n";
  cout << "Result (int): " << WOT::GetSum(i_01, i_02) << endl;
  cout << "Result (float): " << WOT::GetSum(f_01, f_02) << endl;
  cout << "Result (double): " << WOT::GetSum(d_01, d_02) << endl;
  cout << endl;

  cout << "With Template\n";
  /*
    1. Có thể không truyền kiểu dữ liệu vào Type Parameter như này,
    để cho trình biên dịch tự đoán.
  */
  cout << "Result (int): " << WT::GetSum(i_01, i_02) << endl;
  cout << "Result (float): " << WT::GetSum<float>(f_01, f_02) << endl;
  cout << "Result (double): " << WT::GetSum(d_01, d_02) << endl;
  /*
    2. Có thể truyền vào kiểu dữ liệu khác cho type parameters mà không
    cần phải trùng type với function parameter. Khi này thì kiểu dữ liệu
    sẽ được chuyển đối (type casting).

    Nêu nếu như type của function params mà là non-scalar, nhưng type của
    template params lại là scalar thì sẽ gây lỗi.
  */
  cout << "Result (int) from (double, double): " << WT::GetSum<int>(d_01, d_02) << endl;
  cout << endl;

  // Ngoài ra templat còn hỗ trợ một số kiểu dữ liệu khác
  // mà không cần phải khai báo thêm như overload.
  cout << "Using template can operate in other types\n";
  char c_01 = 'a', c_02 = 'b';
  string s_01 = "Hello, ", s_02 = "World!!!";

  cout << "Result (char): " << WT::GetSum(c_01, c_02) << endl;
  cout << "Result (std::string): " << WT::GetSum(s_01, s_02) << endl;

  return 0;
};

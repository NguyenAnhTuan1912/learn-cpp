/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử so sánh.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  // In ra màn hình số lớn hơn.
  // Thay đổi giá trị của hai kết quả này để thấy các kết quả khác nhau.
  short s_num_01 = 12;
  short s_num_02 = 24;

  if(s_num_01 > s_num_02) {
    cout
      << "s_num_01 larger than s_num_02 ("
      << s_num_01 << " > " << s_num_02 << ")." << endl;
  } else if(s_num_01 == s_num_02) {
    cout
      << "s_num_01 equal to s_num_02 ("
      << s_num_01 << " = " << s_num_02 << ")."  << endl;
  } else {
    cout
      << "s_num_01 smaller than s_num_02 ("
      << s_num_01 << " < " << s_num_02 << ")."  << endl;
  };

  // Output: "Value of s_num_01 > s_num_02: "
  cout << "Value of s_num_01 > s_num_02: " << (s_num_01 > s_num_02) << endl;
  // Output: "Value of s_num_01 = s_num_02: "
  cout << "Value of s_num_01 = s_num_02: " << (s_num_01 == s_num_02) << endl;
  // Output: "Value of s_num_01 < s_num_02: "
  cout << "Value of s_num_01 < s_num_02: " << (s_num_01 < s_num_02) << endl;

  // Output: "Type of s_num_01 > s_num_02: b"
  cout << "Type of s_num_01 > s_num_02: " << typeid(s_num_01 > s_num_02).name() << endl;
  
  return 0;
};

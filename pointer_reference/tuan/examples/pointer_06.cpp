/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về pointer và function.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Hàm này dùng để nối chuỗi dựa theo
// string (*_c)(string str_1, string str_2)
string combine(string (*_c)(string str_1, string str_2), string str_1, string str_2) {
  return (*_c)(str_1, str_2);
};

// Các hàm nối chuỗi.
string leftToRight(string str_1, string str_2) {
  return str_1.append(" ").append(str_2);
};

string rightToLeft(string str_1, string str_2) {
  return str_2.append(" ").append(str_1);
};

int main() {
  // Khai báo các biến
  string
    str_1 = "Xin chao, ",
    str_2 = "Toi ten la Tuan.";

  cout << combine(leftToRight, str_1, str_2) << endl;
  cout << combine(rightToLeft, str_1, str_2) << endl;

  return 0;
};

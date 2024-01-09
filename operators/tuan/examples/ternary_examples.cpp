/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử 3 ngôi.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  short
    s_num_01 = 10,
    s_num_02 = 12;

  /*
    Thay vì mình dùng if...else như này

    if(s_num_01 > s_num_02) {
      result_01 = "s_num_01 larger than s_num_02";
    };

    if(s_num_01 < s_num_02) {
      result_01 = "s_num_01 smaller than s_num_02";
    };
  */
  string result_01 =
    s_num_01 > s_num_02
    ? "s_num_01 larger than s_num_02"
    : "s_num_01 smaller than s_num_02";

  // s_num_01 smaller than s_num_02
  cout << result_01 << endl;

  /*
    Thay vì mình dùng if...else như này

    if(s_num_01 > s_num_02) {
      result_01 = "s_num_01 larger than s_num_02";
    } else if(s_num_01 == s_num_02) {
      result_01 = "s_num_01 equal to s_num_02";
    } else {
      result_01 = "s_num_01 smaller than s_num_02";
    };
  */
  string result_02 =
    s_num_01 > s_num_02
    ? "s_num_01 larger than s_num_02"
    : s_num_01 == s_num_02
      ? "s_num_01 equal to s_num_02"
      : "s_num_01 smaller than s_num_02";

  // s_num_01 smaller than s_num_02
  cout << result_02 << endl;

  return 0;
};

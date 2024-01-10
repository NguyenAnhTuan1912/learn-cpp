/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các falsy value.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

struct Test {
  short x_;
  short y_;
};

int main() {
  short falsy_value_01 = 0;
  short falsy_value_02[1];
  char c_01 = '0';
  string s_01 = "";
  Test falsy_value_03;
  short falsy_value_04 = NULL;

  // Output: "falsy_value_01 = 0 la falsy value."
  if(falsy_value_01) {
    cout << "falsy_value_01 = " << falsy_value_01 << " la truthy value.\n";
  } else {
    cout << "falsy_value_01 = " << falsy_value_01 << " la falsy value.\n";
  };

  // Output: "falsy_value_02 = 0 la falsy value."
  if(falsy_value_02) {
    cout << "falsy_value_02 = " << falsy_value_02 << " la truthy value.\n";
  } else {
    cout << "falsy_value_02 = " << falsy_value_02 << " la falsy value.\n";
  };

  // Output: "c_01 = 0 la falsy value."
  if(c_01) {
    cout << "c_01 = " << c_01 << " la truthy value.\n";
  } else {
    cout << "c_01 = " << c_01 << " la falsy value.\n";
  };

  // Chỗ này sẽ lỗi, vì string (non-scalar) không thể convert sang bool (scalar).
  /*
  if(s_01) {
    cout << "s_01 = " << s_01 << " la truthy value.\n";
  } else {
    cout << "s_01 = " << s_01 << " la falsy value.\n";
  };
  */

  // Chỗ này sẽ lỗi, vì struct (non-scalar) không thể convert sang bool (scalar).
  /*
  if(falsy_value_03) {
    cout << "falsy_value_03 = " << falsy_value_03 << " la truthy value.\n";
  } else {
    cout << "falsy_value_03 = " << falsy_value_03 << " la falsy value.\n";
  };
  */

  // Output: "falsy_value_04 = 0 la falsy value."
  // NULL sẽ được convert về short int và có giá trị là 0.
  if(falsy_value_04) {
    cout << "falsy_value_04 = " << falsy_value_04 << " la truthy value.\n";
  } else {
    cout << "falsy_value_04 = " << falsy_value_04 << " la falsy value.\n";
  };

  // Nếu như 0 là falsy thì đảo lại có thành truthy hay không?
  // Output: "~falsy_value_01 = -1 la truthy value."
  // Vậy là có.
  if(~falsy_value_01) {
    cout << "~falsy_value_01 = " << ~falsy_value_01 << " la truthy value.\n";
  } else {
    cout << "~falsy_value_01 = " << ~falsy_value_01 << " la falsy value.\n";
  };

  // Output: "~false = -1 la truthy value."
  if(~false) {
    cout << "~false = " << ~false << " la truthy value.\n";
  } else {
    cout << "~false = " << ~false << " la falsy value.\n";
  };

  // Vậy nếu như đảo lại bits của một truthy value thì có thành falsy value không?
  // Output: "~c_01 = -49 la truthy value."
  // Câu trả lời là không.
  if(~c_01) {
    cout << "~c_01 = " << ~c_01 << " la truthy value.\n";
  } else {
    cout << "~c_01 = " << ~c_01 << " la falsy value.\n";
  };

  // Dùng toàn tử phủ định.
  // Output: "!c_01 = 0 la falsy value."
  if(!c_01) {
    cout << "!c_01 = " << !c_01 << " la truthy value.\n";
  } else {
    cout << "!c_01 = " << !c_01 << " la falsy value.\n";
  };

  return 0;
};

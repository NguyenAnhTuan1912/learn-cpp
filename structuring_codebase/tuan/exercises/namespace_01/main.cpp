/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ có một bài tập về namespace.
  Đồng thời cũng chuẩn bị cho phần sau.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

// Include config và string_utils
#include "configs.cpp"
#include "utils/string_utils/main.cpp"

// Định nghĩa một unnamed/anonymous namespace
namespace {

short a = 10000;
/*
  (1)
  Nếu mình khai báo như này thì sẽ bị lỗi tái định nghĩa (Redefinotion).
  Và trong configs cũng có hàm GetVéion, nếu mình định nghĩa hàm này ở đây,
  thì cũng sẽ báo lỗi.

  Gỡ comment ra để tháy lỗi.
*/
// std::string app_version = "1.2.0";
// std::string GetVersion() { return app_version; };

};

using namespace std;

int main() {
  // Output: "Value of ::app_version (in configs.cpp): 1.2.0"
  cout << "Value of ::app_version (in configs.cpp): " << ::app_version << endl;
  // Output: "Value of ::a: 10000"
  cout << "Value of ::a: " << ::a << endl;

  cout << "\n";

  cout << "Concatenate string\n";
  // Khai báo 2 chuỗi.
  string
    str_01 = " Hello",
    str_02 = "World!!!   ",
    concate_result_01 = StringUtils::v1::Concate(str_01, str_02),
    concate_result_02 = StringUtils::Concate(str_01, str_02);

  // Dùng v1
  // Output: "Value of concate_result_01:  HelloWorld!!!   "
  cout << "Value of concate_result_01: " << concate_result_01 << endl;

  // Dùng v2
  // Output: "Value of concate_result_02: Hello World!!!"
  cout << "Value of concate_result_02: " << concate_result_02 << endl;

  // (2)
  // Và có thể sử dụng ::Trim trong string_utils/main.cpp
  // Output: "Value of ::Trim(str_02): World!!!"
  cout << "Value of ::Trim(str_02): " << ::Trim(str_02) << endl;

  cout << "\n";

  return 0;
};

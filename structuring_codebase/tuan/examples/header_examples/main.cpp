/*
  @author Nguyen Anh Tuan
  Trong này mình dùng để implement các headers file.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
// File header tự tạo phải được định nghĩa như thế này.
// Include example_01.h
/*
  Nếu như không link example_01.cpp trong quá trình compile
  thì comment dòng include này lại
*/
#include "headers/example_01/example_01.h"
// Include example_02.h
/*
  Nếu như không link example_02.cpp trong quá trình compile
  thì comment dòng include này lại
*/
#include "headers/example_02/example_02.h"

// Tạo một unnamed namespace
namespace {

short a = 1200;

};

using namespace std;

int main() {
  cout << "Example 01\n";
  /*
    Khi import example_01.h vào trong thì mình có thể
    thấy được name của namespace Example01
  */
  /*
    Nếu như không link example_01.cpp trong quá trình compile
    thì comment mấy dòng này lại
  */
  /*
  // Output: "Value of Example01::name: "
  cout << "Value of Example01::name: " << Example01::name << endl;
  // Output: "Value of Example01::topic: "
  cout << "Value of Example01::topic: " << Example01::topic << endl;
  // Output: "Value of Example01::Greet(): "
  cout << "Value of Example01::Greet(): " << Example01::Greet() << endl;

  cout << "\n";
  */

  cout << "Example 02\n";

  /*
    Nếu như không link example_02.cpp trong quá trình compile
    thì comment mấy dòng này lại
  */
  // Output: "Value of Example02::g_name: "
  cout << "Value of Example01::g_name: " << Example02::g_name << endl;
  // Output: "Value of Example02::s_num_01: "
  cout << "Value of Example01::s_num_01: " << Example02::s_num_01 << endl;
  // Output: "Value of Example02::GetHiddenMessage(): "
  cout << "Value of Example01::GetHiddenMessage(): " << Example02::GetHiddenMessage() << endl;

  cout << "\n";

  // Output: "Value of ::a: "
  cout << "Value of ::a: " << ::a << endl;
  // Output: "Value of ::ProveThatUnnamedNamespaceIsHiddenWithAnotherTU(): "
  // Uncomment dòng này để thấy lỗi
  // cout << "Value of ::ProveThatUnnamedNamespaceIsHiddenWithAnotherTU(): " << ::ProveThatUnnamedNamespaceIsHiddenWithAnotherTU() << endl;

  cout << "\n";

  return 0;
};

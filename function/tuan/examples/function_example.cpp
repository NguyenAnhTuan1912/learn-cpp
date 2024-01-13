/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về khai báo và định nghĩa function.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

// Khai báo và định nghĩa function trong namespace
namespace {

void SayHello() {
  std::cout << "Hello, World!!! Function Examples\n";
};

};

using namespace std;

// Khai báo function trong Global Scope
// Bad name
string Greet() {
  return "Ham nay duoc khai bao o Global Scope!";
};

// Good name
string GetGreetingText() {
  return "Ham nay duoc khai bao o Global Scope!";
}

int main () {
  // Khai báo function trong Local Scope (Main Scope)
  // Không thể
  /*
  string GreetInMain() {
    return "Ham nay duoc khai bao o Main Scope!";
  };
  */

  // Output: "Value of Greet(): Ham nay duoc khai bao o Global Scope!"
  cout << "Value of Greet(): " << Greet() << endl;
  // Output: "Value of GetGreetingText(): Ham nay duoc khai bao o Global Scope!"
  cout << "Value of GetGreetingText(): " << GetGreetingText() << endl;
  // Output: "Hello, World!!! Function Examples"
  ::SayHello();
  // Vì không có phần khai báo nên cái này lỗi.
  // cout << "Value of GreetInMain(): " << GreetInMain() << endl;

  cout << "\n";

  return 0;
};

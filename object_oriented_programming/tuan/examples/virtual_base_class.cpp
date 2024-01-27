/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ cơ bản về từ khóa virtual
  trong phần kế thừa.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

class A {
public:
  void Print() {
    cout << "Say hello from instance of A";
  };
};

namespace Example_01 {

class B: public A {};
class C: public A {};
class D: public B, C {};

};

namespace Example_02 {

class B: virtual public A {};
class C: virtual public A {};
class D: public B, C {};

};

int main() {
  // Khởi tạo các instances
  Example_01::D d_01;
  Example_02::D d_02;

  cout << "Call Print\n";
  /*
    Lỗi
      request for member 'Print' is ambiguous

    Uncomment để thấy lỗi
  */
  // d_01.Print();
  d_02.Print();
  cout << endl;

  return 0;
};

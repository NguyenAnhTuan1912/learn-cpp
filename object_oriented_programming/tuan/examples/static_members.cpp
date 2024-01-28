/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Static Member.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

class A {
public:
  A() {
    cout << "Khoi tao instance cua A\n";
  };

  void Print() { cout << "Hello, I'm a instance of A.\n"; };
};

/*
  Tạo một lớp B có một static member là một
  instance của A
*/
class B {
public:
  B() {
    cout << "Khoi tao instance cua B\n";
  };

  // Khai báo, định nghĩa ở ngoài Class Scope.
  static A a;
};

// Khởi tạo instance của A
A B::a;

/*
  Tạo một lớp C có một member là instance của A
*/
class C {
public:
  C() {
    cout << "Khoi tao instance cua C\n";
  };

  // Khác với B, thì a ở đây là member của instance
  A a;
};

int main() {
  // Khởi tạo instance B
  cout << "Initialize instances of B\n";
  B b_01, b_02, b_03;

  cout << "\n";

  // Truy cập vào a để gọi Print
  cout << "Call Print from B: "; B::a.Print();
  cout << "Call Print from b_01: "; b_01.a.Print();
  cout << "Call Print from b_02: "; b_02.a.Print();
  cout << "Call Print from b_03: "; b_03.a.Print();

  cout << "\n";

  cout << "Address of a in B\n";
  cout << "Check with B: " << &(B::a) << endl;
  cout << "Check with b_01: " << &(b_01.a) << endl;
  cout << "Check with b_02: " << &(b_02.a) << endl;
  cout << "Check with b_03: " << &(b_03.a) << endl;

  cout << "\n";

  cout << "Initialize instances of C\n";
  C c_01, c_02, c_03;

  cout << "\n";

  cout << "Address of a in C\n";
  cout << "Check with c_01: " << &(c_01.a) << endl;
  cout << "Check with c_02: " << &(c_02.a) << endl;
  cout << "Check with c_03: " << &(c_03.a) << endl;

  cout << "\n";

  return 0;
};

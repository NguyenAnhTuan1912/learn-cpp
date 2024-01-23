/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về const T&& và T&&.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Hai hàm Hello1 và Hello2
void Hello1(int&& a) {
    cout << "Receive only rvalue reference\n";
    cout << a << endl;
};

void Hello2(const int& a) {
    cout << "Receive lvalue and rvalue reference (lvalue is default)\n";
    cout << a << endl;
};

// Overloads có rvalue referrence argument và mọt overload có lvalue reference argument.
void Hello(const int& a) {
  cout << "Trong ham Hello(const int& a)\n";
};

void Hello(int&& a) {
  cout << "Trong ham Hello(int&& a)\n";
};

int&& AddMore10(int&& a) {
  a += 10;
  // a được xem như là lvalue
  Hello(a);
  /*
    Nên có hàm move ở đây, vì a được xem như là lvalue
    trong thân của AddMore10, nhưng return type phải là
    rvalue reference.

    Nếu return a thì sẽ gây lỗi.
  */
  return move(a);
};

int GetNumber() {
    return 21;
};

int main() {
  int a = 999;

  cout << "Lvalue and Rvalue arugments\n";
  // Pass lvalue
  /*
    Lỗi
      cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'

    Uncomment để xem lỗi.
  */
  // Hello1(a);
  Hello2(a);

  // Pass rvalue
  Hello1(GetNumber());
  Hello2(GetNumber());

  cout << "\n";

  cout << "Treat named rvalue reference as lvalue inside a function\n";

  /*
    Truyền một rvalue vào cho AddMore10 qua GetNumber, khi đó
    AddMore10 nhận một rvalue reference.
    Tiếp theo, AddMore10 sẽ trả về một rvalue reference cho Hello,
    và Hello sẽ gọi overload nào?
  */
  Hello(AddMore10(GetNumber()));

  cout << "\n";

  return 0;
};

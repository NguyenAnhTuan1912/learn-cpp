/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về cách pointer được sử dụng trong hàm

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int Sum(int a, int b) {
  return a + b;
};

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
};

void PrintValAddress(int a) {
  cout<< "Val's address: " << &a << endl;
};

void PrintRefAddress(int &a) {
  cout<< "Ref's address: " << &a << endl;
};

/*
  Khi biên dịch thì sẽ hiện ra một message là:
  "warning: address of local variable 'a' returned"
  Nghĩa ra khi đó đã trả về một biến khác chứ không còn
  là biến đã truyền vào.
*/
int* GetPointerWithVal(int a) {
  return &a;
};

int* GetPointerWithRef(int &a) {
  return &a;
};

int main() {
  // Khai báo các biến
  int
    a = 10,
    b = 25;

  // Khai báo các con trỏ
  int
    *ptr_a = &a,
    *ptr_b = &b;

  cout << "Sum of a & b (*ptr_a & *ptr_b): " << Sum(*ptr_a, *ptr_b) << endl;

  Swap(*ptr_a, *ptr_b);

  cout << "Value of a: " << a << endl;
  cout << "Value of b: " << b << endl;

  cout << "\n";

  cout << "Address of Value and Reference in function\n";

  int m = 10;

  cout << "Address of m: " << &m << endl;
  PrintValAddress(m); // != &m
  PrintRefAddress(m); // == &m

  // Kiểm tra với lambda
  [&](int a) {
    cout << "Is 'a' a copy? " << ((&a == &m) ? "no" : "yes") << endl;
  }(m);

  [&](int &a) {
    cout << "Is 'a' a copy? " << ((&a == &m) ? "no" : "yes") << endl;
  }(m);

  cout << "\n";

  cout << "Get poitner from function\n";

  int q = 100;

  int
    *ptr_q_01 = GetPointerWithVal(q),
    *ptr_q_02 = GetPointerWithRef(q);

  cout << "Value of &q: " << &q << endl;
  cout << "Value of ptr_q_01: " << ptr_q_01 << endl; // != &q
  cout << "Value of ptr_q_02: " << ptr_q_02 << endl; // == &q

  // Sửa đối dữ liệu của q với 2 pointers này.
  /*
    Lỗi, bởi vì ptr_q_01 đang trỏ vào trong một vùng nhớ
    mà nó outside với chương trình.

    Uncomment để thấy lỗi.
  */
  // *ptr_q_01 += 50;
  *ptr_q_02 /= 10;

  cout << "Value of q: " << q << endl;

  cout << "\n";

  return 0;
};

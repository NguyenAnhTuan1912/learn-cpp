/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về constant pointer.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  // Khai báo các biến
  int a = 10;
  int alternate = 9999;
  const int k_b = 99;
  /*
    Nên đặt dấu * ở sau kiểu dữ liệu cho chắc ăn, kể cả &
  */
  // Khai báo các con trỏ
  // Con trỏ trỏ về biến int
  int* ptr_a = &a;
  // Con trỏ trỏ về hằng int
  const int* ptr_k_B = &k_b;
  // Con trỏ hằng trỏ về biến int
  int* const k_ptr_a = &a;
  // Con trỏ hằng trỏ về hằng int
  const int* const k_ptr_k_b = &k_b;

  cout << "Value of &a: " << &a << endl;
  cout << "Value of &k_b: " << &k_b << endl;

  cout << "\n";

  cout << "Value of ptr_a: " << ptr_a << endl;
  cout << "Value of ptr_k_B: " << ptr_k_B << endl;
  cout << "Value of k_ptr_a: " << k_ptr_a << endl;
  cout << "Value of k_ptr_k_b: " << k_ptr_k_b << endl;

  cout << "\n";

  // Thay đổi giá trị
  cout << "Change value\n";

  // a = 20
  *ptr_a += 10;
  // a = -30
  *k_ptr_a -= 50;
  /*
    Lỗi:
      assignment of read-only location '*ptr_k_B'
      assignment of read-only location '*(const int*)k_ptr_k_b'

    Không thể dùng con trỏ hằng để sửa đổi dữ liệu của vùng nhớ mà nó
    trỏ tới.

    Uncomment để thấy lỗi.
  */
  /*
  *ptr_k_B += 1;
  *k_ptr_k_b -= 500;
  */

  cout << "Value of a: " << a << endl;
  cout << "Value of k_b: " << k_b << endl;

  cout << "\n";

  cout << "Make constant pointer points to another address\n";

  /*
    Lỗi:
      assignment of read-only location '*k_ptr_k_b'
      assignment of read-only location '*k_ptr_a'

    Uncomment để thấy lỗi
  */
  /*
  k_ptr_k_b = &alternate;
  k_ptr_a = &alternate;
  */

  cout << "Value of ptr_k_B: " << ptr_k_B << endl;
  cout << "Value of ptr_k_B: " << k_ptr_a << endl;

  cout << "\n";

  return 0;
};

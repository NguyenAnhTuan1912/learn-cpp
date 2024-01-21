/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Pointer

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  // Khai báo các biến thông thường
  int a = 10;
  float b = 20.3;
  char c = 'c';

  // Khai báo các con trỏ
  int* ptr_a = &a;
  float* ptr_b = &b;
  char* ptr_c = &c;

  // In các con trỏ
  cout << "Print pointer\n";

  cout << "Value of ptr_a: " << ptr_a << endl;
  cout << "Value of ptr_b: " << ptr_b << endl;
  cout << "Value of ptr_c: " << ptr_c << endl;

  cout << "\n";

  // In phần giá trị của vùng nhớ mà con trỏ trỏ tới.
  cout << "Print value of memory location that pointer point to\n";

  cout << "Value of *ptr_a: " << *ptr_a << endl;
  cout << "Value of *ptr_b: " << *ptr_b << endl;
  cout << "Value of *ptr_c: " << *ptr_c << endl;

  cout << "\n";

  // Thay đổi giá trị của các biến trên thông qua con trỏ.
  *ptr_a += 10; // Tăng lên 10.
  *ptr_b -= 100; // Giảm đi 100.
  *ptr_c = 'T'; // Đổi thành T.

  /*
    Không nên dùng kiểu này, bởi vì con trỏ đang trỏ tới một vùng nhớ
    không mong muốn khác.
  */
  // ptr_a += 100;
  /*
    Lỗi: Invalid conversion from 'int' to 'int*'

    value của ptr_a buộc phải là một địa chỉ.
  */
  // ptr_a = 10;

  cout << "Change value with pointer\n";

  cout << "Value of *ptr_a: " << *ptr_a << endl;
  cout << "Value of *ptr_b: " << *ptr_b << endl;
  cout << "Value of *ptr_c: " << *ptr_c << endl;

  cout << "\n";

  // Con trỏ, con trỏ cấp 2
  cout << "Pointer and Pointer point to pointer\n";
  int m = 100;

  int* ptr_m = &m;
  int** ptr2_m = &ptr_m;

  // Value của ptr_ptr_m
  cout << "Value of ptr2_m: " << ptr2_m << endl;
  cout << "Value of *ptr2_m: " << *ptr2_m << endl; // == ptr_m
  cout << "Value of ptr_m: " << ptr_m << endl; // == *ptr2_m

  // Sửa đổi value của m qua con trỏ
  *ptr_m += 15;

  cout << "Value of *ptr_a: " << *ptr_m << endl;

  // Sửa lại địa chỉ mà ptr_m đang lưu về nullptr,
  // sau đó là sửa tiếp m thông qua ptr_m.
  // Cái này còn được gọi là con trỏ cấp 1.
  *ptr2_m = nullptr;
  /*
    Lỗi: Invalid conversion from 'int' to 'int*'

    value của *ptr2_m buộc phải là một địa chỉ,
    vì value của ptr_m là một địa chỉ :)))
  */
  // *ptr2_m = 100;
  // Tiếp tục sửa đổi value của m qua con trỏ
  /*
    Khi chạy chương trình thì thấy chương trình chạy về cuối khá chậm và bị sai,
    đồng thời thì dòng này không được in ra.

    Uncomment để thấy vấn đề
  */
  // *ptr_m -= 50;

  // cout << "Value of *ptr_m: " << *ptr_m << endl;

  cout << "\n";

  cout << "One variable, two pointers\n";
  int i = 9999;

  // Khai báo 2 con trỏ.
  int
    *ptr_01_i = &i,
    *ptr_02_i = ptr_01_i;

  cout << "Value of ptr_01_i: " << ptr_01_i << endl;
  cout << "Value of ptr_02_i: " << ptr_02_i << endl;
  cout << "Value of i: " << i << endl;

  // Thay đổi giá trị của i bằng 2 con trỏ
  *ptr_01_i += 1;
  *ptr_02_i += 2350;

  cout << "Value of i: " << i << endl;

  cout << "\n";

  return 0;
};

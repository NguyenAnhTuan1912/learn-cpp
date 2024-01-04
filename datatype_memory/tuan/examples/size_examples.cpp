/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ cho các ví dụ về:
  - Ví dụ về size của các kiểu dữ liệu.
  - Ví dụ về tràn size.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  // Khai báo các biến.
  char c = 'a';
  unsigned char u_c = 'b';
  wchar_t wc = 'c';
  int n = 1;
  unsigned int u_n = 2;
  short short_n = 3;
  unsigned short u_short_n = 4;
  long int long_n = 5;
  unsigned long int u_long_n = 6;
  long long int long_long_n = 7;
  unsigned long long int u_long_long_n = 8;
  float float_n = 1.0;
  double double_n = 3.0;
  long double l_double_n = 4.0;

  cout << "Size\n";

  cout << "Size of c: " << sizeof(c) << " byte(s)." << endl;
  cout << "Size of u_c: " << sizeof(u_c) << " byte(s)." << endl;
  cout << "Size of wc: " << sizeof(wc) << " byte(s)." << endl;
  cout << "Size of n: " << sizeof(n) << " byte(s)." << endl;
  cout << "Size of u_n: " << sizeof(u_n) << " byte(s)." << endl;
  cout << "Size of short_n: " << sizeof(short_n) << " byte(s)." << endl;
  cout << "Size of u_short_n: " << sizeof(u_short_n) << " byte(s)." << endl;
  cout << "Size of long_n: " << sizeof(long_n) << " byte(s)." << endl;
  cout << "Size of u_long_n: " << sizeof(u_long_n) << " byte(s)." << endl;
  cout << "Size of long_long_n: " << sizeof(long_long_n) << " byte(s)." << endl;
  cout << "Size of u_long_long_n: " << sizeof(u_long_long_n) << " byte(s)." << endl;
  cout << "Size of float_n: " << sizeof(float_n) << " byte(s)." << endl;
  cout << "Size of double_n: " << sizeof(double_n) << " byte(s)." << endl;
  cout << "Size of l_double_n: " << sizeof(l_double_n) << " byte(s)." << endl;

  cout << "\n";

  cout << "Size Overflow\n";

  // Tràn size (Size Overflow)
  // Range: [-32,768; 32,767]
  short over_short_1 = -32769; // Vì tràn bộ nhớ cho nên nó sẽ được assign 32767
  short over_short_2 = 32768; // Vì tràn bộ nhớ cho nên nó sẽ được assign -32768
  unsigned short over_short_3 = 65536; // Vì tràn bộ nhớ cho nên nó sẽ được assign 0

  int over_int_1 = 4294967296; // Vì tràn bộ nhớ cho nên nó sẽ được assign 0



  cout << "Value of over_short_1: " << over_short_1 << endl;
  cout << "Value of over_short_2: " << over_short_2 << endl;
  cout << "Value of over_short_3: " << over_short_3 << endl;
  cout << "Value of over_int_1: " << over_int_1 << endl;

  short n_1 = 32768;
  short n_2 = 50000;
  int valid_n_1 = 32768;
  int valid_n_2 = 50000;
  // Expect: 82768
  int sum_1 = n_1 + n_2;
  // Expect: 82768
  int true_sum_1 = valid_n_1 + valid_n_2;


  // Output: Value of n_1: -32768
  cout << "Value of n_1: " << n_1 << endl;
  // Output: Value of n_2: -15546
  cout << "Value of n_2: " << n_2 << endl;
  // Output: Value of sum_1: -48304
  cout << "Value of sum_1: " << sum_1 << endl;

  // Output: Value of valid_n_1: 82768
  cout << "Value of valid_n_1: " << valid_n_1 << endl;
  // Output: Value of valid_n_2: 50000
  cout << "Value of valid_n_2: " << valid_n_2 << endl;
  // Output: Value of true_sum_1: 82768
  cout << "Value of true_sum_1: " << true_sum_1 << endl;

  short first = 64000;
  short second = first;

  // Output: Value of first: 82768
  cout << "Value of first: " << first << endl;
  // Output: Value of second: 50000
  cout << "Value of second: " << second << endl;

  return 0;
}

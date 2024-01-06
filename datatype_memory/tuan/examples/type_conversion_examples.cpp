/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy ví dụ về chuyển đổi kiểu dữ liệu.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

int main() {
  // Kiểu int -> short
  // Khi gán số, thì mặc định số là kiểu dữ liệu int, nên khi nó thấy short, thì nó sẽ convert int -> short.
  short s_num = 12;

  // Kiểu int -> char
  // Không được vượt quá [-128; 255]
  char ch = 89;
  char over_ch = 256; // (1)

  // Kiểu double -> in
  // Mất dữ liệu
  double d_num = 323.125;
  int i_num = d_num;

  // Kiểu float -> bool
  float f_num = 23.3;
  bool b = f_num;

  cout << "Implicit Type Conversion\n";

  // Output: "Value of s_num: 12"
  cout << "Value of s_num: " << s_num << endl;
  // Output: "Value of ch: Y"
  cout << "Value of ch: " << ch << endl;
  // (1) Output: "Value of over_ch:"
  cout << "Value of over_ch: " << over_ch << endl;
  // Output: "Value of d_num: 323.125"
  cout << "Value of d_num: " << d_num << endl;
  // Output: "Value of i_num: 323"
  cout << "Value of i_num: " << i_num << endl;
  // Output: "Value of f_num: 23.3"
  cout << "Value of f_num: " << f_num << endl;
  // Output: "Value of b: 1"
  cout << "Value of b: " << b << endl;

  cout << "\n";

  cout << "\n";

  // Khai báo 2 kiểu dữ liệu khác nhau, sau đó cộng/trừ/nhân/chia
  short s01 = 2;
  char c01 = 'c'; // ASCII là c -> về decimal là 99
  int sum01 = s01 + c01; // = 2 + 99
  short diff01 = c01 - s01; // = 99 - 2
  float prod01 = s01 * c01; // = 99 * 2
  char quot01 = c01 / s01; // = 99 / 2

  // Output: "Value of sum01: 101"
  cout << "Value of sum01: " << sum01 << endl;
  // Output: "Value of diff01: 97"
  cout << "Value of bdiff01: " << diff01 << endl;
  // Output: "Value of prod01: 198"
  cout << "Value of prod01: " << prod01 << endl;
  // Output: "Value of quot01: 1" <-- Kiểu dữ liệu là char, không phải là số.
  cout << "Value of quot01: " << quot01 << endl;

  cout << "\n";

  cout << "Explicit Type Conversion\n";

  // Chuyển đổi với (type)
  double s_num02 = 23.241;
  char ch02 = 99;
  char ch03 = (char)s_num02 + ch02;

  // Output: "Value of s_num02: 23.241"
  cout << "Value of s_num02: " << s_num02 << endl;
  // Output: "Value of ch02: c"
  cout << "Value of ch02: " << ch02 << endl;
  // Output: "Value of ch03: z"
  cout << "Value of ch03: " << ch03 << endl;

  // Chuyển đổi với hàm.
  short s_num03 = static_cast<int>('z' + 23.24);

  // Output: "Value of s_num03: 145"
  cout << "Value of s_num03: " << s_num03 << endl;

  cout << "\n";

  // Một số trường hợp lỗi
  // 1. Chuyển đổi Non-scalar type -> Scalar type và ngược lại.
  // int n = "Hello";
  // char c = (char)"World.";
  // int arr[4];
  // double a = arr;
  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ cho các ví dụ về:
  - Ví dụ về các khai báo biến.
  - Ví dụ về các trường hợp lỗi.
  - Ví dụ về khai báo hằng và các trường hợp lỗi.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <typeinfo>
// #include <string>

using namespace std;

int main() {
  // Khai báo tĩnh (Statically Declare)
  // Khai báo kiểu số nguyên.
  int n = 1;

  // Cũng là khai báo kiểu số nguyên, nhưng ít bộ nhớ hơn.
  unsigned short short_n = 1;

  // Khai báo kiểu số thực.
  float float_n = 10.2;

  // Khai báo lần lượt kí tự và chuỗi (với chuỗi thì mình cần phải import thêm thư viện).
  char c = 'a';
  string text = "Hello world";

  // Khai báo động (Dynamically Declare), mình dùng từ khóa auto.
  auto name = "Nguyen Van B";

  // Một số khai báo lỗi
  // 1. Không thể gán giá trị cho biến trước khi nó được khai báo.
  // init = 10; // Throw: 'init' was not declared in this scope.
  // int init;

  // 2. Khai báo động cần phải có giá trị khởi tạo.
  // auto infer_type; // Throw: decalration of 'auto infer_type` has no initializer.

  // 3. Biến cần phái được khai báo.
  // known = "Has error?"; // Throw: 'known' was not declared in this scope.

  // 4. Khai báo không phù hợp.
  // unsigned double u_double_n = 23.12; // Throw: 'signed' or 'unsigned' invalid for 'u_double_n'.

  // 5. Khai báo lại biến trước đó.
  // int repeat = 100;
  // int repeat = 9; // Throw: redeclaration of 'int repeat'
  // float repeat = 10.0; // Throw: conflicting declaration 'float repeat'

  // 6. Gán giá trị có kiểu dữ liệu khác với khai báo
  // char wrong_char = "Error"; // Throw: invalid conversion from 'const char*' to 'char'.
  int wrong_int = 1.2; // Not error.

  // Khai báo một hằng số.
  const int kNum = 999;

  // Một số lỗi khi khai báo hằng
  // 1. Không có giá trị khởi tạo.
  // const float kG;

  // 2. Gán giá trị sau khi khai báo.
  // const string kName; kName = "Nguyen Anh C";

  cout << "Value of n: " << n << ", and type is " << typeid(n).name() << endl;
  cout << "Value of short_n: " << short_n << ", and type is " << typeid(short_n).name() << endl;
  cout << "Value of float_n: " << float_n << ", and type is " << typeid(float_n).name() << endl;
  cout << "Value of c: " << c << ", and type is " << typeid(c).name() << endl;
  cout << "Value of text: " << text << ", and type is " << typeid(text).name() << endl;
  cout << "Value of name: " << name << ", and type is " << typeid(name).name() << endl;
  cout << "Value of kNum: " << kNum << ", and type is " << typeid(kNum).name() << endl;

  return 0;
}

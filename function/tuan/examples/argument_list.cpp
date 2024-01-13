/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Argument List

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
// Include thư viện stdarg.h để xài
#include <stdarg.h>

// Khai báo một namespace
namespace ArgumentListExamples {

void Print(int N, ...) {
  va_list arg_ptr;

  va_start(arg_ptr, N);

  for(int i = 0; i < N; i++) {
    std::cout << va_arg(arg_ptr, char *);
    if(i < N - 1) std::cout << " ";
  };

  va_end(arg_ptr);
};

int Sum(int N, ...) {
  va_list arg_ptr;
  int sum = 0;

  va_start(arg_ptr, N);

  for(int i = 0; i < N; i++)
    sum += va_arg(arg_ptr, int);

  va_end(arg_ptr);

  return sum;
};

};

using namespace std;
using namespace ArgumentListExamples;

int main() {
  // In một chuỗi từ 2 chuỗi.
  // Output: "Ten toi la Nguyen Anh Tuan"
  Print(2, "Ten toi la", "Nguyen Anh Tuan");

  cout << "\n";

  // Tính tổng.
  Print(2, "Tong cua cac so", "trong Sum la: ");
  // Output: "Tong cua cac so trong Sum la: 130"
  cout << Sum(5, 2, 3, 100, -3, 28);

  cout << "\n";

  return 0;
};

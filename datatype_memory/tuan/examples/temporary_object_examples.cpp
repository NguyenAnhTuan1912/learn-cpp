/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Temporary Object

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

void TakeNonConstReference(int &a) {
  std::cout << "Lay tham chieu non-const.\n";
}

void TakeConstReference(const int &a) {
  std::cout << "Lay tham chieu const.\n";
}

void Takevalue(int a) {
  std::cout << "Lay gia tri.\n";
}

int GetValue() {
  // Trả về xvalue.
  return 21;
}

using namespace std;

int main() {
  // Khai báo 2 biến
  int
    // a là object và có giá trị là 33.
    // Hay là lvalue
    a = 33,
    /*
      Khi gọi hàm GetValue, bởi vì giá trị trả về của nó được gán lại cho b,
      nên trong tình huống này thì trình biên dịch sẽ không tạo Temporary Object,
      mà sẽ gán giá trị trả về cho b luôn.

      b là object và có giá trị là giá trị trả về của GetValue là một prvalue, hay
      là lvalue.
    */
    b = GetValue();

  cout << "Goi TakeNonConstReference.\n";
  TakeNonConstReference(a);

  cout << "\n";

  cout << "Goi TakeConstReference.\n";
  TakeConstReference(a);

  cout << "\n";

  cout << "Goi Takevalue.\n";
  Takevalue(a);

  cout << "\n";

  // Lỗi
  cout << "Goi TakeNonConstReference (Loi).\n";
  // Uncommemt để thấy lỗi
  // TakeNonConstReference(GetValue());

  return 0;
};

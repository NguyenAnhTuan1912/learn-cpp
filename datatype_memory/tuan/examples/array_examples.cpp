/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về mảng.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

int main() {
  short n = 5;
  // Khai báo một mảng số nguyên.
  int numbers[n] = { 1, 2, 3, 4, 5 };
  // Khai báo một mảng số thực.
  float float_numbers[n] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
  // Khao báo một mảng ký tự.
  char characters[n] = { 'a', 'b', 'c', 'd', 'e' };

  // In dữ liệu của numbers
  cout << "Values of numbers: : ";
  for(short i = 0; i < n; i++) {
    cout << numbers[i] << " ";
  };
  cout << "\n";

  // In dữ liệu của float_numbers
  cout << "Values of float_numbers: : ";
  for(short i = 0; i < n; i++) {
    cout << float_numbers[i] << " ";
  };
  cout << "\n";

  // In dữ liệu của characters
  cout << "Values of characters: : ";
  for(short i = 0; i < n; i++) {
    cout << characters[i] << " ";
  };
  cout << "\n";

  // Kiểu dữ liệu sẽ được tự động chuyển nếu như cùng là scalar type.
  cout << "Values of c: ";
  char c[n] = {'a', 'b', 'c', 'd', 114 };
  int i = 0;
  while(c[i]) {
    cout << c[i] << " ";
    i++;
  };
  cout << "\n";

  // Size của array có thể không cố định.
  short s[3];
  s[0] = 1;
  s[1] = 2;
  s[2] = 3;
  s[3] = 4;

  // In mảng đó ra.
  i = 0;
  while((!!s[i])) {
    cout << "[" << i << "]: " << s[i] << " ";
    i++;
  };
  cout << "\n";

  cout << "Number of members of s: " << sizeof(s) / sizeof(s[0]) << endl;
  cout << "Size of s: " << sizeof(s) << endl;
  if(s[3]) cout << "s[3] has value.\n";

  // Một số trường hợp lỗi.
  // 1. Gán dữ liệu khác với kiểu dữ liệu được khai báo.
  // numbers[6] = '6' // Đúng, giống với short, int, thì char cũng là một kiểu scalar.
  // numbers[6] = 7.0; // Đúng, giống với giải thích trên.
  // numbers[6] = true // Đúng, giống với giải thích trên.
  // numbers[6] = "6"; // Sai, vì string không còn thuộc scalar type nữa.
  // int test[1];
  // numbers[6] = test; // Sai, vì khác kiểu dữ liệu (cơ bản hơn là không thuộc scalar type).
  // cout << "Value of numbers[6]: " << numbers[6] << endl;
  return 0;
};

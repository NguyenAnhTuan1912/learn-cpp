/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về
  - Parameter
  - Argument
  - Reference
  - Value

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Hàm SumWithVal (tham trị - value)
int SumWithVal(int a, int b) {
  a += b;
  return a;
}

// Hàm SumWithRef (tham chiếu - reference)
int SumWithRef(int &a, int &b) {
  a += b;
  return a;
}

// Hàm SwapWithVal (tham trị - value)
void SwapWithVal(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
};

// Hàm SwapWithRef (tham chiếu - reference)
void SwapWithRef(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
};

// Hàm SayHello
void SayHello(string name) {
  cout << "Xin chao, toi ten la " << name << ".\n";
};

void SayHelloWithDefaultValue(string name = "Tuan", int age = 21) {
  cout
    << "Xin chao, toi ten la "
    << name
    << ". Nam nay toi "
    << age
    << " tuoi.\n";
};

int main() {
  /*
    Khai báo và gán cho hai biến tùy giá trị tùy thích
    để xem Value và Reference khác nhau như thế nào.
  */
  int
    a = 4,
    b = 23;

  // Output: "Gia tri cua a va b la: 4, 23"
  cout << "Gia tri cua a va b la: " << a << ", " << b << endl;
  cout << "Tinh tong cua a va b theo SumWithVal & SumWithRef\n";

  cout << "========" << "\n";

  // Tính tổng của a và b theo 2 hàm.
  // Output: "Tong a va b voi SumWithVal: 27"
  cout << "Tong a va b voi SumWithVal: " << SumWithVal(a, b) << endl;
  // Output: "Gia tri cua a va b la: 4, 23"
  cout << "Gia tri cua a va b la: " << a << ", " << b << endl;

  // Output: "Tong a va b voi SumWithRef: 27"
  cout << "Tong a va b voi SumWithRef: " << SumWithRef(a, b) << endl;
  // Output: "Gia tri cua a va b la: 27, 23"
  cout << "Gia tri cua a va b la: " << a << ", " << b << endl;

  cout << "\n";
  cout << "\n";

  // Gán cho a và b một giá trị khác.
  a = 12;
  b = 99;
  // Output: "Gia tri cua a va b la: 12, 99"
  cout << "Gia tri cua a va b la: " << a << ", " << b << endl;
  cout << "Hoan vi a va b theo SwapWithVal & SwapWithRef\n";

  cout << "========" << "\n";

  // Hoán vị hai số a và b theo 2 hàm.
  SwapWithVal(a, b);
  // Output: "Hoan vi a va b voi SwapWithVal: 12, 99"
  cout << "Hoan vi a va b voi SwapWithVal: " << a << ", " << b << endl;

  SwapWithRef(a, b);
  // Output: "Hoan vi a va b voi SwapWithRef: 99, 12"
  cout << "Hoan vi a va b voi SwapWithRef: " << a << ", " << b << endl;

  cout << "\n";

  // Ví dụ về default value
  cout << "Default value\n";

  cout << "========" << "\n";

  // Gọi hàm SayHello không có tham số truyền vào sẽ lỗi
  // Uncomment để thấy lỗi
  // SayHello();

  // Gọi hàm SayHello với tham số
  // Output: "Xin chao, toi ten la Tuan."
  SayHello("Tuan");

  // Gọi hàm SayHelloWithDefaultValue
  cout << "Goi ham SayHelloWithDefaultValue khong tham so!\n";
  // Output: "Xin chao, toi ten la Tuan. Nam nay toi 21 tuoi."
  SayHelloWithDefaultValue();
  cout << "Goi ham SayHelloWithDefaultValue co tham so!\n";
  // Output: "Xin chao, toi ten la Nguyen Tuan. Nam nay toi 120 tuoi."
  SayHelloWithDefaultValue("Nguyen Tuan", 120);

  cout << "\n";

  return 0;
};

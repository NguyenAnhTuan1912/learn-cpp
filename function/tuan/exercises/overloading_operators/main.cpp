#include <iostream>

#include "class/Point.h"

using namespace std;
// Sử dụng namespace đã định nghĩa
using namespace OverloadingOperators;

int main() {
  // Khởi tạo 2 points
  Point
    a(2, 3),
    b{ 3, 4 };

  cout << "Point a and b\n";
  // In 2 point ra màn hình
  a.PrintP();
  b.PrintP();
  cout << "\n";

  cout << "Increase a\n";
  // Thực hiện phép tăng tiến trên a.
  a++;

  // (3, 4)
  a.PrintP();
  cout << "\n";

  // Tổng a và b
  Point total = a + b;
  cout << "Total of a and b\n";

  // (6, 8)
  total.PrintP();
  cout << "\n";

  // Tích a và b
  Point product = a * b;
  cout << "Product of a and b\n";

  // (9, 16)
  product.PrintP();
  cout << "\n";

  // Tạo một điểm c có tọa độ giống a bằng phép gán
  cout << "Create c has same point with a\n";
  Point c;
  c = a;

  // (3, 4)
  c.PrintP();
  cout << "\n";

  // Cập nhập điểm b thông qua = và giảm b
  cout << "Update b with = and decrease\n";
  // (6, 14)
  b(3, 10);
  --b;

  // (5, 13)
  b.PrintP();
  cout << "\n";

  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về reference (lvalue reference).

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

struct Point {
  int x_;
  int y_;

  void Print() {
    cout << "(" << this->x_ << ", " << this->y_ << ")" << endl;
  }
};

// Chuyển dịch điểm sang phải 10 đơn vị với ref.
void MoveToRight10Units(Point& p) {
  p.x_ += 10;
};

int main() {
  // Tạo 2 point
  Point
    p{ 1, 2 },
    p_02{ 20, 15 };
  // Tạo 1 reference tới point
  /*
    Khác với pointer, ref không cần phải có toán tử
    & trước object.
  */
  Point& ref_p = p;
  /*
    Lỗi
      'ref_p_02' declared as reference but not initiallize
      cannot bind non-const lvalue reference type 'Point&' to an rvalue of type 'Point'

    Lvalue reference sẽ không thể tham chiếu tới nowhere, mà
    nó phải có một lvalue nào đó để cho nó tham chiếu.

    Uncomment để xem lỗi.
  */
  // Point& ref_p_02;
  // Point& ref_p_03 = Point{ 1, 3 };

  // In thông tin của p.
  cout << "Print with p\n";
  p.Print();
  cout << "Address of p: " << &p << endl;

  cout << "\n";

  cout << "Print with ref of p (ref_p)\n";
  ref_p.Print();
  cout << "Address of ref_p: " << &ref_p << endl;

  cout << "\n";

  // Thay đổi tham chiếu cho ref_p
  ref_p = p_02;

  cout << "Print with ref of p_02 (ref_p)\n";
  ref_p.Print();
  cout << "Address of ref_p: " << &ref_p << endl;

  cout << "\n";

  cout << "Move p_02 to right 10 units\n";
  // Dùng ref_p, nên p_02 sẽ được chỉnh sửa
  MoveToRight10Units(ref_p);

  // Sau đó in p_02 với ref_p và PrintPoint
  ref_p.Print();
  p_02.Print();
  p.Print();

  return 0;
};

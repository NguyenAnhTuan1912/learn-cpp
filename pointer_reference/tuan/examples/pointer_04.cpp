/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về object với pointer.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

struct Person {
  string name_;
  int age_;

  void Greet() {
    cout << this->GetGreetingText();
  };

  void Print() {
    cout << this->name_ << ", " << this->age_ << endl;
  };

  string GetGreetingText() {
    return "Hello, Toi ten la " + this->name_ + ". Nam nay toi " + to_string(this->age_) + " tuoi!!.\n";
  };
};

// Tạo ra hai hàm để sửa đổi dữ liệu.
void doSthWithVal(Person p) {
  cout << "Modifiy person in 'doSthWithVal' fn\n";
  // Sửa lại tuổi
  p.age_ += 50;
};

void doSthWithPointer(Person* p) {
  cout << "Modifiy person in 'doSthWithPointer' fn\n";
  // Sửa lại tuổi
  p->age_ += 50;
};

int main() {
  // Tạo ra 2 "Person"
  // Cấp phát trong Heap
  Person* ptr_p01 = new Person{ "Nguyen Anh Tuan", 21 };
  // Cấp phát trong Stack
  Person p02{ "Admin", 100 };

  cout << "Init and Greet\n";
  // Giới thiệu
  ptr_p01->Greet();
  p02.Greet();

  cout << "\n";
  /*
    Lỗi:
      request for member 'Greet' in 'ptr_p01', which is of pointer type 'Person*'
      base operand of '->' has non-pointer type 'Person'

      Lưu ý:
        - Với pointer khi trỏ tới một object, khi muốn truy cập vào member của object đó
        thì mình phải dùng toán tử '->'.
        - Với object thông thường (lvalue) thì mình phải dùng toán tử '.' khi muốn truy
        cập vào trong member của nó.

      Uncomment để thấy lỗi
  */
  /*
  ptr_p01.Greet();
  p02->Greet();
  */
  cout << "Change value of member in object\n";
  // Dùng hai function ở trên để chính sửa
  // In lại kết quả của 2 objects
  doSthWithVal(p02);
  p02.Print();
  doSthWithPointer(ptr_p01);
  ptr_p01->Print();

  cout << "\n";

  delete(ptr_p01);

  return 0;
};

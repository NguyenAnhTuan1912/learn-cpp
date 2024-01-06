/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ cho các ví dụ về:
  - Ví dụ về custom một type với struct.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

/*
  Tạo kiểu dữ liệu Person với struct, bao gồm 3 thông số:
  - Tên
  - Tuổi
  - Tình trạng sức khỏe
*/
struct Person {
  string name_ = "Default Name";
  short age_ = 20;
  string health_status_ = "Good";
};

int main () {
  cout << "Struct type\n";
  // Tạo một object Person mới với biến p1.
  // Cách 1.
  Person p1 { "Nguyen Anh Tuan", 21, "Good" };
  // Hoặc
  // Person p1 = { "Nguyen Anh Tuan", 21, "Good" };
  // Cách 2.
  Person p2;
  // Không gán giá trị.
  Person p3;

  p2.name_ = "Nguyen Thanh Trung";
  p2.age_ = 21;
  p2.health_status_ = "Good";

  // Sau đó là in các thông tin trong p1 ra.
  cout << "Person: [ name: " << p1.name_ << "; age: " << p1.age_ << "; health status: " << p1.health_status_ << " ]." << endl;
  cout << "Person: [ name: " << p2.name_ << "; age: " << p2.age_ << "; health status: " << p2.health_status_ << " ]." << endl;
  cout << "Person: [ name: " << p3.name_ << "; age: " << p3.age_ << "; health status: " << p3.health_status_ << " ]." << endl;

  cout << "\n";

  cout << "Size of Person: " << sizeof(Person) << endl;

  // Một số trường hợp lỗi.
  // 1. Khởi tạo sai giá trị.
  // Person wrong_p1 { 2, 21, "Good" }; // Throw: could not convert '2' from 'int' to 'std::__cxxll::string'.

  cout << "\n";

  return 0;
}

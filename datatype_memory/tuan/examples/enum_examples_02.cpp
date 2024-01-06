/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ ví dụ dùng struct với enum.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

/*
  Tạo một enum cho biết tình trạng sức khỏe, gòm các thông số đơn giản như là:
  - Very bad
  - Bad
  - Good
*/
enum HealthStatusEnum {
  kHealthStatus_Good = 'a',
  kHealthStatus_Bad = 'b',
  kHealthStatus_Very_Bad = 'c',
};

/*
  Tạo kiểu dữ liệu Person với struct, bao gồm 3 thông số:
  - Tên
  - Tuổi
  - Tình trạng sức khỏe
*/
struct Person {
  string name_;
  short age_;
  HealthStatusEnum health_status_;
};

int main() {
  cout << "Tao lan luot tung nguoi.\n";
  // Tạo một object Person mới với biến p1.
  // Cách 1.
  Person p1 { "Nguyen Anh Tuan", 21, kHealthStatus_Good };
  Person p3 { "Tran Van C", 999 };
  // Cách 2.
  Person p2;

  p2.name_ = "Nguyen Thanh Trung";
  p2.age_ = 21;
  p2.health_status_ = kHealthStatus_Good;

  // Sau đó là in các thông tin trong p1 ra.
  // Output: Person: [ name: Nguyen Anh Tuan; age: 21; health status: 97 ].
  cout << "Person: [ name: " << p1.name_ << "; age: " << p1.age_ << "; health status: " << p1.health_status_ << " ]." << endl;
  // Output: Person: [ name: Nguyen Thanh Trung; age: 21; health status: 97 ].
  cout << "Person: [ name: " << p2.name_ << "; age: " << p2.age_ << "; health status: " << p2.health_status_ << " ]." << endl;
  // Output: Person: [ name: Tran Van C; age: 999; health status: 0 ].
  cout << "Person: [ name: " << p3.name_ << "; age: " << p3.age_ << "; health status: " << p3.health_status_ << " ]." << endl;

  cout << "\n";

  cout << "Dung Array de tao mot danh sach.\n";
  // Tạo một danh sách Person
  // Khởi tạo n
  int n = 3;
  Person people[n] = {
    { "Nguyen Anh Tuan", 21, kHealthStatus_Good },
    { "Nguyen Thanh Trung", 21, kHealthStatus_Good },
    { "Tran Van C", 999 },
  };

  // In danh sách.
  for(short i = 0; i < n; i++) {
    cout << "Person: [ name: " << people[i].name_ << "; age: " << people[i].age_ << "; health status: " << people[i].health_status_ << " ]." << endl;
  };

  cout << "\n";

  return 0;
};

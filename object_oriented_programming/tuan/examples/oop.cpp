/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về OOP

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Định nghĩa lớp đối tượng Person
class Person {
public:
  string name_;
  short age_;
};

// Hàm này để in Person
void PrintPerson(Person& p) {
  cout << "Information\n";
  cout << "Name: " << p.name_ << endl;
  cout << "Age: " << p.age_ << endl;
};

int main() {
  // Khởi tạo một person
  // Cách 1
  Person p { "Nguyen Anh Tuan", 21 };
  // Cách 2
  Person p_02 = Person();
  /*
    Lỗi
      no matching function for call to 'Person::Person(const char[16], int)'

    Lỗi này sẽ dược giải thích trong các ví dụ sau.

    Uncomment để thấy lỗi.
  */
  // Person p_03 = Person("Nguyen Anh Tuan", 21);

  // Thêm thông tin cho p_02.
  p_02.name_ = "Nguyen Van A";
  p_02.age_ = 12;

  PrintPerson(p);
  cout << "\n";
  PrintPerson(p_02);

  return 0;
};

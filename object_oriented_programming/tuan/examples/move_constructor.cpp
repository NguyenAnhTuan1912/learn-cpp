/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về move constructor

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <vector>

using namespace std;

class A {
public:
  A() = default;
  // Copy constuctor
  A(const A& a) {
    this->text_ = std::move(a.text_);
    this->numbers_ = std::move(a.numbers_);
  };
  // Move constructor

  // A(A&& a) = default; // Hoặc

  string text_;
  std::vector<int> numbers_;

  void Print() {
    cout << "Text: " << this->text_ << endl;
    cout << "Numbers: ";
    int N = this->numbers_.size();
    for(int i = 0; i < N; i++) {
      if(i < N - 1) cout << this->numbers_[i] << " ";
      else cout << this->numbers_[i] << endl;
    };
  };
};

// Hàm này sẽ tạo ra một A và trả về rvalue.
A CreateA() {
  A a;
  a.text_ = "This instance is xvalue of CreateA";
  a.numbers_.push_back(1);
  a.numbers_.push_back(2);
  a.numbers_.push_back(3);
  return a;
};

int main() {
  // Khởi tạo các instances
  A a_01;
  A a_02 = A(CreateA());

  // Khởi tạo giá trị cho a_01
  a_01.text_ = "Instance nay duoc tao voi Default Constructor";
  a_01.numbers_.push_back(98);
  a_01.numbers_.push_back(99);
  a_01.numbers_.push_back(100);

  // In các thuộc tính
  a_01.Print();
  a_02.Print();

  return 0;
};


/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về move constructor

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Khởi tạo một class có destructor.
class A {
public:
  A() = default;
  ~A() {
    cout << this->text_;
  };

  string text_;
};

// Khởi tạo một class có thuộc tính được cấp phát trong Heap.
// Lớp này không có hàm khởi tạo mặc định.
class B {
public:
  B(int size_of_array) {
    this->size_of_numbers_ = size_of_array;
    this->numbers_ = new int[size_of_array];
    for(int i = 0; i < size_of_array; i++) this->numbers_[i] = i * 10;
  };
  ~B() {
    // Xóa thuộc tính trong Heap.
    cout << "Delete numbers_ in Heap\n";
    delete[] this->numbers_;
  };

  void Print() {
    for(int i = 0; i < this->size_of_numbers_; i++) {
      if(i < this->size_of_numbers_ - 1) cout << this->numbers_[i] << " ";
      else cout << this->numbers_[i] << endl;
    };
  };

private:
  int size_of_numbers_;
  int* numbers_{nullptr};
};

// Tạo một hàm tạo A
A CreateA() {
  A a;
  a.text_ = "Instance A nay se duoc huy trong CreateA\n";
  return A();
};

int main() {
  // Khởi tạo các instances
  A a_01;
  A a_02 = CreateA();

  // Gán text_
  a_01.text_ = "Instance A nay se duoc huy trong Main Scope\n";
  a_02.text_ = "Instance A thay vi duoc huy trong CreateA, se duoc huy trong Main Scope\n";

  // Goi CreatA
  CreateA();

  B b = B(5);

  b.Print();

  return 0;
};

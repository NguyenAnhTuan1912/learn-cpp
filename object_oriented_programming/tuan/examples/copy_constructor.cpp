/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về copy constructor

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Định nghĩa một lớp bình thường
class Normal {
public:
  Normal() = default;
  Normal(string text, int number): text_{text}, number_{number} {};

  string text_;
  int number_;

  void Print() { cout << "(" << this->text_ << ", " << this->number_ << ")\n"; };
};

/*
  Định nghĩa một lớp đối tượng có thể copy
  value trong instance của nó
*/
class CanCopy {
public:
  CanCopy() = default;
  CanCopy(string text, int number): text_{text}, number_{number} {};
  CanCopy(const CanCopy& cc) {
    this->text_ = cc.text_ + " [Copied!!!]";
    this->number_ = cc.number_;
  };

  string text_;
  int number_;

  void Print() { cout << "(" << this->text_ << ", " << this->number_ << ")\n"; };

  // Operator
  // Overload operator= dùng để copy.
  CanCopy& operator=(CanCopy& cc) {
    this->text_ = cc.text_;
    this->number_ = cc.number_;

    return *this;
  };
};

/*
  Định nghĩa một lớp đối tượng không thể copy
  value trong instance của nó.
*/
class CannotCopy {
public:
  CannotCopy() = default;
  CannotCopy(string text, int number): text_{text}, number_{number} {};
  CannotCopy(const CannotCopy& cc) = delete;

  string text_;
  int number_;

  void Print() { cout << "(" << this->text_ << ", " << this->number_ << ")\n"; };
};

/*
  Khởi tạo lớp đối tượng để làm thuộc tính trong lớp khác.
*/
class Child {
public:
  string text_;
  int numbers_[5];

  void PrintNumbers() {
    for(int i = 0; i < 5; i++) {
      if(i < 4) cout << this->numbers_[i] << " ";
      else cout << this->numbers_[i] << endl;
    };
  };
};

/*
  Khởi tạo một lớp đối tượng không có copy constructor.
*/
class NonCPCtor {
public:
  Child c_;
};

class HasCPCtor {
public:
  HasCPCtor() = default;
  HasCPCtor(const HasCPCtor& hcc) {
    this->c_ = Child(hcc.c_);
  };

  Child c_;
};

int main() {
  // Khởi tạo các instance
  Normal nl{"Day la instance cua Normal", 800};
  CanCopy cn_cpy{"Day la instance cua CanCopy", 900};
  CannotCopy cnt_cpy{"Day la instance cua CannotCopy", 1000};

  cout << "Value of originals\n";
  cout << "Value of nl: ";
  nl.Print();
  cout << "Value of cn_cpy: ";
  cn_cpy.Print();
  cout << "Value of cnt_cpy: ";
  cnt_cpy.Print();

  cout << "\n";

  // Khởi tạo các instance được copy từ các instance trên
  Normal copy_of_nl = Normal(nl);
  CanCopy copy_of_cn_cpy = CanCopy(cn_cpy);
  CanCopy copy_of_cn_cpy_02;
  // Thực hiện copy với =
  copy_of_cn_cpy_02 = cn_cpy;
  /*
    Lỗi
      use of deleted function 'CannotCopy::CannotCopy(const CannotCopy&)'

    Uncomment để thấy lỗi.
  */
  // CannotCopy copy_of_cnt_cpy = CannotCopy(cnt_cpy);

  cout << "Value of copy_of_nl: ";
  copy_of_nl.Print();
  cout << "Value of copy_of_cn_cpy: ";
  copy_of_cn_cpy.Print();
  cout << "Value of copy_of_cn_cpy_02: ";
  copy_of_cn_cpy_02.Print();

  cout << "\n";

  cout << "Address Checking\n";
  cout << "Address of nl: " << &nl << endl;
  cout << "Address of cn_cpy: " << &cn_cpy << endl;
  cout << "Address of cnt_cpy: " << &cnt_cpy << endl;
  cout << "Address of copy_of_nl: " << &copy_of_nl << endl;
  cout << "Address of copy_of_cn_cpy: " << &copy_of_cn_cpy << endl;
  cout << "Address of copy_of_cn_cpy_02: " << &copy_of_cn_cpy_02 << endl;

  cout << "\n";

  cout << "Copy constructor with non-scalar type\n";
  // Khởi tạo các instances
  NonCPCtor ncc;
  HasCPCtor hcc;

  // Gán text_ của c_
  ncc.c_.text_ = "Instance cua Child trong NonCPCtor";
  hcc.c_.text_ = "Instance cua Child trong HasCPCtor";
  // Khởi tạo numbers_ của c_
  ncc.c_.numbers_[0] = 1;
  ncc.c_.numbers_[1] = 2;
  ncc.c_.numbers_[2] = 3;
  ncc.c_.numbers_[3] = 4;
  ncc.c_.numbers_[4] = 5;
  hcc.c_.numbers_[0] = 100;
  hcc.c_.numbers_[1] = 99;
  hcc.c_.numbers_[2] = 98;
  hcc.c_.numbers_[3] = 97;
  hcc.c_.numbers_[4] = 96;

  // Khởi tạo các instances để copy
  NonCPCtor copy_of_ncc = ncc;
  HasCPCtor copy_of_hcc = HasCPCtor(hcc);

  // Sửa text_ của c_
  copy_of_ncc.c_.text_ = "(copy_of_ncc) Da bi sua doi";
  copy_of_hcc.c_.text_ = "(copy_of_hcc) Da bi sua doi";
  // Sủa numbers_ của c_
  copy_of_ncc.c_.numbers_[0] = 9999;
  copy_of_hcc.c_.numbers_[0] = 2024;

  // In các text_ của c_ trong từng instances
  cout << "Value of ncc.c_.text_: " << ncc.c_.text_ << endl;
  cout << "Value of hcc.c_.text_: " << hcc.c_.text_ << endl;
  cout << "Value of copy_of_ncc.c_.text_: " << copy_of_ncc.c_.text_ << endl;
  cout << "Value of copy_of_hcc.c_.text_: " << copy_of_hcc.c_.text_ << endl;
  // In numbers_ của c_ trong từng instances
  cout << "Value of ncc.c_.numbers_: "; ncc.c_.PrintNumbers();
  cout << "Value of hcc.c_.numbers_: "; hcc.c_.PrintNumbers();
  cout << "Value of copy_of_ncc.c_.numbers_: "; copy_of_ncc.c_.PrintNumbers();
  cout << "Value of copy_of_hcc.c_.numbers_: "; copy_of_hcc.c_.PrintNumbers();

  return 0;
};

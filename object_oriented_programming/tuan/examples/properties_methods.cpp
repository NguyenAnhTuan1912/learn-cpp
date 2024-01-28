/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về thuộc tính và phương thức

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <vector>

using namespace std;

// Khởi tạo class C
class C {
public:
  // Properties
  string id_;
  string a_id_;
  string name_;

  // Methods
  /*
    Phương thức này dùng để in thông tin của C
  */
  void Print() {
    cout << "i: " << this->id_ << ", " << this->a_id_ << ", " << this->name_ << endl;
  };
};

// Khởi tạo class ListC
class ListC {
public:
  // Properties
  std::vector<C> data;

  // Methods
  /*
    Phương thức này dùng để thêm một C vào trong danh sách.
  */
  void AddC(string id, string a_id, string name) {
    C c{ id, a_id, name };
    this->data.push_back(c);
  };

  /*
    Phương thức này dùng để lấy danh sách C của một A nào đó.
  */
  std::vector<C> GetCs(string id) {
    std::vector<C> result;
    int N = this->data.size();
    for(int i = 0; i < N; i++)
      if(this->data[i].a_id_ == id) result.push_back(this->data[i]);

    return result;
  };
};

// Khởi tạo class A
class A {
public:
  // Properties
  string id_;
  string name_;

  // Methods
  /*
    Phương thức này dùng để lấy ra danh sách C của riêng A
    trong danh sách C.
  */
  std::vector<C> GetCs(ListC& list_c_) {
    return list_c_.GetCs(this->id_);
  };
};

// Khởi tạo class B
class B {
public:
  // Properties
  string id_;
  string name_;
  ListC& list_c_;

  // Methods
  /*
    Phương thức này sẽ dùng list_c để lấy ra thông tin
    danh sách C của một A.
  */
  std::vector<C> GetCs(string id) {
    return this->list_c_.GetCs(id);
  };

  /*
    Phương thức này dùng để tạo một C vào trong list_c.
  */
  void CreateC(string id, string a_id, string name) {
    this->list_c_.AddC(id, a_id, name);
  };
};

// Hàm này nhận vào một list c để in
void PrintListC(std::vector<C> list_c) {
  int N = list_c.size();
  for(int i = 0; i < N; i++) list_c.at(i).Print();
};

int main() {
  // Tạo ra 2 instances A
  A
    a_01{ "A_01", "Nguyen Anh Tuan" },
    a_02{ "A_02", "Nguyen Van B" };
  // Tạo một list C
  ListC list_c;
  // Tạo một instance B
  B b{ "B_01", "Giang Vien A", list_c };

  // Thêm một C vào trong list.
  b.CreateC("C_01", a_01.id_, "Object C 01");
  b.CreateC("C_02", a_02.id_, "Object C 02");
  b.CreateC("C_03", a_02.id_, "Object C 03");
  b.CreateC("C_04", a_01.id_, "Object C 04");
  b.CreateC("C_05", a_02.id_, "Object C 05");
  b.CreateC("C_06", a_01.id_, "Object C 06");
  b.CreateC("C_07", a_01.id_, "Object C 07");

  // Lấy ra danh sách C của a_01 và a_02
  std::vector<C> list_c_a_01 = b.GetCs(a_01.id_);
  std::vector<C> list_c_a_02 = b.GetCs(a_02.id_);

  cout << "Method 1\n";

  // In danh sách C của a_01 và a_02
  cout << "List c cua a_01: \n";
  PrintListC(list_c_a_01);
  cout << "\n";

  cout << "List c cua a_02: \n";
  PrintListC(list_c_a_02);
  cout << "\n";

  cout << "Method 2\n";

  // In danh sách C của a_01 và a_02
  cout << "List c cua a_01: \n";
  PrintListC(a_01.GetCs(list_c));
  cout << "\n";

  cout << "List c cua a_02: \n";
  PrintListC(a_02.GetCs(list_c));
  cout << "\n";

  return 0;
};

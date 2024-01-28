/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ cơ bản về override

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

namespace Example_01 {

class Base {
public:
  Base() = default;
  Base(string t): text_(t) {};

  string text_ = "Gia tri mac dinh cua Base";

  virtual void Print() {
    cout << "(Base) Value of text_: " << text_ << endl;
  };
};

class Derived: public Base {
public:
  Derived() = default;
  Derived(string t): Base(t), text_(t) {};

  string text_ = "Gia tri mac dinh cua Derived";

  void Print() {
    cout << "(Derived) Value of text_: " << text_ << endl;
  };
};

};

namespace Example_02 {

class A {
public:
  A() = default;
  A(string t): text_(t) {};

  string text_ = "Gia tri mac dinh cua A";

  string GetText_01() {
    return text_;
  };

  virtual string GetText_02() {
    return text_;
  };
};

class B: public A {
public:
  B() = default;
  B(string t): A(t) { };

  string text_ = "Gia tri mac dinh cua B";

  string GetText_01() {
    return text_;
  };

  string GetText_02() {
    return text_;
  };
};

class C: public A {
public:
  C() = default;
  C(string t): A(t) {};

  string text_ = "Gia tri mac dinh cua C";

  string GetText_01() {
    return text_;
  };

  string GetText_02() {
    return text_;
  };
};

class D: public A {
public:
  D() = default;
  D(string t): A(t) {};

  string text_ = "Gia tri mac dinh cua D";

  string GetText_01() {
    return text_;
  };

  string GetText_02() {
    return text_;
  };
};

// Khởi tạo 2 hàm để in text_
void PrintWithVirtual(A& a) {
  cout << "Value of text_ with GetText_02: " << a.GetText_02() << endl;
};

void PrintWithoutVirtual(A& a) {
  cout << "Value of text_ with GetText_01: " << a.GetText_01() << endl;
};

};

int main() {
  // Khởi tạo các instances trong Example_01
  Example_01::Derived d;
  Example_01::Base* ptr_d = &d;
  Example_01::Base& ref_d = d;

  cout << "Print text_ directly\n";
  cout << "Value of d.text_: " << d.text_ << endl;
  cout << "Value of ptr_d->text_: " << ptr_d->text_ << endl;
  cout << "Value of ref_d.text_: " << ref_d.text_ << endl;

  cout << endl;

  cout << "Print text_ with Print()\n";
  d.Print();
  ref_d.Print();
  ptr_d->Print();
  ptr_d->Example_01::Base::Print();
  ref_d.Example_01::Base::Print();

  cout << endl;

  // Khởi tạo các instances trong Example_02
  Example_02::B instance_B("Initialize from constructor, but belong to A (BBB)");
  Example_02::C instance_C("Initialize from constructor, but belong to A (CCC)");
  Example_02::D instance_D("Initialize from constructor, but belong to A (DDD)");

  cout << "Get indirectly\n";
  cout << "Get text_ with virtual\n";
  cout << "Value of instance_B.text_: "; Example_02::PrintWithVirtual(instance_B);
  cout << "Value of instance_C.text_: "; Example_02::PrintWithVirtual(instance_C);
  cout << "Value of instance_D.text_: "; Example_02::PrintWithVirtual(instance_D);
  cout << endl;

  cout << "Get text_ without virtual\n";
  cout << "Value of instance_B.text_: "; Example_02::PrintWithoutVirtual(instance_B);
  cout << "Value of instance_C.text_: "; Example_02::PrintWithoutVirtual(instance_C);
  cout << "Value of instance_D.text_: "; Example_02::PrintWithoutVirtual(instance_D);
  cout << endl;

  cout << "Get directly\n";
  cout << "Get text_ with virtual\n";
  cout << "Value of instance_B.text_: " << instance_B.GetText_02() <<endl;
  cout << "Value of instance_C.text_: " << instance_C.GetText_02() <<endl;
  cout << "Value of instance_D.text_: " << instance_D.GetText_02() <<endl;
  cout << endl;

  cout << "Get text_ without virtual\n";
  cout << "Value of instance_B.text_: " << instance_B.GetText_01() <<endl;
  cout << "Value of instance_C.text_: " << instance_C.GetText_01() <<endl;
  cout << "Value of instance_D.text_: " << instance_D.GetText_01() <<endl;
  cout << endl;

  return 0;
};

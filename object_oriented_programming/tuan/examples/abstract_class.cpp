/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Abstract Class.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Tạo một abstract class Abstract.
class Abstract {
public:
  Abstract() = default;
  Abstract(string t): text_{t} {};

  string text_ = "Gia tri mac dinh cua Abstract::text_";

  virtual string GetText() { return text_; };
  virtual void SetText(string t) = 0;
  virtual void Print() = 0;
};

namespace Example_01 {

class B: public Abstract {
public:
  B() = default;
  B(string t): Abstract(t) {};

  void SetText(string t) { text_ = t; };
  void Print() {
    cout << "text_: " << text_ << endl;
  };
};

class C: public Abstract {
public:
  C() = default;
  C(string t): Abstract(t) {};
};

};

int main() {
  // Khởi tạo các instances
  Example_01::B conc{"Gia tri moi cho conc"};
  Abstract* ptr_conc = &conc;
  /*
    Lỗi
      cannot declare variable 'conc' to be of abstract type 'Example_01::C'

      Bởi vì trong Abstract có 2 pure virtual functions, nhưng mình không implement thằng nào cả,
      cho nên là mình sẽ phải định nghĩa 2 pure virtual functions đó, giống ở class B.

      Uncomment để thấy lỗi.
  */
  // Example_01::C conc_02{"Gia tri moi cho conc_02"};
  conc.Print();
  ptr_conc->Print();
  /*
    Lỗi
      undefined reference to 'Abstract::Print()'

    Uncomment để thấy lỗi.
  */
  // ptr_conc->Abstract::Print();
  cout << "Get text_ from method: " << conc.GetText() << endl;
  cout << "Get text_ from method: " << ptr_conc->GetText() << endl;
  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về namespace.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

// Các namespace sẽ được định nghĩa trên này.
// Giả sử các namespace được include từ file khác.

// Mình sẽ định nghĩa namespace trên này.
// Khi định nghĩa namespace ở file khác, thì nhớ include nó vào.
namespace Example {

short s_num_01 = 23;
std::string name = "Example";
std::string type = "namespace";

};

// Định nghĩa thêm một block khác cho namespace Example
namespace Example {

int a = 9999;

};

/*
  Mình có thể dùng từ khóa using namespace <namespace name>
  để sử dụng các members của namespace mà không cần access từ nó.
  Xem ở (2) bên dưới
*/
using namespace Example;

// Định nghĩa một unnamed/ anonymous namespace
/*
  Vì namespace này không có tên, nên mình không thể dùng từ khóa using namespace
  để sử dụng trực tiếp các member trong này.
*/
namespace {

std::string g_program_greeting = "Hello World!!!";

};

// Định nghĩa một Nested Namespace
namespace Parent {

short s_num_01 = 100;
std::string parent_name = "Parent";

  namespace Child {

  short s_num_01 = 99;
  std::string private_key = "231894hkjfa0-adfhxcjjk";
  std::string _name = "Child";

  // GetSayWord của Child có thể access vào name của Parent không?
  // Xem thêm (4)
  std::string GetSayWord() { return "Hello, this is " + parent_name + " namespace."; };
  // Xem thêm (5)
  /*
    GetAOfParent của Child access vào trong member và namespace
    này vẫn chưa biết được sự tồn tại của nó thì có được không?

    Lỗi từ khi compile.
  */
  // string GetAOfParent() { return Parent::a };

  };

// GetSayWord của Parent có thể access vào _name của Child không?
// Xem thêm (6)
std::string GetSayWord() { return "Hello, this is " + Child::_name + " namespace."; };

int a = 10000;

};

// Tách thử Parent::Child::GetAOfParent ra ngoài.
// Nếu không tách như này thì sẽ lỗi.
namespace Parent {

  namespace Child {

  int GetAOfParent() { return Parent::a; };

  };

};

// Sử dụng các members trong Parent mà không thông qua ::
using namespace Parent;

// Sử dụng inline cho nested namespace để thực hiện cơ chế phiên bản.
namespace PackageA {

  // Mình có một version cũ
  namespace v_1_0 {

  std::string version = "1.0.0";
  std::string GetValue() { return "Hello from version " + version; };

  };

  // Một version hiện tại
  // Mình có một version cũ
  inline namespace v_2_0 {

  std::string version = "2.0.0";
  std::string GetValue() { return "Hello from version " + version; };

  };

};

using namespace std;

int main() {
  // Giờ mình sẽ khai báo một biến có tên là s_num_01 giống trong namespace
  short s_num_01 = 99;

  cout << "Namespace\n";

  // (1)
  // Output: "Value of Example::s_num_01: 23"
  cout << "Value of Example::s_num_01: " << Example::s_num_01 << endl;
  // Output: "Value of Example::name: Example"
  // (2)
  // Output: "Value of Example::name: Example"
  cout << "Value of Example::name: " << name << endl;
  // Output: "Value of s_num_01: 99"
  cout << "Value of s_num_01: " << s_num_01 << endl;
  // (3)
  // a là member của namespace Example, nhưng được định nghĩa ở Scope khác
  // Output: "Value of Example::a: 9999"
  cout << "Value of Example::a: " << Example::a << endl;

  cout << "\n";

  cout << "Unnamed/ Anonymous Namespace\n";

  // Output: "Value of ::g_program_greeting: Hello World!!!"
  cout << "Value of ::g_program_greeting: " << ::g_program_greeting << endl;

  cout << "\n";

  cout << "Nested Namespace\n";

  // (4)
  // Output: "Value of Parent::Child::GetSayWord(): Hello, this is Parent namespace."
  cout << "Value of Parent::Child::GetSayWord(): " << Parent::Child::GetSayWord << endl;
  // (5)
  // Output: "Value of Parent::Child::GetAOfParent(): 10000"
  cout << "Value of Parent::Child::GetAOfParent(): " << Parent::Child::GetAOfParent() << endl;
  // (6)
  // Output: "Value of Parent::GetSayWord(): Hello, this is Child namespace."
  cout << "Value of Parent::GetSayWord(): " << Parent::GetSayWord() << endl;
  // Output: "Value of GetSayWord() (in Parent - namespace): Hello, this is Child namespace."
  cout << "Value of GetSayWord() (in Parent - namespace): " << GetSayWord() << endl;

  cout << "\n";

  cout << "Inline Namespace\n";

  // Output: "Value of PackageA::version: Hello, this is Child namespace."
  cout << "Value of PackageA::version: " << PackageA::version << endl;
  // Output: "Value of PackageA::GetValue(): Hello from version 2.0.0"
  cout << "Value of PackageA::GetValue(): " << PackageA::GetValue() << endl;
  // Output: "Value of PackageA::v_1_0::version: 1.0.0"
  cout << "Value of PackageA::v_1_0::version: " << PackageA::v_1_0::version << endl;
  // Output: "Value of PackageA::v_1_0::GetValue(): Hello from version 1.0.0"
  cout << "Value of PackageA::v_1_0::GetValue(): " << PackageA::v_1_0::GetValue() << endl;

  cout << "\n";

  return 0;
};

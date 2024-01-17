/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về lambda.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <algorithm>

using namespace std;

namespace {

string GetGreetingText(string name) {
  return "Hello, My name is " + name;
};

string GetGreetingText(auto GetName) {
  return "Hello, My name is " + GetName();
}

int GetMaxValue(int a, int b) {
  return a > b ? a : b;
};

}

// Tạo một struct là Person
struct Person {
  string name_;
  int age_;
};

int main() {
  // Khai báo một số biến
  int
    a = 10,
    b = 90;

  string
    first_name = "Anh Tuan",
    last_name = "Nguyen",
    mutable_str_01 = "This string can be mutated.";

  // Khai báo biến static, có thể access từ bên trong lambda
  // mà không cần phải capture
  static string dont_need_to_capture_text = "This is a static text and don't need to capture in any lambda.";

  //
  // Các lambda được khai báo ở đây
  //
  // Khai báo một lambda trong Main Scope
  auto _GetGreetingText_L = [](string name) -> string {
    return "Hello, My name is " + name;
  };

  // Khai báo một lambda dùng Capture Clause
  auto _GetSum_L = [a, b]() -> int {
    return a + b;
  };
  // Không thể dùng a và b khi trong Capture Clause không có a và b.
  // Uncomment rồi chạy sẽ thấy lỗi.
  /*
  auto GetSum02 = []() {
    return a + b;
  };
  */
  // Lambda có thể có overload không?
  // Trả lời: không thể
  auto _GetMax_L = [](int a, int b) -> int {
    return a > b ? a : b;
  };
  // Uncomment để thấy lỗi.
  /*
  auto GetMax = [](float a, float b) {
    return a > b ? a : b;
  };
  */
  // Khai báo một lambda để lấy tên.
  auto _GetName_L = [last_name, first_name]() -> string {
    return last_name + " " + first_name;
  };
  // Khai báo một biến mới trong Capture Clause
  auto _GetMaxValueText_L = [G = ::GetMaxValue](int a, int b) -> string {
    return "Max value between of two is " + to_string(G(a, b));
  };
  // Khai báo 2 lambda một là mutable và immutable
  // Immutable-captures lambda
  // Uncomment để thấy lỗi
  /*
  auto TryModifyingImmutableCaptures = [mutable_str_01]() {
    mutable_str_01 += " This value can mutate in lambda body!!!";
  };
  */
  // Mutable-captures lambda
  auto _TryModifyingMutableCaptures_L = [mutable_str_01]() mutable {
    mutable_str_01 += " This value can mutate in lambda body!!!";
    cout << mutable_str_01 << endl;
  };
  // Khai báo 2 lambda là GetPerson và GetPersonInvalidly
  auto _GetPerson_L = [](string name = "Nguyen Anh Tuan", int age = 21) -> Person {
    return { name, age };
  };
  // Lỗi
  // Uncomment để thấy lỗi.
  /*
  auto GetPersonInvalidly = [](string name = "Nguyen Anh Tuan", int age = 21) {
    return { name, age };
  };
  */
  // Khai báo một lambda để access vào static
  auto _AccessToStatic_L = []() {
    cout << "Static: " << dont_need_to_capture_text << endl;
  };
  //
  // Các lambda được khai báo ở trên
  //

  cout << "Use lambda and get typeof lambda\n";
  // Gọi lambda GetGreetingText
  cout << "Greeting text: " << _GetGreetingText_L("Nguyen Anh Tuan") << endl;
  // Output: "Max between a and b: 90"
  cout << "Max between a and b: " << _GetMax_L(a, b) << endl;
  // Kiển tra type của lambda GetGreetingText
  cout << "Type of GetGreetingText: " << typeid(_GetGreetingText_L).name() << endl;

  cout << "\n";

  cout << "Capture a and b\n";
  // Output: "Sum of a and b: 100"
  cout << "Sum of a and b: " << _GetSum_L() << endl;

  cout << "\n";

  cout << "Pass lambda to a function\n";
  // Output: "Greeting text: 90"
  cout << "Greeting text: " << ::GetGreetingText(_GetName_L) << endl;

  cout << "\n";

  cout << "Declare variable in Capture Clause\n";
  // Output: "Max value between of two is: -3"
  cout << _GetMaxValueText_L(-23, -3);

  cout << "\n\n";

  cout << "Multable and Immutable Captures\n";
  _TryModifyingMutableCaptures_L();

  cout << "\n";

  cout << "Call a lambda immediately\n";
  []() {
    int N = 5, arr[N] = { 1, 2, 3, 4, 5 };
    for(int i = 0; i < N; i++) {
      cout << arr[i] << " ";
    }
  }();

  cout << "\n\n";

  cout << "Return a struct from lambda with {} (initializer list)\n";
  auto p = _GetPerson_L();
  cout << "Name of p: " << p.name_ << endl;
  cout << "Age of p: " << p.age_ << endl;

  cout << "\n";

  cout << "Capture everything\n";
  // Khi capture với =, thì mọi biến được captured sẽ là const.
  [=]() {
    cout << "Inside a closure\n";

    cout << "Information of a person:\n";
    cout << "Name: " << p.name_ << endl;
    cout << "Age: " << p.age_ << endl;

    cout << "Mutable string: " << mutable_str_01 << endl;
  }();

  cout << "\n";

  cout << "Lambda can access a static which don't need to be captured\n";
  _AccessToStatic_L();

  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ cho các ví union.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

/*
  Tạo một kiểu dữ liệu union trong đó có các thuộc tính đơn giản như:
  - character_
  - float_number_
  - amount
*/
union Example01Union {
  char character_;
  float float_number_;
  short amount_;
};

union InvalueUnion {
  // string invalid_member_; // std::string không phải là một kiểu dữ liệu hợp lệ.
  // const short kConstant_; // Hằng số phải có giá trị khởi tạo.
  const short kHealth_ = 9999;
  int speed_;
};

int main () {
  cout << "Union type\n";

  // Khởi tạo một union
  // Đầu tiên là gán giá trị cho tất cả các members trong này.
  cout << "TH 1: Gan gia tri cho tat ca cac members.\n";
  Example01Union exp_union;

  // Thử gán dữ liệu giống như struct
  exp_union.character_ = 't';
  exp_union.float_number_ = 100.0123;
  exp_union.amount_ = 100;

  // Thử truy cập dữ liệu.
  // Output: "Value of exp_union.character_: d" // Dữ liệu bị sai
  cout << "Value of exp_union.character_: " << exp_union.character_ << endl;
  // Output: "Value of exp_union.float_number_: 100.001" // Dữ liệu bị sai
  cout << "Value of exp_union.float_number_: " << exp_union.float_number_ << endl;
  // Output: "Value of exp_union.amount_: 100"
  cout << "Value of exp_union.amount_: " << exp_union.amount_ << endl;

  cout << "\n";

  // Khởi tạo một union khác.
  // Lần này sẽ thử khởi tạo giống như với struct, nhưng chỉ được cho phép tạo 1 giá trị duy nhất.
  cout << "TH 2: Khoi tao voi mot gia tri duy nhat.\n";
  Example01Union exp_union_02 { 's' };
  // Hoặc
  // Example01Union exp_union_02 = { 's' };

  // Thử truy cập dữ liệu.
  // Output: "Value of exp_union.character_: s"
  cout << "Value of exp_union_02.character_: " << exp_union_02.character_ << endl;
  // Output: "Value of exp_union.float_number_: " // Trong trường hợp này biến sẽ được tạo ngẫu nhiên.
  cout << "Value of exp_union_02.float_number_: " << exp_union_02.float_number_ << endl;
  // Output: "Value of exp_union.amount_: " // Trong trường hợp này biến sẽ được tạo ngẫu nhiên.
  cout << "Value of exp_union_02.amount_: " << exp_union_02.amount_ << endl;

  cout << "\n";

  // Khởi tạo một union khác.
  // Lần này thì sẽ dùng nó theo cách thông thường.
  cout << "TH 2: Khoi tao voi mot gia tri duy nhat.\n";
  Example01Union exp_union_03;

  // Gán dữ liệu và in dữ liệu cho character_
  exp_union_03.character_ = 'A';
  // Output: "Value of exp_union.character_: A"
  cout << "Value of exp_union_03.character_: " << exp_union_03.character_ << endl;

  // Gán dữ liệu và in dữ liệu cho float_number_
  exp_union_03.float_number_ = 23.4;
  // Output: "Value of exp_union.float_number_: 23.4"
  cout << "Value of exp_union_03.float_number_: " << exp_union_03.float_number_ << endl;

  // Gán dữ liệu và in dữ liệu cho amount_
  exp_union_03.amount_ = 999;
  // Output: "Value of exp_union.amount_: 999"
  cout << "Value of exp_union_03.amount_: " << exp_union_03.amount_ << endl;

  cout << "\n";

  // Một số trường hợp lỗi
  // 1. Khởi tạo quá nhiều dữ liệu.
  // Example01Union exp_union_02 { 's', 23.4, 33 };
  // 2. Gán lần lượt các giá trị cho các thuộc tính và dùng sau đó. Xem ở trường hợp khởi tạo đầu tiên.
  // 3. Không thể khai báo được std::string (xem ở trên).
  // 4. Constant trong union bị replace dữ liệu.
  InvalueUnion invalid_union;

  // Output: "Value of invalid_union.kHealth_: 9999"
  cout << "Value of invalid_union.kHealth_: " << invalid_union.kHealth_ << endl;

  // Gán dữ liệu và in dữ liệu cho speed_
  invalid_union.speed_ = 50;
  // Output: "Value of invalid_union.speed_: 50"
  cout << "Value of invalid_union.speed_: " << invalid_union.speed_ << endl;
  // Output: "Value of invalid_union.kHealth_: 50" // Constant đã bị replace
  cout << "Value of invalid_union.kHealth_: " << invalid_union.kHealth_ << endl;

  // 5. Không thể gán cho const, đương nhiên rồi, nhưng vẫn có thể bị thay đổi.
  // invalid_union.kHealth_ = 10000;

  return 0;
}

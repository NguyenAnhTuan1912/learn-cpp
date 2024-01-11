/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về scope (global và local).

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Ở ngoài này là Global Scope.
string g_str_value_01 = "Day la bien toan cuc.";

int main() {
  // Ở trong này là Local Scope, cụ thể là local scope của hàm main.
  // Gọi là Main Scope.
  // Cấp L-1
  string str_value_01 = "Day la bien o Main Scope";

  {
    // Ở trong này cũng là một Local Scope, thấp hơn Main Scope.
    // Gọi là Block Scope
    // Cấp L-2
    // Các iđentifiers ở scope cao hơn có thể dùng ở scope thấp hơn.
    cout << "Block Scope - 2\n";
    cout << "Value of g_str_value_01 in (Block Scope - 2): " << g_str_value_01 << endl;
    cout << "Value of str_value_01 in (Block Scope - 2): " << str_value_01 << endl;
  }

  cout << "\n";

  if(true) {
    // Ở trong này cũng là một Local Scope, thấp hơn Main Scope.
    // Gọi là If...else Scope.
    // Cấp L-2
    cout << "If...else Scope - 2\n";
    cout << "Value of g_str_value_01 in (If...else - 2): " << g_str_value_01 << endl;
    cout << "Value of str_value_01 in (If...else - 2): " << str_value_01 << endl;
  };

  cout << "\n";

  short i = 0;
  while(i < 1) {
    // Ở trong này cũng là một Local Scope, thấp hơn Main Scope.
    // Gọi là While Scope.
    // Cấp L-2
    cout << "While Scope - 2\n";
    cout << "Value of g_str_value_01 in (While Scope - 2): " << g_str_value_01 << endl;
    cout << "Value of str_value_01 in (While Scope - 2): " << str_value_01 << endl;

    cout << "\n";

    {
      // Ở trong này cũng là một Local Scope, thấp hơn While Scope ở ngoài.
      // Cấp L-3
      cout << "Block Scope - 3\n";
      cout << "Value of g_str_value_01 in (Block Scope - 3): " << g_str_value_01 << endl;
      cout << "Value of str_value_01 in (Block Scope - 3): " << str_value_01 << endl;
    }
    i++;
  };

  cout << "\n";

  i = 0;
  string day;
  switch(i) {
    // Switch không có scope. Nên trong trường hợp này các Case Scope sẽ thấp hơn Main Scope.
    case 2: {
      // Ở trong này cũng là một Local Scope
      // Cấp L-2
      // Tương tự với các Case Scope còn lại.
      cout << "Case Scope - 2\n";
      cout << "Value of g_str_value_01 in (Case Scope - 2): " << g_str_value_01 << endl;
      cout << "Value of str_value_01 in (Case Scope - 2): " << str_value_01 << endl;
      day = "Monday";
      break;
    };

    case 4: {
      day = "Wednesday";
      cout << "Case Scope - 2\n";
      cout << "Value of g_str_value_01 in (Case Scope - 2): " << g_str_value_01 << endl;
      cout << "Value of str_value_01 in (Case Scope - 2): " << str_value_01 << endl;

      cout << "\n";

      {
        // Ở trong này cũng là một Local Scope
        // Cấp L-3
        cout << "Block Scope - 3\n";
        cout << "Value of g_str_value_01 in (Block Scope - 3): " << g_str_value_01 << endl;
        cout << "Value of str_value_01 in (Block Scope - 3): " << str_value_01 << endl;
        day = "Thu tu";
      }
      break;
    };

    default: {
      // Gọi chung là Case Scope.
      cout << "Case Scope - 2\n";
      cout << "Value of g_str_value_01 in (Case Scope - 2): " << g_str_value_01 << endl;
      cout << "Value of str_value_01 in (Case Scope - 2): " << str_value_01 << endl;

      cout << "\n";

      {
        // Cấp L-3
        // Sửa giá trị của day
        day = "Day khong phai la mot ngay hop le.";
        cout << "Block Scope - 3\n";
        cout << "Value of day in (Block Scope - 3): " << day << endl;

        cout << "\n";

        {
          // Cấp L-4
          // Sửa giá trị của day
          day = "Thu nhat";
          cout << "Block Scope - 4\n";
          cout << "Value of day in (Block Scope - 4): " << day << endl;
        }
      }

      cout << "\n";

      // Sửa giá trị của day
      day = "This is not a valid date in week.";
      cout << "Case Scope - 2\n";
      cout << "Value of day in (Case Scope - 2): " << day << endl;
      break;
    };
  };

  cout << "\n";

  cout << "Main Scope - 1\n";
  cout << "Value of day in (Main Scope - 1): " << day << endl;

  cout << "\n";

  for(int i = 0; i < 1; i++) {
    // Ở trong này cũng là một Local Scope, thấp hơn Main Scope.
    // Cấp L-2
    cout << "For Scope - 2\n";
    cout << "Value of g_str_value_01 in (For Scope - 2): " << g_str_value_01 << endl;
    cout << "Value of str_value_01 in (For Scope - 2): " << str_value_01 << endl;

    cout << "\n";

    {
      // Cấp L-3
      cout << "Block Scope - 3\n";
      cout << "Value of g_str_value_01 in (Block Scope - 3): " << g_str_value_01 << endl;
      cout << "Value of str_value_01 in (Block Scope - 3): " << str_value_01 << endl;
    }
  };

  cout << "\n";

  return 0;
};

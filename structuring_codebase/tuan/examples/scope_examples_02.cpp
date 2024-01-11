/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về visibility.
  Và ví Block Scope nó cũng giống như các Local Scope khác, cho nên
  bài ví dụ này thì mình chỉ lấy ví dụ với Block Scope.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Ở ngoài này là Global Scope.
string g_str_value_01 = "Day la bien g_str_value_01 toan cuc.";

int main() {
  cout << "Main Scope - 1\n";
  string str_value_01 = "Day la bien str_value_01 trong Main Scope.";

  // Đầu tiên là ví dụ về Visibility.
  // Ví dụ 1
  {
    // Tạo một biến có tên y hệt với str_value_01
    string str_value_01 = "Day la bien str_value_01 trong Block Scope - 2";

    cout << "Block Scope - 2\n";
    cout << "Value of str_value_01 in (Block Scope - 2): " << str_value_01 << endl;
    {
      // Vậy thì trong đây sẽ như thế nào?
      cout << "Block Scope - 3\n";
      cout << "Value of str_value_01 in (Block Scope - 3): " << str_value_01 << endl;
    }
  }

  cout << "Value of str_value_01 in (Main Scope - 1): " << str_value_01 << endl;

  cout << "\n";

  // Ví dụ 2
  cout << "Main Scope - 1\n";
  string str_value_02 = "Day la bien str_value_02 trong Main Scope.";

  {
    cout << "Block Scope - 2\n";
    // Thử với Block Scope có độ sâu cao hơn
    {
      // Cấp L-3
      cout << "Block Scope - 3\n";
      cout << "Value of g_str_value_01 in (Block Scope - 3): " << g_str_value_01 << endl;
      {
        // Cấp L-4
        cout << "Block Scope - 4\n";
        {
          cout << "Block Scope - 5\n";
          cout << "Value of str_value_02 in (Block Scope - 5): " << str_value_02 << endl;
        }
      }
    }
  }

  cout << "\n";

  // Ví dụ 3
  // Khai báo một biến trong Scope có độ sâu cao hơn
  // Và thử xem Scope có độ sâu thấp hơn có thể "thấy" được không?
  {
    string bs_01_str_value_01 = "Day la bien bs_01_str_value_01 trong Main Scope.";
  }

  cout << "Main Scope - 1\n";
  cout << "Error: bs_01_str_value_01 was not declare in this scope.\n";
  // cout << "Value of bs_01_str_value_01 in (Main Scope - 1): " << bs_01_str_value_01 << endl;

  cout << "\n";

  // Ví dụ 4
  // Ở đây mình sẽ ví dụ phức tạp hơn
  int a = 10;

  {
    int b = 2;
    a += 5;
    b++;

    {
      int a = 20;
      a -= 10;
    }

    a++;

    if(b >= 2) {
      a += 23;
    } else {
      a -= 4;
    }
  }

  cout << "Main Scope - 1\n";
  cout << "Value of a in (Main Scope - 1): " << a << endl;

  cout << "\n";

  return 0;
};

/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về accessibility.
  Và ví Block Scope nó cũng giống như các Local Scope khác, cho nên
  bài ví dụ này thì mình chỉ lấy ví dụ với Block Scope.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

# include <iostream>

using namespace std;

int g_i_num_01 = 15;

int AddTwoNumberWithGNum(int a, int b) {
  // Dòng này sẽ bị lỗi
  /*
    Ví tham số int a được tính là một biến cục bộ
    của hàm AddTwoNumberWithGNum, nên int a trong thâm
    hàm AddTwoNumberWithGNum có nghĩa là mình đang khai báo
    biến a 2 lần, hay khai báo lại biến a.
  */
  // int a = 10;
  return a + b + g_i_num_01;
};

int main() {
  // Ví dụ 1
  cout << "Main Scope - 1\n";
  short s_num_01 = 10;

  {
    s_num_01 += 10;
    {
      short s_num_01 = 10;
      s_num_01 += 12;
    }
  }

  if(s_num_01 >= 20) {
    s_num_01 -= 2;

    if(s_num_01 <= 18) {
      short s_num_01 = 2;
      s_num_01 += 2;
    }

    s_num_01++;
  }

  cout << "Value of s_num_01 in (Main Scope - 1): " << s_num_01 << endl;

  cout << "\n";

  // Ví dụ 2
  short
    s_num_02 = 10,
    s_num_03 = -3,
    result_01 = AddTwoNumberWithGNum(s_num_02, s_num_03);
  cout << "Main Scope - 1\n";
  cout << "Value of result_01 in (Main Scope - 1): " << result_01 << endl;

  return 0;
};

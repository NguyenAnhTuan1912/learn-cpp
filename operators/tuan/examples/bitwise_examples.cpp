/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử bitwise.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  cout << "Use integer\n";
  short
    s_num_01 = 2,
    s_num_02 = 5,
    // & là AND ở level bits
    result_01 = s_num_01 & s_num_02,
    // | là OR ở level bits
    result_02 = s_num_01 | s_num_02,
    // ^ là XOR ở level bits (ở dưới)
    result_03,
    // >> là chuyển dịch bits sang phải 1 đơn vị.
    result_04 = s_num_01 >> 1,
    // << là chuyển dịch bits sang phải 2 đơn vị.
    result_05 = s_num_02 << 2;

  // Output: "Value of result_01: 0"
  /*
    Nó được tính như sau:
    2 -> 00000010
    5 -> 00000101
    &
    r -> 00000000 = 0
    Vì 1 AND 1 = 1, còn lại sẽ là 0.
  */
  cout << "Value of result_01: " << result_01 << endl;

  // Output: "Value of result_02: 7"
  /*
    Nó được tính như sau:
    2 -> 00000010
    5 -> 00000101
    |
    r -> 00000111 = 7
    Vì 0 OR 0 = 0, còn lại sẽ là 1.
  */
  cout << "Value of result_02: " << result_02 << endl;

  s_num_01 = 13;
  s_num_02 = 9;
  result_03 = s_num_01 ^ s_num_02;
  // Output: "Value of result_03: 4"
  /*
    Nó được tính như sau:
    13 -> 00001101
    09 -> 00001001
    ^
     r -> 00000100 = 4
    Vì cùng trạng thái sẽ là 0, còn lại sẽ là 1.
  */
  cout << "Value of result_03: " << result_03 << endl;

  // Output: "Value of result_04: 1"
  // 2 -> 00000010 >> 1 = 00000001 -> 1
  cout << "Value of result_04: " << result_04 << endl;
  // Output: "Value of result_05: 4"
  // 5 -> 00000101 << 2 = 00010100 -> 20
  cout << "Value of result_05: " << result_05 << endl;

  // Đảo bits tất cả các kết quả.
  // Phép toán bits này khá phức tạp. Để cho dễ thì mình sẽ convert sang unsigned short (vì ban đầu khai báo short).
  // Output: "Value of ~result_01: 65535"
  // 0 -> ~00000000 00000000 = 11111111 11111111 -> 65535
  cout << "Value of ~result_01: " << (unsigned short)~result_01 << endl;
  // Output: "Value of ~result_02: 65528"
  // 7 -> ~00000000 00000111 = 11111111 11111000 -> 65528
  cout << "Value of ~result_02: " << (unsigned short)~result_02 << endl;
  // Output: "Value of ~result_03: 65531"
  // 4 -> ~ 00000000 00000100 = 11111111 11111011 -> 65531
  cout << "Value of ~result_03: " << (unsigned short)~result_03 << endl;
  // Output: "Value of ~result_04: 65534"
  // 1 -> ~00000000 00000001 = 11111111 11111110 -> 65534
  cout << "Value of ~result_04: " << (unsigned short)~result_04 << endl;
  // Output: "Value of ~result_05: 65515"
  // 20 -> ~00000000 00010100 = 11111111 11101011 -> 65515
  cout << "Value of ~result_05: " << (unsigned short)~result_05 << endl;

  cout << "\n";

  cout << "Use char\n";
  char
    c_01 = 'a',
    c_02 = 'c',
    // Lặp lại tất cả các toán tử trên với ký tự.
    result_06 = c_01 & c_02,
    result_07 = c_01 | c_02,
    result_08 = c_01 ^ c_02,
    result_09 = c_01 >> 3,
    result_10 = c_02 << 2;

    // Output: "Value of result_06: a"
    /*
      Nó được tính như sau:
      a -> 97 -> 01100001
      c -> 99 -> 01100011
      &
      r       -> 01100001 = 97 -> a
    */
    cout << "Value of result_06: " << result_06 << endl;
    // Output: "Value of result_07: c"
    /*
      Nó được tính như sau:
      a -> 97 -> 01100001
      c -> 99 -> 01100011
      |
      r       -> 01100011 = 99 -> c
    */
    cout << "Value of result_07: " << result_07 << endl;
    // Output: "Value of result_08: "
    /*
      Nó được tính như sau:
      a -> 97 -> 01100001
      c -> 99 -> 01100011
      ^
      r       -> 00000010 = 2 -> STX (start of text)
      Đây là kí tự điều khiển nên không hiện lên màn hình
    */
    cout << "Value of result_08: " << result_08 << endl;
    // Output: "Value of result_09: \n"
    // a -> 97 -> 01100001 >> 3 = 00001100 -> 12 -> FF (NP form feed, new page)
    // Đây là kí tự điều khiển nên không hiện lên màn hình.
    cout << "Value of result_09: " << result_09 << endl;
    // Output: "Value of result_10: î"
    // c -> 99 -> 01100011 << 2 = 10001100 -> 140 -> î
    // Đây là kí tự điều khiển nên không hiện lên màn hình
    cout << "Value of result_10: " << result_10 << endl;

    // Đảo bits của c_nn
    // Output: "Value of ~c_01: -98"
    cout << "Value of ~c_01: " << ~c_01 << endl;
    // Output: "Value of ~c_02: -100"
    cout << "Value of ~c_02: " << ~c_02 << endl;

  return 0;
};

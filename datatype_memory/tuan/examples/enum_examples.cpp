/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ cho các ví dụ về:
  - Ví dụ về custom một type với enum.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>

using namespace std;

/*
  Tạo kiểu dữ liệu Enum màu, gồm các thông số đơn giản như là:
  - black
  - green
  - blue
  - red

  Với struc thì mình không cần phải thêm hậu tố như enum. Còn với enum thì mình phải tên hậu tố Enum
*/
enum ColorEnum {
  kColor_Black = 1,
  kColor_Green = 2,
  kColor_Blue = 3,
  kColor_Red = 4
};

// Định nghĩa một enum mà không gán bất cứ giá trị nào.
enum DefaultEnum {
  kDefault_Value01,
  kDefault_Value02,
  kDefault_Value03
};

/*
  Định nghĩa một enum, mà trong đó phần tử đầu được gán giá trị (số nguyen).
  Còn lại thì không.
*/
enum AutoEnum {
  kAuto_Value01 = 5,
  kAuto_Value02,
  kAuto_Value03
};

/*
  Định nghĩa một enum, mà trong đó phần tử đầu được gán giá trị (ký tự).
  Còn lại thì không.
*/
enum Auto02Enum {
  kAuto02_Value01 = 'd',
  kAuto02_Value02,
  kAuto02_Value03
};

/*
  Định nghĩa một enum, mà trong đó sẽ được gán nhiều kiểu dữ liệu khác nhau,
  và phần tử được gán là ngẫu nhiên.
*/
enum Auto03Enum {
  kAuto03_Value01 = 'd',
  kAuto03_Value02 = 10,
  kAuto03_Value03,
  kAuto03_Value04,
  kAuto03_Value05,
  kAuto03_Value06,
  kAuto03_Value07 = -9,
  kAuto03_Value08
};

enum CorrectEnum {
  kCorrect_Value01 = 'c', // Đúng
  kCorrect_Value02 = kAuto02_Value01 // Đúng
};

// Trường hợp (1) lỗi của enum.
enum Wrong01Enum {
  // kWrong01_Value01 = "Error", // Sai
  // kWrong01_Value02 = 22.3l // Sai
};

// Trường hợp (3) lỗi của enum
enum Wrong02Enum {
  // kCorrect_Value01 = kAuto02_Value01 // Sai
};

int main() {
  cout << "Enum type\n";

  // Default enum
  cout << "Default Enum\n";
  cout << "Khong co phan tu nao trong enum nay duoc gan gia tri, tat ca deu la mac dinh.\n";

  cout << "Value of kDefault_Value01: " << kDefault_Value01 << endl; // 0
  cout << "Value of kDefault_Value02: " << kDefault_Value02 << endl; // 1
  cout << "Value of kDefault_Value03: " << kDefault_Value03 << endl; // 2

  cout << "\n";

  // Auto01 enum
  cout << "Auto Enum\n";
  cout << "Phan tu dau tien cua enum nay duoc gan gia tri.\n";

  cout << "Value of kAuto_Value01: " << kAuto_Value01 << endl; // 5
  cout << "Value of kAuto_Value02: " << kAuto_Value02 << endl; // 6
  cout << "Value of kAuto_Value03: " << kAuto_Value03 << endl; // 7

  cout << "\n";

  // Auto02 enum
  cout << "Auto02 Enum\n";
  cout << "Phan tu dau tien cua enum nay duoc gan gia tri la mot ky tu.\n";

  cout << "Value of kAuto02_Value01: " << kAuto02_Value01 << endl; // 100
  cout << "Value of kAuto02_Value02: " << kAuto02_Value02 << endl; // 101
  cout << "Value of kAuto02_Value03: " << kAuto02_Value03 << endl; // 102

  cout << "\n";

  // Auto02 enum
  cout << "Auto03 Enum\n";
  cout << "Mot so phan tu duoc gan gia tri mot cach ngay nhien, va khac kieu du lieu.\n";

  cout << "Value of kAuto03_Value01: " << kAuto03_Value01 << endl; // 100
  cout << "Value of kAuto03_Value02: " << kAuto03_Value02 << endl; // 10
  cout << "Value of kAuto03_Value03: " << kAuto03_Value03 << endl; // 11
  cout << "Value of kAuto03_Value04: " << kAuto03_Value04 << endl; // 12
  cout << "Value of kAuto03_Value05: " << kAuto03_Value05 << endl; // 13
  cout << "Value of kAuto03_Value06: " << kAuto03_Value06 << endl; // 14
  cout << "Value of kAuto03_Value07: " << kAuto03_Value07 << endl; // -9
  cout << "Value of kAuto03_Value08: " << kAuto03_Value08 << endl; // -8

  cout << "\n";

  cout << "Dung enum voi condition statement.\n";
  // Dùng enum
  int color_1 = 1;
  switch(color_1) {
    case kColor_Black: {
      cout << kColor_Black << ". Mau den \n";
      break;
    }

    case kColor_Green: {
      cout << kColor_Green << ". Mau xanh la \n";
      break;
    }

    case kColor_Blue: {
      cout << kColor_Blue << ". Mau xanh nuoc bien \n";
      break;
    }

    case kColor_Red: {
      cout << kColor_Red << ". Mau do \n";
      break;
    }

    default: {
      cout << "Chua co mau nay \n";
      break;
    }
  };

  cout << "\n";

  // Một số trường hợp lỗi.
  // 1. Định nghĩa enum mà gán giá trị không phải là integral trong enum (xem ở trên).
  // 2. Gán giá trị mới cho property trong Enum.
  // kColor_Black = 10;
  // 3. Khai báo tên phần tử của enum trùng với tên phần tử của một enum khác (xenm ở trên).

  cout << "\n";

  return 0;
};

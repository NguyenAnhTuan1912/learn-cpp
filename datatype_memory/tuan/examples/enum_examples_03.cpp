/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ ví dụ 2 enum giống nhau (về giá trị của từng thành phần).

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/
#include <iostream>
#include <typeinfo>

using namespace std;

enum CarCategoryEnum {
  kCarCategory_Normal,
  kCarCategory_Super,
  kCarCategory_Hyper,
};

enum BikeCategoryEnum {
  kBikeCategory_Normal,
  kBikeCategory_Electric,
  kBikeCategory_Sport,
};

int main() {
  // Giờ thì mình sẽ dùng switch case để cho thấy điều đáng lưu ý ở đây.
  // Nếu như mình gán như thế này thì rất đúng logic.
  // switch(kBikeCategory_Electric)
  // Nhưng nếu như thế này thì lại khác.

  switch(kCarCategory_Super) {
    case kBikeCategory_Normal: {
      cout << "Bike binh thuong.\n";
      break;
    }

    case kBikeCategory_Electric: {
      cout << "Bike dien.\n";
      break;
    }

    case kBikeCategory_Sport: {
      cout << "Bike the thao.\n";
      break;
    }

    default: {
      cout << "Bike chua co loai nay!\n";
      break;
    }
  };

  // Cả hai biến đều cho output là "Bike dien".

  // Check type cho 2 phần từ có cùng giá trị ở 2 enum khác nhau.
  // Output: "Type of kCarCategory_Super: 15CarCategoryEnum"
  cout << "Type of kCarCategory_Super: " << typeid(kCarCategory_Super).name() << endl;
  // Output: "Type of kBikeCategory_Electric: 16BikeCategoryEnum"
  cout << "Type of kBikeCategory_Electric: " << typeid(kBikeCategory_Electric).name() << endl;

  return 0;
};

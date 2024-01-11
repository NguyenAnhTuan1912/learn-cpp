/*
  Nếu dùng namespace thì mình không cần phải tạo class cho string utils.
  Và với inline namespace thì mình lại càng nên dùng namespace cho utils.

  Trong 2 namespace v1 và v2 thì mình sẽ cùng khai báo một function để cắt chuỗi,
  sự khác biệt giữa hai function này là
    - v1: không có khoảng trắng giữa 2 chuỗi, không bỏ đi khoảng trắng ở 2 đầu.
    - v2: có khoảng trắng giữa 2 chuỗi, bỏ đi khoảng trắng ở 2 đầu.
*/

// (2)
// Khai báo một unnamed namespace cho các private function
namespace {

std::string Trim(std::string text) {

  // Xóa spaces ở đầu. Tìm kí tự không phải là khoảng trắng rồi xóa
  // từ đầu đến chỗ tìm được (Tìm từ đầu về cuối chuỗi).
  text = text.erase(0, text.find_first_not_of(' '));
  // Xóa spaces ở cuối, Tìm kí tự không phải là khoảng trắng rồi xóa
  // từ chỗ tìm được tới cuối (Tìm từ cuối về đầu chuỗi).
  text = text.erase(text.find_last_not_of(' ') + 1);
  return text;
};

};

namespace StringUtils {
  std::string version = "2.3.4";

  // Phiên bản của của string utils
  namespace v1 {

  std::string Concate(std::string str_01, std::string str_02) {
    return str_01 + str_02;
  };

  };

  // Phiên bản hiện tại của string utils
  inline namespace v2 {

  std::string Concate(std::string str_01, std::string str_02) {
    // Bỏ khoảng trắng ra khỏi hai chuỗi.
    str_01 = ::Trim(str_01);
    str_02 = ::Trim(str_02);

    // Nối chuỗi.
    str_01.append(" ");
    str_01.append(str_02);

    return str_01;
  };

  };

};

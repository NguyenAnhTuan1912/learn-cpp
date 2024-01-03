#include <string>

namespace string_utils {

/**
 * Dùng hàm này để nối 2 chuỗi lại với nhau.
 * @param str1 Chuỗi thứ nhất
 * @param str2 Chuỗi thứ hai
 * @return
 *
 */

std::string Concate(std::string str1, std::string str2) {
  str1.append(str2);
  return str1;
};

}

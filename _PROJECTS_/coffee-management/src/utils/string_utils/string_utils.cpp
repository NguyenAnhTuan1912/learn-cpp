#include <algorithm>

#include "string_utils.h"

namespace CoffeeShop {
namespace Utils {
namespace String {

std::string ToUpperCase(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
  return s;
};

std::vector<std::string> Split(std::string str, std::string seperator) {
  size_t p_start = 0, p_end, l = seperator.length();
  std::string token;
  std::vector<std::string> result;

  while((p_end = str.find(seperator, p_start)) != std::string::npos) {
    token = str.substr(p_start, p_end - p_start);
    p_start = p_end + l;
    result.push_back(token);
  };

  return result;
};

};
};
};

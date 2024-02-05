#include <algorithm>

#include "string_utils.h"

namespace CoffeeShop {
namespace Utils {
namespace String {

std::string ToUpperCase(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
  return s;
};

};
};
};

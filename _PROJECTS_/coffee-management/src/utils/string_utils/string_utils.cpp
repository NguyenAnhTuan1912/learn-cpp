#include <algorithm>

// Add utils
#include "string_utils.h"
#include "../number_utils/number_utils.h"

namespace CoffeeShop {
namespace Utils {
namespace String {

std::string ToUpperCase(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
  return s;
};

std::string GenerateRandom(std::string prefix, int length) {
  std::string alphabet = "abcdefghijklmnopqrstuvw0123456789xyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string result = "";
  int N = alphabet.length();

  for(int i = 0; i < length; i++) {
    result += alphabet[Utils::Number::GetRandom(N)];
  };

  if(prefix != "" || prefix.length() == 0) result = prefix + "_" + result;

  return result;
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

bool IsStringEmpty(std::string str) {
  if(str.length() == 0) return true;
  int i = 0;
  while(str[i] != '\0') {
    if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r') return false;
    i++;
  };
  return true;
};

bool IsStringEmpty(int c) {
  if(c != ' ' && c != '\n' && c != '\t' && c != '\r') return false;
  return true;
};

};
};
};

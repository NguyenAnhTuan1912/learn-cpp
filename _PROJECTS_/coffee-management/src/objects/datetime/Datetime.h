#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include <ctime>
#include <regex>

// Add macros
#include "../../macros/date_format.h"

namespace CoffeeShop {

class Datetime {
private:
  time_t _date_ = time(NULL);

public:
  Datetime() = default;
  Datetime(std::string datetime);
  Datetime(int timestamp): _date_(timestamp) {};

  static std::regex DATE_FORMAT_FULL_REGEX;
  static std::regex DATE_FORMAT_NORMAL_REGEX;
  static std::regex DATE_FORMAT_ONLY_DATE_REGEX;
  static std::regex DATE_FORMAT_ONLY_TIME_REGEX;

  // Other methods
  std::string GetFullDatetimeStr();
  std::string GetDatetimeStr();
  std::string GetDateStr();
  std::string GetTimeStr();

  // Other operators
};

};

#endif // DATETIME_H_INCLUDED

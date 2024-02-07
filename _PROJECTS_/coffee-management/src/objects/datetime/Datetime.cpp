#include <sstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>
#include <exception>
#include <regex>
#include <sstream>

#include "Datetime.h"

// Add utils
#include "../../utils/string_utils/string_utils.h"

namespace CoffeeShop {

std::regex Datetime::DATE_FORMAT_FULL_REGEX(DATE_FORMAT_FULL_PATTERN);
std::regex Datetime::DATE_FORMAT_NORMAL_REGEX(DATE_FORMAT_NORMAL_PATTERN);
std::regex Datetime::DATE_FORMAT_ONLY_DATE_REGEX(DATE_FORMAT_ONLY_DATE_PATTERN);
std::regex Datetime::DATE_FORMAT_ONLY_TIME_REGEX(DATE_FORMAT_ONLY_TIME_PATTERN);

Datetime::Datetime(std::string datetime) {
  try {
    std::smatch m;
    std::tm tm{};

    if(std::regex_match(datetime, Datetime::DATE_FORMAT_NORMAL_REGEX)) {
      int day, month, year, hour, minute, second;
      std::regex_match(datetime, m, Datetime::DATE_FORMAT_NORMAL_REGEX);
      std::string date = m[1], time = m[2];

      std::replace(date.begin(), date.end(), '/', ' ');
      std::replace(time.begin(), time.end(), ':', ' ');

      std::istringstream(date) >> day >> month >> year;
      std::istringstream(time) >> hour >> minute >> second;

      std::cout << "Date: " << m[1] << std::endl;
      std::cout << "Time: " << m[2] << std::endl;

      tm.tm_mday = day;
      tm.tm_mon = month - 1;
      tm.tm_year = year - 1900;
      tm.tm_hour = hour;
      tm.tm_min = minute;
      tm.tm_sec = second;
    }
    else if(std::regex_match(datetime, Datetime::DATE_FORMAT_ONLY_DATE_REGEX)) {
      int day, month, year;
      std::regex_match(datetime, m, Datetime::DATE_FORMAT_ONLY_DATE_REGEX);
      std::string date = m[1];
      std::replace(date.begin(), date.end(), '/', ' ');

      std::istringstream(date) >> day >> month >> year;

      std::cout << "Date: " << m[1] << std::endl;
      std::cout << "Day: " << day << std::endl;
      std::cout << "Month: " << month << std::endl;
      std::cout << "Year: " << year << std::endl;

      tm.tm_mday = day;
      tm.tm_mon = month - 1;
      tm.tm_year = year - 1900;
    }

    this->_date_ = std::mktime(&tm);
  } catch(const std::exception& e) {
    std::cerr << e.what();
  }
};

std::string Datetime::GetDateStr() {
  char result[256];

  // Convert to date
  std::strftime(result, sizeof(result), DATE_FORMAT_ONLY_DATE, std::localtime(&this->_date_));

  return result;
};

std::string Datetime::GetTimeStr() {
  char result[256];

  // Convert to date and time
  std::strftime(result, sizeof(result), DATE_FORMAT_ONLY_TIME, std::localtime(&this->_date_));

  return result;
};

std::string Datetime::GetDatetimeStr() {
  char result[256];

  // Convert to date and time
  std::strftime(result, sizeof(result), DATE_FORMAT_NORMAL, std::localtime(&this->_date_));

  return result;
};

std::string Datetime::GetFullDatetimeStr() {
  char result[256];

  // Convert to date and time
  std::strftime(result, sizeof(result), DATE_FORMAT_FULL, std::localtime(&this->_date_));

  return result;
};

};

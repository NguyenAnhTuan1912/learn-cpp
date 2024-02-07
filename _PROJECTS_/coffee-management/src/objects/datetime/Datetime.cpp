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

// Define static properties
std::regex Datetime::DATE_FORMAT_FULL_REGEX(DATE_FORMAT_FULL_PATTERN);
std::regex Datetime::DATE_FORMAT_NORMAL_REGEX(DATE_FORMAT_NORMAL_PATTERN);
std::regex Datetime::DATE_FORMAT_ONLY_DATE_REGEX(DATE_FORMAT_ONLY_DATE_PATTERN);
std::regex Datetime::DATE_FORMAT_ONLY_TIME_REGEX(DATE_FORMAT_ONLY_TIME_PATTERN);

// Defined static methods
bool Datetime::CheckDatetimeStrFullFormat(std::string datetime) {
  return std::regex_match(datetime, Datetime::DATE_FORMAT_FULL_REGEX);
};

bool Datetime::CheckDatetimeStrNormalFormat(std::string datetime) {
  return std::regex_match(datetime, Datetime::DATE_FORMAT_NORMAL_REGEX);
};

bool Datetime::CheckDatetimeStrOnlyDateFormat(std::string datetime) {
  return std::regex_match(datetime, Datetime::DATE_FORMAT_ONLY_DATE_REGEX);
};

bool Datetime::CheckDatetimeStrOnlyTimeFormat(std::string datetime) {
  return std::regex_match(datetime, Datetime::DATE_FORMAT_ONLY_TIME_REGEX);
};

bool Datetime::CheckDatetimeStr(std::string datetime) {
  if(Datetime::CheckDatetimeStrFullFormat(datetime)) return true;
  if(Datetime::CheckDatetimeStrNormalFormat(datetime)) return true;
  if(Datetime::CheckDatetimeStrOnlyDateFormat(datetime)) return true;
  if(Datetime::CheckDatetimeStrOnlyTimeFormat(datetime)) return true;

  return false;
};

// Define primary members
Datetime::Datetime(std::string datetime) {
  try {
    std::smatch m;
    std::tm tm_time = *std::localtime(&this->_date_);

    if(std::regex_match(datetime, m, Datetime::DATE_FORMAT_NORMAL_REGEX)) {
      int day, month, year, hour, minute, second;
      std::string date = m[1], time = m[2];

      std::replace(date.begin(), date.end(), '/', ' ');
      std::replace(time.begin(), time.end(), ':', ' ');

      std::istringstream(date) >> day >> month >> year;
      std::istringstream(time) >> hour >> minute >> second;

      tm_time.tm_mday = day;
      tm_time.tm_mon = month - 1;
      tm_time.tm_year = year - 1900;
      tm_time.tm_hour = hour;
      tm_time.tm_min = minute;
      tm_time.tm_sec = second;
    } else if(std::regex_match(datetime, m, Datetime::DATE_FORMAT_ONLY_DATE_REGEX)) {
      int day, month, year;
      std::string date = m[1];
      std::replace(date.begin(), date.end(), '/', ' ');

      std::istringstream(date) >> day >> month >> year;

      tm_time.tm_mday = day;
      tm_time.tm_mon = month - 1;
      tm_time.tm_year = year - 1900;
    } else if(std::regex_match(datetime, m, Datetime::DATE_FORMAT_ONLY_TIME_REGEX)) {
      int hour, minute, second;
      std::string time = m[1];

      std::replace(time.begin(), time.end(), ':', ' ');

      std::istringstream(time) >> hour >> minute >> second;

      tm_time.tm_hour = hour;
      tm_time.tm_min = minute;
      tm_time.tm_sec = second;
    } else throw std::runtime_error("This format of datetime isn't supported!!!");

    this->_date_ = std::mktime(&tm_time);
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

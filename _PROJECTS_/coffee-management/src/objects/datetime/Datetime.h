#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include <ctime>
#include <regex>

// Add macros
#include "../../macros/date_format_macros.h"

namespace CoffeeShop {

class Datetime {
private:
  time_t _date_ = time(nullptr);

public:
  Datetime() = default;
  Datetime(std::string datetime);
  Datetime(time_t t): _date_(t) {};

  // Getters
  virtual time_t GetDatetime() final { return this->_date_; };

  // Setters
  virtual void SetDatetime(time_t date) final { this->_date_ = date; };

  // Static properties
  static std::regex DATE_FORMAT_FULL_REGEX;
  static std::regex DATE_FORMAT_NORMAL_REGEX;
  static std::regex DATE_FORMAT_ONLY_DATE_REGEX;
  static std::regex DATE_FORMAT_ONLY_TIME_REGEX;

  // Static methods
  static bool CheckDatetimeStrFullFormat(std::string datetime);
  static bool CheckDatetimeStrNormalFormat(std::string datetime);
  static bool CheckDatetimeStrOnlyDateFormat(std::string datetime);
  static bool CheckDatetimeStrOnlyTimeFormat(std::string datetime);
  static bool CheckDatetimeStr(std::string datetime);

  // Other methods
  /** \brief Use to get datetime string as "a, dd/MM/yyyy hh:mm:ss" (Full) format
   *
   * \return A full datetime format string
   *
   */
  std::string GetFullDatetimeStr();

  /** \brief Use to get datetime string as "dd/MM/yyyy hh:mm:ss" (Normal) format
   *
   * \return A normal datetime format string
   *
   */
  std::string GetDatetimeStr();

  /** \brief Use to get datetime string as "dd/MM/yyyy" (Only-date) format
   *
   * \return A only-date datetime format string
   *
   */
  std::string GetDateStr();

  /** \brief Use to get datetime string as "hh:mm:ss" (Only-time) format
   *
   * \return A only-time datetime format string
   *
   */
  std::string GetTimeStr();

  /** \brief Use to get distance between 2 dates.
   *
   * \param &dt A reference of Datetime instance
   * \return A distance between 2 dates as epoch.
   *
   */

  virtual double GetDistance(Datetime& dt) final {
    return difftime(this->_date_, dt.GetDatetime());
  };

  // Other operators
  virtual bool operator>(Datetime& dt) final { return this->_date_ > dt.GetDatetime(); };
  virtual bool operator<(Datetime& dt) final { return this->_date_ < dt.GetDatetime(); };
  virtual bool operator>=(Datetime& dt) final { return this->_date_ >= dt.GetDatetime(); };
  virtual bool operator<=(Datetime& dt) final { return this->_date_ <= dt.GetDatetime(); };
  virtual bool operator==(Datetime& dt) final { return this->_date_ == dt.GetDatetime(); };
  virtual bool operator!=(Datetime& dt) final { return this->_date_ != dt.GetDatetime(); };
};
};

#endif // DATETIME_H_INCLUDED

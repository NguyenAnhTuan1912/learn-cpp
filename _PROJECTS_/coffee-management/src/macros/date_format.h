#ifndef DATE_FORMAT_H_INCLUDED
#define DATE_FORMAT_H_INCLUDED

#define DATE_FORMAT_FULL "%a, %d/%m/%Y %H:%M:%S"
#define DATE_FORMAT_NORMAL "%d/%m/%Y %H:%M:%S"
#define DATE_FORMAT_ONLY_DATE "%d/%m/%Y"
#define DATE_FORMAT_ONLY_TIME "%H:%M:%S"

#define DATE_FORMAT_FULL_PATTERN "(\\w+), (\\d{2}\\/\\d{2}\\/\\d{4}) (\\d{2}:\\d{2}:\\d{2})"
#define DATE_FORMAT_NORMAL_PATTERN "(\\d{2}\\/\\d{2}\\/\\d{4}) (\\d{2}:\\d{2}:\\d{2})"
#define DATE_FORMAT_ONLY_DATE_PATTERN "(\\d{2}\\/\\d{2}\\/\\d{4})"
#define DATE_FORMAT_ONLY_TIME_PATTERN "(\\d{2}:\\d{2}:\\d{2})"

#endif // DATE_FORMAT_H_INCLUDED

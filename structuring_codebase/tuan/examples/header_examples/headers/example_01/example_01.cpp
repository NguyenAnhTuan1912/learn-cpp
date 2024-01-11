/*
  Để chạy được chương trình thì file này phải được link
  với main.cpp trong quá trình build.
*/
#include <iostream>
#include <string>

#include "example_01.h"

/*
Example01::name = "Example 01";
Example01::topic = "Day la mot vi du ve header file - Vi du 1";

std::string Example01::Greet() {
    return "Hello, day la header file cua " + Example01::name;
}

std::string Example01::GetName() {
    return Example01::name;
}

std::string Example01::GetTopic() {
    return Example01::topic;
}
*/

namespace Example01 {
    std::string name = "Example 01";
    std::string topic = "Day la mot vi du ve header file - Vi du 1";

    std::string Greet() {
        return "Hello, day la header file cua " + name;
    }

    std::string GetName() {
      return name;
    }

    std::string GetTopic() {
        return topic;
    }
}

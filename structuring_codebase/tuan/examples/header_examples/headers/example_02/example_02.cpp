/*
  Để chạy được chương trình thì file này phải được link
  với main.cpp trong quá trình build.
*/
#include <iostream>
#include <string>

#include "example_02.h"

// Định nghĩa một unnamed namespace
namespace {

// Internal Linkage
const std::string hidden = "Bien nay da duoc an di boi example_02.h";

std::string ProveThatUnnamedNamespaceIsHiddenWithAnotherTU() { return "That's right"; };

};

namespace Example02 {

const std::string g_name = "Example 02";
const short s_num_01 = 9999;
std::string GetHiddenMessage() { return ::hidden; };

};

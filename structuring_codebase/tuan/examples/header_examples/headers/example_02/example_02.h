/*
  Giờ thì mình khai báo một namespace tên là Exampe02
  với một số biến extern và một số function.
*/
#pragma once
#ifndef EXAMPLE_02_H
#define EXAMPLE_02_H

// Định nghĩa một unnamed namespace
namespace {

// Internal Linkage
extern const std::string hidden;
std::string ProveThatUnnamedNamespaceIsHiddenWithAnotherTU();

};

namespace Example02 {

extern const std::string g_name;
extern const short s_num_01;
std::string GetHiddenMessage();

};

#endif /* EXAMPLE_02_H */

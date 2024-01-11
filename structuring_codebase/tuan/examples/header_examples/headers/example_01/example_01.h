/*
  Trong này mình sẽ khai báo một số biến cho namespace Example01
  của file header này.
*/
#pragma once
#ifndef EXAMPLE_01_H
#define EXAMPLE_01_H
namespace Example01 {

extern std::string name;
extern std::string topic;

std::string GetName();
std::string GetTopic();
std::string Greet();

};

#endif /* EXAMPLE_01_H */

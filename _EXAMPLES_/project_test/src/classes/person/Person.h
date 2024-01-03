#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
  public:
    // Constructors & Desctructor.
    Person();
    Person(std::string name, unsigned short age);
    virtual ~Person();

    // Properties
    std::string name_;
    unsigned short age_;

    // Methods
    void InputInformation();
    void PrintInformation();
  protected:

  private:
};

#endif // PERSON_H

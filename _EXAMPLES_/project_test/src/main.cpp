#include <iostream>

#include "classes/person/Person.h"

#include "utils/string/string_utils.h"

using namespace std;

int main() {
    cout << "Example of project structure in Learn CPP.\n";

    // Tạo object Person mới với tên (indentifier) là p.
    Person p1;
    // Tạo một object khác với default constructor và params constructor.
    Person p2 { "Nguyen Van B", 30 };
    Person p3 {};

    // Nhập thông tin cho p
    p1.InputInformation();

    // Nối chuỗi
    p3.name_ = string_utils::Concate(p3.name_, "Tran Van B");

    // Dùng phương thức PrintInformation để in thông tin của p ra.
    p1.PrintInformation();
    p2.PrintInformation();
    p3.PrintInformation();

    return 0;
}

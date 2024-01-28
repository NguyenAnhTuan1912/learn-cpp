/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Access Qualifiers.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

class A {
  /*
    name_ là private, không thể access từ bên ngoài.
  */
  string name_;
};

class B {
public:
  // Constructor
  // Cho B() là default.
  B() = default;
  B(string id, string last_name, string first_name, short age) {
    this->_id_ = id;
    this->last_name_ = last_name;
    this->first_name_ = first_name;
    this->age_ = age;
  };

  /*
    first_name_ và last_name_ đều có thể access từ bên ngoài.
  */
  string first_name_;
  string last_name_;

  void Print() {
    cout
      << "B: "
      << _id_ << ", "
      << GetFullname() << ", "
      << age_ << ".\n";
  };

protected:
  /*
    age_ chỉ có thể access từ bên trong class và các lớp
    kế thừa.
  */
  short age_;

  string GetFullname() {
    return this->first_name_ + " " + this->last_name_;
  };

private:
  /*
    _id_ và _type_ không thể access từ bên ngoài.
  */
  string _id_;
  string _type_ = "Human";
};

class C {
public:
  int value_ = 100;

private:
  C() = default;
};

class D {
public:
  D(int value) { this->value_ = value; };

  int value_ = 100;

private:
  D() = default;
};

int main() {
  /*
    Lỗi
      no matching function for call to 'A::A({...})'

    Bởi vì trong class A không có member nào có quyền access tới
    cho nên khi gọi constructor thì sẽ không thể tạo instance
    với default constructor được.

    Uncomment để thấy lỗi.
  */
  // A a{ "Object" };
  A b;
  /*
    Lỗi
      'std::string A::name_' is private within this context.

    Ở đây giải thích quá rõ nên là không cần phải giải thích nữa.
    Và vì không thể access được vào bất kì member nào trong A nên
    nên sẽ không sửa được dữ liệu của A từ bên ngoài.

    Uncomment để thấy lỗi.
  */
  // b.name_;
  // Khởi tạo instance cho B
  B c = B("b_01", "Nguyen", "Anh Tuan", 21);

  c.Print();
  /*
    Lỗi
      'std::string B::GetFullname()' is protected within this context.

    Uncomment để thấy lỗi
  */
  // c.GetFullname();
  /*
    Lỗi
      'short int B::age_' is protected within this context.
      'std::string B::_id_' is private within this context.

    Uncomment
  */
  /*
  c.age_ = 22;
  c._id_ = "b_02";
  */

  // Khởi tạo một instance cho C
  /*
    Lỗi
      'constexpr C::C()' is private within this context. x2
      no matching function for call to 'C::C(int)'

    Uncomment để thấy lỗi
  */
  /*
  C instance_c_01;
  C instance_c_02 = C();
  C instance_c_03(1912);
  */
  /*
    Uncomment để thấy lỗi
  */
  /*
    C instance_c_04();
    instance_c_04.value_ = 9999;
  */
  // Hợp lệ
  // (*)
  C instance_c_05{};

  instance_c_05.value_ = 9999;
  cout << "Type of instance_c_05: " << typeid(instance_c_05).name() << endl;
  cout << "Value of instance_c_05.value_: " << instance_c_05.value_ << endl;

  cout << "\n";

  /*
    Lỗi
      'constexpr D::D()' is private within this context.

    Uncomment để thấy lỗi
  */
  // (*)
  // D instance_d_01{};
  D instance_d_02(1912);

  cout << "Type of instance_d_02: " << typeid(instance_d_02).name() << endl;
  cout << "Value of instance_d_02.value_: " << instance_d_02.value_ << endl;

  return 0;
};

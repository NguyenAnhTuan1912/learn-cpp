/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Class Template.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

/*
  Class Template này sẽ có một số operator overload
  được khai báo khác nhau.
*/
template<typename T>
class Number {
private:
  T _value_;

public:
  Number(T v): _value_(v) {};

  // Note 1
  T GetValue() const { return _value_; };

  // Operator Overloads
  // Cách 1
  template<typename V>
  T operator+(V& v) {
    return _value_ + v;
  };

  template<typename V>
  T operator-(V& v) {
    return _value_ - v;
  };

  // Khai báo các operator để dùng cho cách 2
  template<typename V> T operator*(V& v);
  template<typename V> T operator/(V& v);

  // Khai báo các operators khác
  // Note 1, 2
  template<typename F_T>
  friend ostream& operator<<(ostream& out, const Number<F_T>& n);
  /*
    Uncomment đoạn code dưới và comment đoạn trên để thấy lỗi
  */
  /*
    template<typename F_T>
    friend ostream& operator<<(ostream& out, const Number<F_T>& n) {
      out << n.GetValue();
      return out;
    };
  */
};

// Cách 2
// Note 3
template<typename T> // template cho class
template<typename V> // template cho function
T Number<T>::operator*(V& v) {
  return _value_ * v;
};

template<typename T> template<typename V>
T Number<T>::operator/(V& v) {
  return _value_ / v;
};

// Các Operator Overloads bên ngoài.
template<typename T, typename V>
T operator+(V& v, Number<T>& n) {
  return v + n.GetValue();
};

template<typename T, typename V>
T operator-(V& v, Number<T>& n) {
  return v - n.GetValue();
};

template<typename T, typename V>
T operator*(V& v, Number<T>& n) {
  return v * n.GetValue();
};

template<typename T, typename V>
T operator/(V& v, Number<T>& n) {
  return v / n.GetValue();
};

template<typename T>
ostream& operator<<(ostream& out, const Number<T>& n) {
  out << n.GetValue();
  return out;
};

int main() {
  // Khởi tạo 2 instance cho numbers
  Number<int> i_n = 10;
  Number<float> f_n = 5.2;

  int i_01 = 30;
  float f_01 = 2.4;

  cout << "Value of i_n: " << i_n << endl;
  cout << "Value of f_n: " << f_n << endl;
  cout << "Value of i_01: " << i_01 << endl;
  cout << "Value of f_01: " << f_01 << endl;
  cout << endl;

  cout << "Addtition\n";
  cout << "Value of i_n + i_01: " << i_n + i_01 << endl;
  cout << "Value of i_01 + i_n: " << i_01 + i_n << endl;
  cout << "Value of i_n + f_01: " << i_n + f_01 << endl;
  cout << "Value of f_n + f_01: " << f_n + f_01 << endl;
  cout << "Value of f_01 + f_n: " << f_01 + f_n << endl;
  cout << "Value of f_01 + i_n: " << f_01 + i_n << endl;
  cout << endl;

  cout << "Substraction\n";
  cout << "Value of i_n - i_01: " << i_n - i_01 << endl;
  cout << "Value of i_01 - i_n: " << i_01 - i_n << endl;
  cout << "Value of f_n - f_01: " << f_n - f_01 << endl;
  cout << "Value of f_01 - f_n: " << f_01 - f_n << endl;
  cout << "Value of i_n - f_01: " << i_n - f_01 << endl;
  cout << "Value of f_01 - i_n: " << f_01 - i_n << endl;
  cout << endl;

  cout << "Multiplication\n";
  cout << "Value of i_n * i_01: " << i_n * i_01 << endl;
  cout << "Value of i_01 * i_n: " << i_01 * i_n << endl;
  cout << "Value of f_n * f_01: " << f_n * f_01 << endl;
  cout << "Value of f_01 * f_n: " << f_01 * f_n << endl;
  cout << "Value of i_n * f_01: " << i_n * f_01 << endl;
  cout << "Value of f_01 * i_n: " << f_01 * i_n << endl;
  cout << endl;

  cout << "Division\n";
  cout << "Value of i_n / i_01: " << i_n / i_01 << endl;
  cout << "Value of i_01 / i_n: " << i_01 / i_n << endl;
  cout << "Value of f_n / f_01: " << f_n / f_01 << endl;
  cout << "Value of f_01 / f_n: " << f_01 / f_n << endl;
  cout << "Value of i_n / f_01: " << i_n / f_01 << endl;
  cout << "Value of f_01 / i_n: " << f_01 / i_n << endl;
  cout << endl;

  return 0;
};

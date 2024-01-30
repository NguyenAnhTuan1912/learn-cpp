/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Class Template.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Khai báo type cho lambda
/*
  Vì typedef không thể dùng với template, cho nên mình phải dùng
  template + using. Xem thêm https://cplusplus.com/forum/general/87524/
*/
template<typename T>
using ListForeachCallBack = function<void(T&, int)>;

class Person {
private:
  string _name_;
  int _age_;

public:
  Person(string n, int a): _name_(n), _age_(a) {};

  void Print() {
    cout
      << "Name: " << _name_ << ", "
      << "Age: " << _age_ << ".\n";
  };
};

class Coordinate {
private:
  float _x_;
  float _y_;

public:
  Coordinate(float x, float y): _x_(x), _y_(y) {};

  void Print() {
    cout << "(" << _x_ << ", " << _y_ << ").\n";
  }
};

template<typename T>
class List {
private:
  std::vector<T> _data_;

public:
  int GetSize() { return _data_.size(); };
  void AddItem(T item) { _data_.push_back(item); };
  void ReplaceItem(T item, int index) {
    if(index < 0) index = 0;
    else if(index >= _data_.size()) index = _data_.size() - 1;

    _data_[index] = item;
  };
  void Foreach(ListForeachCallBack<T> Cb) {
    int N = _data_.size();
    for(int i = 0; i < N; i++) {
      Cb(_data_[i], i);
    };
  };
};

int main() {
  // Khởi tạo một số instance.
  List<Person> people;
  List<Coordinate> coors;

  // Định nghĩa các lamdba
  ListForeachCallBack<Person> PrintP = [](Person& p, int index) {
    cout << index + 1 << ". "; p.Print();
  };
  ListForeachCallBack<Coordinate> PrintC = [](Coordinate& coor, int index) {
    cout << index + 1 << ". "; coor.Print();
  };

  // Thêm một số thông tin
  people.AddItem({"Nguyen Anh Tuan", 21});
  people.AddItem({"Carl Johnson", 53});
  people.AddItem({"Will Smiths", 30});
  people.AddItem({"Jason Hill", 100});
  people.AddItem({"Marshall Bee", 23});

  coors.AddItem({12.4, -2.2});
  coors.AddItem({3, 4});
  coors.AddItem({1.2, 3.4});
  coors.AddItem({-24, -24});
  coors.AddItem({3.4, 1.2});
  coors.AddItem({5, 5});
  coors.AddItem({0, 0});
  coors.AddItem({4, -4});
  coors.AddItem({-31.4, 55.2});
  coors.AddItem({5.1, 4.5});

  // In các thông tin
  cout << "Print people\n";
  people.Foreach(PrintP);
  cout << endl;

  cout << "Print coors\n";
  coors.Foreach(PrintC);
  cout << endl;

  // Replace một số dữ liệu
  people.ReplaceItem({"Tuna Nguyen", 21}, 0);
  people.ReplaceItem({"Amelia Tran", 23}, 100);

  coors.ReplaceItem({1, 2}, -10);
  coors.ReplaceItem({20, 30}, 4);

  // In lại các thông tin
  cout << "Re-print people\n";
  people.Foreach(PrintP);
  cout << endl;

  cout << "Re-print coors\n";
  coors.Foreach(PrintC);
  cout << endl;

  return 0;
};

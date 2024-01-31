/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về Template Specialization.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

template<typename K, typename V>
class Dictionary {
private:
  K* _keys_;
  V* _values_;
  int _size_;
  int _max_size_;

public:
  Dictionary(int initial_size): _size_(0), _max_size_(initial_size) {
    _keys_ = new K[_max_size_];
    _values_ = new V[_max_size_];
  };

  void AddItem(K key, V value) {
    if(_size_ + 1 >= _max_size_) {
      _max_size_ += 5;

      K* tmp_keys = new K[_max_size_];
      V* tmp_values = new V[_max_size_];

      // Gán lại cho temp
      for(int i = 0; i < _size_; i++) {
        tmp_keys[i] = _keys_[i];
        tmp_values[i] = _values_[i];
      };
      tmp_keys[_size_] = key;
      tmp_values[_size_] = value;

      // Delete keys và values cũ
      delete[] _keys_;
      delete[] _values_;

      // Cập nhật mới
      _keys_ = tmp_keys;
      _values_ = tmp_values;

      delete[] tmp_keys;
      delete[] tmp_values;
    } else {
      _keys_[_size_] = key;
      _values_[_size_] = value;
    };
    _size_++;
  };

  int GetSize() {
    return _size_;
  };

  void Print() {
    for(int i = 0; i < _size_; i++) {
      cout << "(" << _keys_[i] << ", " << _values_[i] << ")\n";
    };
  };
};

// Specialize Dictionary có key là số tăng dần.
// Cú pháp như bên dưới
template<typename V>
class Dictionary<int, V> {
private:
  int* _keys_;
  V* _values_;
  int _size_;
  int _max_size_;

public:
  Dictionary(int initial_size): _size_(0), _max_size_(initial_size) {
    _keys_ = new int[_max_size_];
    _values_ = new V[_max_size_];
  };

  // AddItem này được xem như là overload của AddItem trên.
  void AddItem(V value) {
    if(_size_ + 1 >= _max_size_) {
      _max_size_ += 5;

      int* tmp_keys = new int[_max_size_];
      V* tmp_values = new V[_max_size_];

      // Gán lại cho temp
      for(int i = 0; i < _size_; i++) {
        tmp_keys[i] = _keys_[i];
        tmp_values[i] = _values_[i];
      };
      tmp_keys[_size_] = _size_ + 1;
      tmp_values[_size_] = value;

      // Delete keys và values cũ
      delete[] _keys_;
      delete[] _values_;

      // Cập nhật mới
      _keys_ = tmp_keys;
      _values_ = tmp_values;
    } else {
      _keys_[_size_] = _size_ + 1;
      _values_[_size_] = value;
    };
    _size_++;
  };

  int GetSize() {
    return _size_;
  };

  void Print() {
    for(int i = 0; i < _size_; i++) {
      cout << "(" << _keys_[i] << ", " << _values_[i] << ")\n";
    };
  };
};

int main() {
  // Khởi tạo
  Dictionary<const char*, const char*> dist_01(1);
  // Lúc này thì trình biên dịch sẽ đọc template bên dưới
  Dictionary<int, const char*> dist_02(5);

  dist_01.AddItem("One", "Nguyen Anh Tuan");
  dist_01.AddItem("Two", "Tuan Nguyen");
  dist_01.AddItem("Three", "Tuna Nguyen");

  /*
    Có một số IDE hiểu đây là overload, nhưng thực chất
    là không phải!!!
  */
  dist_02.AddItem("H");
  dist_02.AddItem("E");
  dist_02.AddItem("L");
  dist_02.AddItem("L");
  dist_02.AddItem("O");

  cout << "Print dist_01\n";
  dist_01.Print();
  cout << endl;

  cout << "Print dist_02\n";
  dist_02.Print();
  cout << endl;


  cout << "Size of dist_01: " << dist_01.GetSize() << endl;
  cout << "Size of dist_02: " << dist_02.GetSize() << endl;

  return 0;
};

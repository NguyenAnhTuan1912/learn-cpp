#ifndef DATALIST_H_INCLUDED
#define DATALIST_H_INCLUDED

#include <map>
#include <exception>
#include <iterator>

// Add types
#include "../../types/types.h"

namespace CoffeeShop {

template<typename K, class V>
class DataList {
private:
  std::map<K, V> _data_;
  int _numof_items_per_page_;
  size_t _current_index_ = 0;

public:
  DataList() = default;
  DataList(int numof_ipp): _numof_items_per_page_{numof_ipp}, _current_index_{0} {};

  // Getters
  virtual std::map<K, V>* GetData() final {
    return &this->_data_;
  };

  // Setters
  virtual void AddItem(K key, V value) final {
    this->_data_[key] = value;
  };

  // Other methods
  virtual bool DeleteItem(int N) final {
    if(N < 0 || N > (int)this->_data_.size() - 1)
      throw std::runtime_error("Index of deleting item is out of range!!!");

    typename std::map<K, V>::iterator it = this->_data_.begin();
    int index;

    while(index < N) {
      it++;
      index++;
    };

    this->_data_.erase(it);

    return true;
  };

  virtual void Next() final {
    size_t tmp = this->_current_index_ + this->_numof_items_per_page_;

    if(tmp >= this->_data_.size()) tmp = this->_data_.size() - 1;

    this->_current_index_ = tmp;
  };

  virtual void Previous() final {
    size_t tmp = this->_current_index_ - this->_numof_items_per_page_;

    if(tmp < 0) tmp = 0;

    this->_current_index_ = tmp;
  };

  virtual void Print(Types::DataListPrintCallBack<V>& Cb) final {
    typename std::map<K, V>::iterator it = this->_data_.begin();
    size_t index = 0;

    std::cout << "Check: " << this->_current_index_ << std::endl;

    while(index < this->_current_index_) {
      it++;
      index++;
    };

    std::cout << it->first << std::endl;

    for(; it != this->_data_.end(); it++) Cb(it->second, ++index);
  };
};

};

#endif // DATALIST_H_INCLUDED

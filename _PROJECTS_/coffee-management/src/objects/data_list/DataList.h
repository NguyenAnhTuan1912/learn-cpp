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
  int _numof_items_per_page_ = 5;
  size_t _current_index_ = 0;

  /** \brief Use this method to get item at N
   *
   * \param N A "index" of item of map
   * \return An iterator of map
   *
   * When this method is executed, a iterator of map will be iterate
   * N time to get exact item.
   */

  typename std::map<K, V>::iterator _GetIteratorOfMapAt_(int N) {
    if(N < 0 || N > (int)this->_data_.size() - 1)
      throw std::runtime_error("Index of item is out of range!!!");

    typename std::map<K, V>::iterator it = this->_data_.begin();
    int index = 0;

    if(N != 0)
      while(index < N) {
        it++;
        index++;
      };

    return it;
  };

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
    typename std::map<K, V>::iterator it = this->_GetIteratorOfMapAt_(N);

    this->_data_.erase(it);

    return true;
  };

  virtual V* GetItem(int N) final {
    if(N < 0 || N > (int)this->_data_.size())
      throw std::runtime_error("Index of deleting item is out of range!!!");

    typename std::map<K, V>::iterator it = this->_data_.begin();
    int index = 0;

    while(index < N) {
      it++;
      index++;
    };

    return &it->second;
  };

  virtual int GetCurrentPage() {
    return (this->_current_index_ / this->_numof_items_per_page_) + 1;
  };

  virtual void Next() final {
    size_t tmp = this->_current_index_ + this->_numof_items_per_page_;

    if(tmp >= this->_data_.size()) return;

    this->_current_index_ = tmp;
  };

  virtual void Previous() final {
    size_t tmp = this->_current_index_ - this->_numof_items_per_page_;

    if((long long)tmp < 0) tmp = 0;

    this->_current_index_ = tmp;
  };

  virtual void Print(Types::DataListPrintCallBack<V>& Cb) final {
    typename std::map<K, V>::iterator it = this->_GetIteratorOfMapAt_(this->_current_index_);
    int index = 0;
    for(; it != this->_data_.end() && index < (this->_numof_items_per_page_); it++) Cb(it->second, ++index);
  };
};

};

#endif // DATALIST_H_INCLUDED

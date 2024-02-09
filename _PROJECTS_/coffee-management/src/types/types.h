#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <functional>

namespace CoffeeShop {
namespace Types {

template<class V>
using DataListPrintCallBack = std::function<void(V&, int)>;

};
};

#endif // TYPES_H_INCLUDED

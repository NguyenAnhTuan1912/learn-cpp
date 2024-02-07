#include <cstdlib>

#include "number_utils.h"

namespace CoffeeShop {
namespace Utils {
namespace Number {

int GetRandom(int mx) {
  return std::rand() % mx;
};

int GetRandom(int mn, int mx) {
  return (std::rand() % (mx - mn + 1)) + mn;
};

};
};
};

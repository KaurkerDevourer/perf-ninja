#include "solution.hpp"
#include <limits>
#include <random>

std::size_t initToBucket(std::size_t v) {
                                //   size of a bucket
    if      (v < 13)  return 0; //   13
    else if (v < 29)  return 1; //   16
    else if (v < 41)  return 2; //   12
    else if (v < 53)  return 3; //   12
    else if (v < 71)  return 4; //   18
    else if (v < 83)  return 5; //   12
    else if (v < 100) return 6; //   17
    return DEFAULT_BUCKET;
}

void init(std::vector<int> &values) {
  std::random_device r;
  std::default_random_engine generator(r());
  // generate random integer in the closed interval [0,150]
  // the chance of selecting the default bucket is ~33%
  std::uniform_int_distribution<int> distribution(0, 150);
  for (int i = 0; i < NUM_VALUES; i++) {
    values.push_back(distribution(generator));
  }
}

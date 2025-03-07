
#include "solution.h"

// Select items which have S.first in range [lower..upper]
#ifdef SOLUTION
  std::size_t select(std::array<S, N> &output, const std::array<S, N> &input,
                    const std::uint32_t lower, const std::uint32_t upper) {
    std::size_t count = 0;
    for (const auto item : input) {
      output[count] = item;
      count += (lower <= item.first) && (item.first <= upper);
    }
    return count;
  }
#else 
  std::size_t select(std::array<S, N> &output, const std::array<S, N> &input,
                    const std::uint32_t lower, const std::uint32_t upper) {
    std::size_t count = 0;
    for (const auto item : input) {
      if ((lower <= item.first) && (item.first <= upper)) {
        output[count++] = item;
      }
    }
    return count;
  }
#endif

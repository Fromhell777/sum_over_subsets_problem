#include "timer.hpp"
#include "prettyprint.hpp"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::uint32_t> find_sum_over_subsets(std::vector<std::uint32_t> const & data,
                                                 std::uint32_t const nbBits) {
  std::vector<std::uint32_t> sum_over_subsets(data.size());

  for (std::uint32_t i = 0; i < sum_over_subsets.size(); i++) {
   sum_over_subsets[i] = data[i];
  }
  for (std::uint32_t i = 0; i < nbBits; i++) {
    for(std::uint32_t mask = 0; mask < sum_over_subsets.size(); mask++) {
      if (mask & (1 << i)) {
        sum_over_subsets[mask] += sum_over_subsets[mask ^ (1 << i)];
      }
    }
  }

  return sum_over_subsets;
}

int main() {
  {
    timer Timer;

    std::uint32_t testCases;
    std::cin >> testCases;

    for (std::uint32_t t = 0; t < testCases; t++) {
      std::uint32_t nbBits;
      std::cin >> nbBits;

      std::vector<std::uint32_t> data(1 << nbBits);
      for (auto & element : data) {
        std::cin >> element;
      }

      std::cout << "Case #" << t + 1 << ":";
      auto result = find_sum_over_subsets(data, nbBits);

      for (auto const element : result) {
        std::cout << ' ' << element;
      }
      std::cout << '\n';
    }
  }
}

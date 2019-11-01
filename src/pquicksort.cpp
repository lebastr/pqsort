#include <vector>
#include <tuple>
#include <boost/lockfree/queue.hpp>
#include <thread>

#include "partition.h"

void pquicksort(std::vector<int> &array, int n_threads) {
  boost::lockfree::queue<std::tuple<i_iterator, i_iterator>> queue{128};

  queue.push(std::make_tuple(array.begin(), array.end()));

  std::vector<std::thread> consumers;
  for(int i = 0; i < n_threads; ++i) {
    std::thread t{consume};
    consumers.push_back(t);

  }
}

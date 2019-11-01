#include <vector>
#include <tuple>
#include <thread>

#include "partition.h"
#include "pquicksort.h"

void rec_pqsort(i_iterator begin, i_iterator end,
		int n_threads) {
  
  i_iterator pivot_idx = begin;  // TODO: Make a random pivot_idx
  i_iterator begin_pb, end_pb;
  std::thread thr;

  
  std::tie (begin_pb, end_pb) = create_partition(pivot_idx, begin, end);
  
  if (begin < begin_pb) {
    if (n_threads > 1) {
      thr = std::thread(rec_pqsort, begin, begin_pb, n_threads / 2);
    } else {
      rec_pqsort(begin, begin_pb, n_threads / 2);
    }
  }

  if (end_pb < end) {
    rec_pqsort(end_pb, end, n_threads / 2);
  }

  if (thr.joinable()) {
    thr.join();
  }
}

void pquicksort(std::vector<int> &array, int n_threads) {
  rec_pqsort(array.begin(), array.end(), n_threads);
}

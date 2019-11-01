#include <vector>
#include <tuple>
#include "partition.h"
#include "quicksort.h"

void recursive_qsort(std::vector<int> &array, i_iterator begin, i_iterator end) {
  i_iterator begin_pivots_basket;
  i_iterator end_pivots_basket;
  i_iterator pivot_idx;

  pivot_idx = begin;  // TODO: Make a random pivot_idx
  std::tie (begin_pivots_basket, end_pivots_basket) = create_partition(array, pivot_idx, begin, end);

  if (begin < begin_pivots_basket) {
    recursive_qsort(array, begin, begin_pivots_basket);
  }

  if (end_pivots_basket < end) {
    recursive_qsort(array, end_pivots_basket, end);
  }
}

void quicksort(std::vector<int> &array) {
  recursive_qsort(array, array.begin(), array.end());
}

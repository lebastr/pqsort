#include <vector>
#include <tuple>
#include "partition.h"

std::tuple<i_iterator, i_iterator> create_partition(std::vector<int> &array,
						    i_iterator pivot_idx,
						    i_iterator begin,
						    i_iterator end) {

  i_iterator pivot_start, pivot_end ; // point to basket with elements equals pivot
  i_iterator idx; // point to basket with elements greater than pivot
  int pivot = *pivot_idx;

  pivot_start = begin;
  pivot_end = begin;
  idx = end;

  // Invariant.
  // There are four basket:
  // 1) From begin to pivot_start with elements smaller than pivot;
  // 2) From pivot_start to pivot_end with elements equal pivot;
  // 3) From pivot_end to idx with elements with unknown status;
  // 4) From idx to end with elements greater than pivot.

  // Goal: The third basket should disappear.
  
  while (idx > pivot_end) {
    int value = *pivot_end;

    if (value == pivot) {
      pivot_end++;
    } else if (value < pivot) {
      std::swap(pivot_end, pivot_start);
      pivot_start++;
      pivot_end++;
    } else {
      idx--;
      std::swap(pivot_end, idx);
    }
  }
  
  return std::make_tuple(pivot_start, pivot_end);
}

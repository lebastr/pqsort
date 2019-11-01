#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include <tuple>

using i_iterator = std::vector<int>::iterator;

std::tuple<i_iterator, i_iterator> create_partition(std::vector<int> &array,
						    i_iterator pivot_idx,
						    i_iterator begin,
						    i_iterator end);

#endif

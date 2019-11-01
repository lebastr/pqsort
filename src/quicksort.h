#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "partition.h"

void recursive_qsort(std::vector<int> &array,
		     i_iterator begin,
		     i_iterator end);

void quicksort(std::vector<int> &array);

#endif

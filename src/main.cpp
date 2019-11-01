// First argument is a sort method
// Second argument is a array size

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "quicksort.h"
#include "pquicksort.h"

int main (int argc, char* argv[]) {
  std::string sort_method;
  
  int M = std::atoi(argv[2]);
  int NSize = std::atoi(argv[3]);

  sort_method = argv[1];

  std::vector<int> array;
  std::cout << "fill array....\n";
  for(size_t i = 0; i < NSize; ++i) {
    array.push_back(std::rand() % M);
  }
  std::cout << "Done.\n";

  std::vector<int> well_sorted = array;
  std::vector<int> sorted = array;

  std::cout << "run std::sort...\n";
  auto t1 = std::chrono::high_resolution_clock::now();
  std::sort(well_sorted.begin(), well_sorted.end());
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Done.\n";

  std::cout << "Run test....\n";
  auto t3 = std::chrono::high_resolution_clock::now();
  if (sort_method == "quicksort") {
    quicksort(sorted);
  } else if (sort_method == "pquicksort") {
    pquicksort(sorted, 2);
  } else {
    std::cout << "Unknown sort method";
    return 0;
  }
  auto t4 = std::chrono::high_resolution_clock::now();
  std::cout << "Done.\n";

  
  if (std::equal(well_sorted.begin(), well_sorted.end(), sorted.begin())) {
    std::cout << "Ok" << "\n";
  } else {
    std::cout << "No" << "\n";
  }

  auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  auto d2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
  
  std::cout << "d1: " << d1 << " d2: " << d2 << "\n";
  
}



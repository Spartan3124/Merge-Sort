#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <vector>
std::vector<int> & mergeSort(std::vector<int> & x, int start, int end,
                             std::vector<int> & temp, int & i);

std::vector<int> & mergeHelper(std::vector<int> & x, int start, int end,
                               std::vector<int> & temp);

#endif

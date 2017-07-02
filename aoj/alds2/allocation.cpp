///
// File:  allocation.cpp
// Author: ymiyamoto
//
// Created on Sun Jul  2 23:16:36 2017
//

#include <cstdint>
#include <vector>

using namespace std;

size_t allocation_load_capcity(vector<uint32_t> baggages, uint32_t capacity, uint32_t tracks)
{
  uint32_t num = 0;

  for (uint32_t i = 0; i < tracks; i++) {
    int32_t track_capacity = capacity;
    do {
      track_capacity -= baggages[num];
      num++;
      if (baggages.size() <= num) return num;
    } while (track_capacity >= 0);
    num--;
  }

  return num;
}

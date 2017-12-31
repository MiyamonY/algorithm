///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 31 17:36:23 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct train_t {
  uint32_t time;
  uint32_t start;
  uint32_t interval;
};

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<train_t> trains;
  for (uint32_t i = 0; i < N; i++) {
    uint32_t C, S, F;
    cin >> C >> S >> F;
    trains.push_back(train_t({C, S, F}));
  }

  for (uint32_t i = 0; i < trains.size(); i++) {
    uint32_t clock = 0;
    for (uint32_t j = i; j < trains.size() - 1; j++) {
      uint32_t t = trains[j].time;
      uint32_t s = trains[j].start;
      uint32_t i = trains[j].interval;
      uint32_t n = 0;
      while (s + n * i < clock) {
        n++;
      }
      clock = (s + n * i) + t;
    }
    cout << clock << endl;
  }

  return 0;
}

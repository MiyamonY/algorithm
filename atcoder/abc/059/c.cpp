///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 16:19:00 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static uint64_t calc_count(vector<long long> &vec, int64_t sign)
{
  unsigned long long count = 0;
  long long total = 0;

  for (uint64_t i = 0; i < vec.size(); i++) {
    total += vec[i];

    if ((total == 0) || ((sign * total) < 0)) {
      count += abs(sign - total);
      total = sign;
    }
    sign *= -1;
  }

  return count;
}

int32_t main()
{
  uint64_t N;
  cin >> N;

  vector<long long> vec;

  for (uint64_t i = 0; i < N; i++) {
    long long val;
    cin >> val;
    vec.push_back(val);
  }

  cout << min(calc_count(vec, 1), calc_count(vec, -1)) << endl;
  return 0;
}

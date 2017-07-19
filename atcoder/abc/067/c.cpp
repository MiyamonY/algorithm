///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 19 19:49:22 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t num;
  cin >> num;

  vector<long long> vec;
  long long total = 0;

  for (uint32_t i = 0; i < num; i++) {
    long long val;
    cin >> val;
    total += val;
    vec.push_back(val);
  }

  long long subtotal = vec[0];
  long long min_val = abs(total - 2 * subtotal);
  for (uint32_t i = 1; i < vec.size() - 1; i++) {
    subtotal += vec[i];
    min_val = min(abs(total - 2 * subtotal), min_val);
  }

  cout << min_val << endl;
  return 0;
}

///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Jul 27 22:57:52 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define ARRAY_SIZE 100001
static priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> before;
static priority_queue<uint64_t, vector<uint64_t>, less<uint64_t>> after;
static int64_t maximums[ARRAY_SIZE];
static int64_t minimums[ARRAY_SIZE];

int32_t main()
{
  uint32_t num;
  cin >> num;

  static vector<uint64_t> array(3 * num);
  static vector<uint64_t> rev_array(3 * num);

  for (uint32_t i = 0; i < 3 * num; i++) {
    uint64_t v;
    cin >> v;
    array[i] = v;
    rev_array[3 * num - 1 - i] = v;
  }

  int64_t maximum = 0, minimum = 0;
  for (uint32_t k = 0; k < num; k++) {
    before.push(array[k]);
    maximum += array[k];

    after.push(rev_array[k]);
    minimum += rev_array[k];
  }
  maximums[0] = maximum;
  minimums[0] = minimum;

  for (uint64_t k = 0; k < num; k++) {
    maximum += array[num + k];
    before.push(array[num + k]);
    maximum -= before.top();
    before.pop();

    maximums[k + 1] = maximum;

    minimum += rev_array[num + k];
    after.push(rev_array[num + k]);
    minimum -= after.top();
    after.pop();

    minimums[k + 1] = minimum;
  }

  int64_t val = INT64_MIN;
  for (uint32_t i = 0; i <= num; i++) {
    val = max(val, maximums[i] - minimums[num - i]);
  }

  cout << val << endl;

  return 0;
}

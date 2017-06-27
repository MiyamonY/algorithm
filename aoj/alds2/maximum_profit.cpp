#include <cstdint>
#include <vector>

#include "problems.hpp"

using namespace std;

int maximum_profit(vector<int32_t> &vec)
{
  int32_t max_val = INT32_MIN;
  int32_t min_val = INT32_MAX;
  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    max_val = max(max_val, *iter - min_val);
    min_val = min(min_val, *iter);
  }

  return max_val;
}

#if !defined(TEST)
#include <iostream>
int32_t main(void)
{
  int32_t num;
  cin >> num;

  vector<int32_t> vec;
  for (uint32_t i = 0; i < num; i++) {
    int32_t d;
    cin >> d;
    vec.push_back(d);
  }

  int32_t val = maximum_profit(vec);

  cout << val << endl;

  return 0;
}
#endif

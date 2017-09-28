#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

static vector<int64_t> array;

int32_t main()
{
  int64_t N, x;
  cin >> N >> x;

  for (uint32_t i = 0; i < N; i++) {
    uint64_t a;
    cin >> a;
    array.push_back(a);
  }

  uint64_t count = 0;
  for (uint32_t i = 0; i < array.size() - 1; i++) {
    int64_t sum = array[i] + array[i + 1];
    if (sum > x) {
      int64_t diff = sum - x;
      array[i + 1] -= min(array[i + 1], diff);
      count += diff;
    }
  }

  cout << count << endl;
  return 0;
}

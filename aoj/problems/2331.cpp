#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<int64_t> nums(100002, 0);

int32_t main() {
  uint32_t N;
  cin >> N;

  for (uint32_t i = 0; i < N; i++) {
    int64_t a, b;
    cin >> a >> b;
    nums[a]++;
    nums[b + 1]--;
  }

  uint32_t max_val = 0;
  for (uint32_t i = 0; i < nums.size() - 1; i++) {
    nums[i + 1] += nums[i];
    if (i + 1 <= nums[i + 1] + 1) {
      max_val = max(max_val, i + 1);
    }
  }

  cout << max_val - 1 << endl;

  return 0;
}
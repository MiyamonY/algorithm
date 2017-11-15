#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t find_len(vector<uint32_t> &nums, uint32_t start, uint32_t len) {
  int32_t end = -1;
  int32_t index = start;
  int32_t remain = len;
  while (remain > 0 && index < nums.size()) {
    remain -= nums[index];
    index++;
  }

  if (remain == 0) {
    end = index;
  }

  return end;
}
int32_t main() {
  while (true) {
    uint32_t n;
    cin >> n;

    if (n == 0) break;

    vector<uint32_t> nums;
    for (uint32_t _ = 0; _ < n; _++) {
      string str;
      cin >> str;
      nums.push_back(str.size());
    }

    for (uint32_t i = 0; i < nums.size(); i++) {
      int32_t index = find_len(nums, i, 5);
      if (index == -1) continue;
      index = find_len(nums, index, 7);
      if (index == -1) continue;
      index = find_len(nums, index, 5);
      if (index == -1) continue;
      index = find_len(nums, index, 7);
      if (index == -1) continue;
      index = find_len(nums, index, 7);
      if (index == -1) continue;
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}
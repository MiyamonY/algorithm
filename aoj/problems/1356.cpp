#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main() {
  uint32_t n;
  cin >> n;

  vector<char> arr;
  for (uint32_t i = 0; i < n; i++) {
    char c;
    cin >> c;
    arr.push_back(c);
  }

  vector<int32_t> nums;
  for (uint32_t i = 0; i < arr.size(); i++) {
    for (uint32_t j = i + 1; j <= arr.size() && j <= i + 4; j++) {
      string num = "";
      for (uint32_t k = i; k < j; k++) {
        string s{arr[k]};
        num += s;
      }
      nums.push_back(stoi(num));
    }
  }

  sort(nums.begin(), nums.end());

  uint32_t index = 0;
  for (int32_t i = 0; i < 10000; i++) {
    bool found = false;
    while (nums[index] == i) {
      index++;
      found = true;
    }

    if (!found) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
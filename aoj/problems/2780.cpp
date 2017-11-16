#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid(uint64_t val) {
  bool valid = true;
  string num = to_string(val);
  for (uint32_t i = 0; i < num.size() - 1; i++) {
    if (num[i + 1] - num[i] != 1) {
      valid = false;
    }
  }
  return valid;
}

int32_t main() {
  uint32_t N;
  cin >> N;

  vector<int64_t> arr;

  for (uint32_t i = 0; i < N; i++) {
    int64_t val;
    cin >> val;
    arr.push_back(val);
  }

  int64_t max_val = -1;
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = i + 1; j < N; j++) {
      if (is_valid(arr[i] * arr[j])) {
        max_val = max(max_val, arr[i] * arr[j]);
      }
    }
  }

  cout << max_val << endl;

  return 0;
}
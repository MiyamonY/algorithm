#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main() {
  while (true) {
    uint32_t n;
    cin >> n;

    if (n == 0) break;

    array<char, 27> arr;
    for (uint32_t i = 0; i < arr.size(); i++) {
      arr[i] = 0;
    }

    uint32_t top = 26;
    uint32_t second = 26;
    int32_t decided = -1;
    for (int32_t i = 0; i < n; i++) {
      char c;
      cin >> c;
      uint32_t index = c - 'A';
      arr[index]++;
      if (arr[top] < arr[index]) {
        if (top != index) {
          second = top;
        }
        top = index;
      } else if (top != index && arr[second] < arr[index]) {
        second = index;
      }

      if (decided < 0 && arr[second] + n - i - 1 < arr[top]) {
        decided = i;
      }
    }

    if (decided == -1) {
      cout << "TIE" << endl;
    } else {
      cout << (char)(top + 'A') << " " << decided + 1 << endl;
    }
  }
  return 0;
}
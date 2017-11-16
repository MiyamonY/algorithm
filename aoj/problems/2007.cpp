#include <cstdint>
#include <iostream>

using namespace std;

int32_t main() {
  bool start = true;
  while (true) {
    uint32_t amount;
    cin >> amount;
    if (amount == 0) break;

    if (!start) {
      cout << endl;
    }
    start = false;

    uint32_t c10, c50, c100, c500;
    cin >> c10 >> c50 >> c100 >> c500;

    uint32_t total = c10 + c50 + c100 + c500;
    uint32_t min_remain = UINT32_MAX;
    uint32_t min_c10 = 0;
    uint32_t min_c50 = 0;
    uint32_t min_c100 = 0;
    uint32_t min_c500 = 0;
    for (uint32_t l = 0; l <= c500; l++) {
      for (uint32_t k = 0; k <= c100; k++) {
        for (uint32_t j = 0; j <= c50; j++) {
          for (uint32_t i = 0; i <= c10; i++) {
            uint32_t payment = 10 * i + 50 * j + 100 * k + 500 * l;
            if (amount <= payment) {
              uint32_t change = payment - amount;
              uint32_t r500 = change / 500;
              change %= 500;
              uint32_t r100 = change / 100;
              change %= 100;
              uint32_t r50 = change / 50;
              change %= 50;
              uint32_t r10 = change / 10;
              uint32_t remain = c10 - i + r10 + c50 - j + r50 + c100 - k +
                                r100 + c500 - l + r500;
              if (remain < min_remain) {
                min_remain = remain;
                min_c10 = i;
                min_c50 = j;
                min_c100 = k;
                min_c500 = l;
              }
            }
          }
        }
      }
    }
    if (min_c10) {
      cout << 10 << " " << min_c10 << endl;
    }
    if (min_c50) {
      cout << 50 << " " << min_c50 << endl;
    }
    if (min_c100) {
      cout << 100 << " " << min_c100 << endl;
    }
    if (min_c500) {
      cout << 500 << " " << min_c500 << endl;
    }
  }

  return 0;
}
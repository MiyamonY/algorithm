#include <cstdint>
#include <iostream>

using namespace std;

uint32_t comb(uint32_t n, uint32_t s, uint32_t i, uint32_t k, uint32_t sum) {
  if (k == 0 && s == sum) {
    return 1;
  } else if (i > n || k == 0) {
    return 0;
  } else {
    return comb(n, s, i + 1, k, sum) + comb(n, s, i + 1, k - 1, sum + i);
  }
}

int32_t main() {
  while (true) {
    uint32_t n, k, s;
    cin >> n >> k >> s;
    if (n == 0) break;
    cout << comb(n, s, 1, k, 0) << endl;
  }

  return 0;
}
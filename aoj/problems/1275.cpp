#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main() {
  while (true) {
    uint32_t n, k, m;
    cin >> n >> k >> m;

    if (n == 0 && k == 0 && m == 0) break;

    uint32_t size = n;
    vector<uint32_t> ring(n);
    for (uint32_t i = 0; i < ring.size(); i++) {
      ring[i] = i + 1;
    }

    uint32_t index = m - 1;
    ring.erase(ring.begin() + index);
    size--;
    while (1 < size) {
      index += k - 1;
      index %= size;
      ring.erase(ring.begin() + index);
      size--;
    }
    cout << ring[0] << endl;
  }

  return 0;
}
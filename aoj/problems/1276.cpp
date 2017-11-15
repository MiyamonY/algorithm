#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

bool is_prime(uint32_t n) {
  for (uint32_t i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

uint32_t above_prime(uint32_t n) {
  for (uint32_t i = n;; i++) {
    if (is_prime(i)) {
      return i;
    }
  }
}

uint32_t below_prime(uint32_t n) {
  for (uint32_t i = n;; i--) {
    if (is_prime(i) || i == 1) {
      return i;
    }
  }
}

int32_t main() {
  while (true) {
    uint32_t n;
    cin >> n;
    if (n == 0) break;

    uint32_t above = above_prime(n);
    uint32_t below = below_prime(n);

    cout << above - below << endl;
  }

  return 0;
}
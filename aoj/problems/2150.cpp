#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

bool is_prime(int32_t n) {
  if (n == 0 || n == 1) return false;

  for (uint32_t i = 2; i <= (uint32_t)sqrt((double)n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

vector<int32_t> primes(int32_t n) {
  int32_t count = 100;
  int32_t num = n + 1;
  vector<int32_t> ret;
  while (0 < count) {
    if (is_prime(num)) {
      ret.push_back(num);
      count--;
    }
    num++;
  }
  return ret;
}

int32_t main() {
  while (true) {
    int32_t N, P;
    cin >> N >> P;
    if (N == -1) break;

    vector<int32_t> ps = primes(N);
    vector<int32_t> sums;
    for (uint32_t i = 0; i < ps.size(); i++) {
      for (uint32_t j = i; j < ps.size(); j++) {
        sums.push_back(ps[i] + ps[j]);
      }
    }

    sort(sums.begin(), sums.end());

    cout << sums[P - 1] << endl;
  }

  return 0;
}
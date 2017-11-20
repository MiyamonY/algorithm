#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

uint32_t gcd(int32_t a, int32_t b) {
  if (b > a) return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int32_t main() {
  while (true) {
    string str;
    cin >> str;
    if (str[0] == '#') break;

    vector<int32_t> dirs;
    uint32_t i = 0;
    while (i < str.size()) {
      if (str[i] == 'n') {
        dirs.push_back(-1);
        i += 5;
      } else if (str[i] == 'w') {
        dirs.push_back(+1);
        i += 4;
      }
    }

    reverse(dirs.begin(), dirs.end());

    pair<int32_t, int32_t> degree;
    degree.second = 1;
    if (dirs[0] == -1) {
      degree.first = 0;
    } else {
      degree.first = 90;
    }

    for (uint32_t i = 1; i < dirs.size(); i++) {
      degree.first *= 2;
      degree.second *= 2;
      degree.first += dirs[i] * 90;
    }

    if (degree.first == 0) {
      cout << 0 << endl;
    } else {
      uint32_t div = gcd(degree.first, degree.second);
      degree.first /= div;
      degree.second /= div;
      if (degree.second == 1) {
        cout << degree.first << endl;
      } else {
        cout << degree.first << "/" << degree.second << endl;
      }
    }
  }
  return 0;
}
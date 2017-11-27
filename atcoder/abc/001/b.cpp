#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

int32_t main() {
  uint32_t dist;
  cin >> dist;

  cout << setfill('0') << setw(2);
  if (dist < 100) {
    cout << 0 << endl;
  } else if (dist <= 5000) {
    cout << dist * 10 / 1000 << endl;
  } else if (dist <= 30000) {
    cout << dist / 1000 + 50 << endl;
  } else if (dist <= 70000) {
    cout << (dist / 1000 - 30) / 5 + 80 << endl;
  } else {
    cout << 89 << endl;
  }

  return 0;
}
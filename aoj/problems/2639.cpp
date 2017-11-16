#include <cstdint>
#include <iostream>

using namespace std;

int32_t main() {
  uint32_t a, b, c;
  cin >> a >> b >> c;

  int32_t time = -1;
  for (uint32_t i = c; i <= (a + b) * 60; i += 60) {
    if (i % (a + b) <= a) {
      time = i;
      break;
    }
  }

  cout << time << endl;

  return 0;
}

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t N;
  cin >> N;

  uint64_t total = 0;
  for (uint64_t i = 0; i < N; i++) {
    uint64_t x, y;
    cin >> x >> y;
    total += y - x + 1;
  }

  cout << total << endl;

  return 0;
}

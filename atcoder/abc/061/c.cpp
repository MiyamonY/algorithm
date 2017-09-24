#include <iostream>
#include <stdint.h>

using namespace std;

#define MAX 100000
static uint64_t counts[MAX];

int32_t main()
{
  int64_t N, K;
  cin >> N >> K;

  for (int32_t i = 0; i < N; i++) {
    uint32_t a, b;
    cin >> a >> b;
    counts[a - 1] += b;
  }

  for (int32_t i = 0; i < MAX; i++) {
    K -= counts[i];
    if (K <= 0) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}

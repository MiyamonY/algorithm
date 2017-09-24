#include <iostream>
#include <stdint.h>

#define MAX_CITIES 50

using namespace std;

static uint32_t routes[MAX_CITIES][MAX_CITIES];

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;

  for (uint32_t i = 0; i < M; i++) {
    uint32_t a, b;
    cin >> a >> b;
    a--;
    b--;
    routes[a][b]++;
    routes[b][a]++;
  }

  for (uint32_t i = 0; i < N; i++) {
    uint32_t count = 0;
    for (uint32_t j = 0; j < N; j++) {
      count += routes[i][j];
    }
    cout << count << endl;
  }

  return 0;
}

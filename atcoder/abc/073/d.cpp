#include <cstdint>
#include <iostream>

using namespace std;

#define MAX_R 8
#define MAX_VERTEX 200

static uint32_t rs[MAX_R];
static uint32_t perm[MAX_R];
static bool used[MAX_R];
static uint64_t routes[MAX_VERTEX][MAX_VERTEX];

uint64_t apply_all_patterns(uint32_t len, uint32_t max)
{
  if (len == max) {
    uint64_t weight = 0;
    for (uint32_t i = 0; i < (max - 1); i++) {
      weight += routes[perm[i]][perm[i + 1]];
    }
    return weight;
  } else {
    uint64_t min_weight = UINT32_MAX;
    for (uint32_t i = 0; i < max; i++) {
      if (used[i]) continue;
      perm[len] = rs[i];
      used[i] = true;
      uint64_t weight = apply_all_patterns(len + 1, max);
      if (weight > 0) {
        min_weight = min(weight, min_weight);
      }
      used[i] = false;
    }
    return min_weight;
  }
}

uint32_t min_path(int32_t R)
{
  return apply_all_patterns(0, R);
}

void init_routes(uint32_t N)
{
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      routes[i][j] = UINT32_MAX;
    }
  }
}

int32_t main()
{
  uint32_t N, M, R;
  cin >> N >> M >> R;

  for (uint32_t i = 0; i < R; i++) {
    cin >> rs[i];
    rs[i]--;
  }

  init_routes(N);
  for (uint32_t i = 0; i < M; i++) {
    uint32_t A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    routes[A][B] = routes[B][A] = C;
  }

  for (uint32_t k = 0; k < N; k++) {
    for (uint32_t i = 0; i < N; i++) {
      for (uint32_t j = 0; j < N; j++) {
        uint64_t weight = routes[i][k] + routes[k][j];
        routes[i][j] = min(weight, routes[i][j]);
      }
    }
  }

  cout << min_path(R) << endl;

  return 0;
}

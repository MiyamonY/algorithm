#include <cstdint>
#include <iostream>

using namespace std;

#define MAX_R 8
#define MAX_VERTEX 200

static uint32_t rs[MAX_R];
static uint32_t perm[MAX_R];
static bool used[MAX_R];
static int32_t graphs[MAX_VERTEX][MAX_VERTEX];
static int32_t routes[MAX_VERTEX][MAX_VERTEX];

uint64_t apply_all_patterns(int32_t len, uint32_t max)
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

void init_graphs(uint32_t N)
{
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      if (i == j) {
        graphs[i][j] = 0;
      } else {
        graphs[i][j] = -1;
      }
    }
  }
}

void init_routes(int32_t N)
{
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      routes[i][j] = INT32_MAX;
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

  init_graphs(N);
  for (uint32_t i = 0; i < M; i++) {
    uint32_t A, B, C;
    cin >> A >> B >> C;
    graphs[A - 1][B - 1] = graphs[B - 1][A - 1] = C;
  }

  init_routes(N);
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      for (uint32_t k = 0; k < N; k++) {
        if ((graphs[i][k] == -1) || (graphs[k][j] == -1)) continue;
        int32_t weight = graphs[i][k] + graphs[k][j];
        routes[i][j] = min(weight, routes[i][j]);
      }
    }
  }

  cout << endl << endl;
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      cout << graphs[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << endl << endl;
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      cout << routes[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << min_path(R) << endl;

  return 0;
}

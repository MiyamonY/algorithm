#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

#define MAX_SIZE 1000
#define INF (1LL << 50)

static vector<pair<int64_t, int64_t>> graph[MAX_SIZE];
static int64_t weights[MAX_SIZE];

void init_weights(uint32_t N)
{
  for (uint32_t i = 0; i < N; i++) {
    weights[i] = INF;
  }
  weights[0] = 0;
}

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;

  init_weights(N);

  for (uint32_t i = 0; i < M; i++) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    graph[a - 1].push_back(make_pair(b - 1, -c));
  }

  uint32_t count = 0;
  for (uint32_t _ = 0; _ < N - 1; _++) {
    for (uint32_t i = 0; i < N; i++) {
      if (weights[i] == INF) continue;
      vector<pair<int64_t, int64_t>> routes = graph[i];
      for (uint32_t j = 0; j < routes.size(); j++) {
        int64_t to = routes[j].first;
        int64_t weight = routes[j].second + weights[i];
        if (weight < weights[to]) {
          weights[to] = weight;
        }
      }
    }
  }

  int64_t ans = -weights[N - 1];

  for (uint32_t _ = 0; _ < N - 1; _++) {
    for (uint32_t i = 0; i < N; i++) {
      if (weights[i] == INF) continue;
      vector<pair<int64_t, int64_t>> routes = graph[i];
      for (uint32_t j = 0; j < routes.size(); j++) {
        int64_t to = routes[j].first;
        int64_t weight = routes[j].second + weights[i];
        if (weight < weights[to]) {
          weights[to] = weight;
        }
      }
    }
  }

  if (ans == -weights[N - 1]) {
    cout << -weights[N - 1] << endl;
  } else {
    cout << "inf" << endl;
  }

  return 0;
}

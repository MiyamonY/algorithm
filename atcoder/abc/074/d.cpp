#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define GRAPH_SIZE 300
static vector<uint32_t> graph[GRAPH_SIZE];
static vector<uint32_t> graph0[GRAPH_SIZE];

int32_t main()
{
  uint32_t N;
  cin >> N;

  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t _ = 0; _ < N; _++) {
      uint32_t weight;
      cin >> weight;
      graph[i].push_back(weight);
      graph0[i].push_back(weight);
    }
  }

  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      bool has_same = false;
      for (uint32_t k = 0; k < N; k++) {
        uint32_t weight = graph[i][j];
        uint32_t weight0 = graph[i][k];
        uint32_t weight1 = graph[k][j];
        if ((weight0 + weight1) < weight) {
          cout << -1 << endl;
          return 0;
        }
        if ((k != i) && (k != j) && ((weight0 + weight1) == weight)) {
          has_same = true;
        }
      }
      if (has_same) {
        graph0[i][j] = 0;
      }
    }
  }

  uint64_t weights = 0;
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = i; j < N; j++) {
      weights += graph0[i][j];
    }
  }

  cout << weights << endl;

  return 0;
}

///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 15:55:22 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define MAX_N 40
#define MAX_A 10
#define MAX_B 10
#define MAX_C 100
#define COST_MAX (MAX_N * MAX_C + 1)

struct cost {
  int32_t a;
  int32_t b;
  int32_t c;
};

static int32_t costs[MAX_N + 1][MAX_N * MAX_A + 1][MAX_N * MAX_B + 1];
static cost inputs[MAX_N];

void init_costs()
{
  for (int32_t j = 0; j <= MAX_N * MAX_A; j++) {
    for (int32_t k = 0; k <= MAX_N * MAX_B; k++) {
      costs[0][j][k] = COST_MAX;
    }
  }
  costs[0][0][0] = 0;
}

int32_t main()
{
  int32_t N, Ma, Mb;
  cin >> N >> Ma >> Mb;

  for (int32_t i = 0; i < N; i++) {
    cin >> inputs[i].a >> inputs[i].b >> inputs[i].c;
  }

  init_costs();
  for (int32_t i = 1; i <= N; i++) {
    for (int32_t a = 0; a <= N * MAX_A; a++) {
      for (int32_t b = 0; b <= N * MAX_B; b++) {
        costs[i][a][b] = costs[i - 1][a][b];
        if ((a - inputs[i - 1].a) >= 0 && (b - inputs[i - 1].b) >= 0) {
          costs[i][a][b] = min(costs[i - 1][a][b], costs[i - 1][a - inputs[i - 1].a][b - inputs[i - 1].b] + inputs[i - 1].c);
        }
      }
    }
  }

  int32_t cost = COST_MAX;
  for (int32_t a = 1; a <= N * MAX_A; a++) {
    for (int32_t b = 1; b <= N * MAX_B; b++) {
      if (a * Mb == b * Ma) {
        cost = min(cost, costs[N][a][b]);
      }
    }
  }

  if (cost == COST_MAX) {
    cout << "-1" << endl;
  } else {
    cout << cost << endl;
  }

  return 0;
}

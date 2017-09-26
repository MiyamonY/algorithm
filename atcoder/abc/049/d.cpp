#include <iostream>
#include <map>
#include <stdint.h>
#include <vector>

using namespace std;

#define CITIES (2 * 100000)

static vector<uint32_t> roads[CITIES];
static vector<uint32_t> rails[CITIES];
static uint64_t road_connected[CITIES];
static uint64_t rail_connected[CITIES];

static void calc_connected(vector<uint32_t> *routes, uint64_t *connected, uint32_t index, uint32_t color)
{
  if (connected[index] != 0) return;
  connected[index] = color;

  for (uint32_t i = 0; i < routes[index].size(); i++) {
    calc_connected(routes, connected, routes[index][i], color);
  }
}

int32_t main()
{
  uint32_t N, K, L;
  cin >> N >> K >> L;

  for (uint32_t i = 0; i < K; i++) {
    uint32_t p, q;
    cin >> p >> q;
    roads[p - 1].push_back(q - 1);
    roads[q - 1].push_back(p - 1);
  }

  for (uint32_t i = 0; i < L; i++) {
    uint32_t r, s;
    cin >> r >> s;
    rails[r - 1].push_back(s - 1);
    rails[s - 1].push_back(r - 1);
  }

  for (uint32_t i = 0; i < N; i++) {
    calc_connected(roads, road_connected, i, i + 1);
  }

  for (uint32_t i = 0; i < N; i++) {
    calc_connected(rails, rail_connected, i, i + 1);
  }

  map<pair<uint64_t, uint64_t>, uint64_t> counter;

  for (uint32_t i = 0; i < N; i++) {
    pair<uint64_t, uint64_t> index(road_connected[i], rail_connected[i]);
    counter[index]++;
  }

  for (uint32_t i = 0; i < N; i++) {
    if (i != 0) cout << " ";
    pair<uint64_t, uint64_t> index(road_connected[i], rail_connected[i]);
    cout << counter[index];
  }

  cout << endl;

  return 0;
}

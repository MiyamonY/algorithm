#include <iostream>
#include <stdint.h>
#include <vector>
#include <map>

using namespace std;

#define CITIES (2 * 100000)

static vector<uint32_t> roads[CITIES];
static vector<uint32_t> rails[CITIES];
static uint64_t road_connected[CITIES];
static uint64_t rail_connected[CITIES];

static void calc_connected(vector<uint32_t> *routes, uint32_t N, uint64_t *connected, uint32_t index, uint32_t color)
{
  if(connected[index] != 0)  return;

  for(uint32_t i = 0; i < routes[index].size(); i++){
    calc_connected(routes, N, connected, routes[index][i], color);
  }
  connected[index] = color;
}

int32_t main()
{
  uint32_t N, K, L;
  cin >> N >> K >> L;

  for(uint32_t i = 0; i < K; i++){
    uint32_t p, q;
    cin >> p >> q;
    roads[p-1].push_back(q-1);
  }

  for(uint32_t i = 0; i < L; i++){
    uint32_t r, s;
    cin >> r >> s;
    rails[r-1].push_back(s-1);
  }

  for(uint32_t i = 0; i < N; i++){
    calc_connected(roads, N, road_connected, i, i + 1);
  }

  for(uint32_t i = 0; i < N; i++){
    calc_connected(rails, N, rail_connected, i, i + 1);
  }


  map<pair<uint64_t, uint64_t>, uint32_t> counter;

  for(uint32_t i = 0; i < N; i++){
    pair<uint64_t, uint64_t> index(road_connected[i], rail_connected[i]);
    if(counter.count(index)){
      counter[index] += 1;
    } else{
      counter[index]++;
    }
  }

  for(uint32_t i = 0; i < N; i++){
    if(i != 0) cout << " ";
    pair<uint64_t, uint64_t> index(road_connected[i], rail_connected[i]);
    cout << counter[index];
  }
  cout << endl;

  return 0;
}

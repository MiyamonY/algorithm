#include <array>
#include <cstdint>
#include <iostream>
#include <queue>

using namespace std;

void wfs(array<array<int32_t, 200>, 200> &hex, int32_t x, int32_t y) {
  queue<pair<int32_t, int32_t>> q;

  hex[x][y] = 0;
  q.push({x, y});

  while (!q.empty()) {
    pair<int32_t, int32_t> p = q.front();
    int32_t x = p.first;
    int32_t y = p.second;
    q.pop();

    vector<pair<int32_t, int32_t>> vecs{{0, 1}, {1, 1},   {-1, 0},
                                        {1, 0}, {-1, -1}, {0, -1}};
    for (uint32_t i = 0; i < vecs.size(); i++) {
      int32_t posx = x + vecs[i].first;
      int32_t posy = y + vecs[i].second;
      if (0 <= posx && posx < 200 && 0 <= posy && posy < 200 &&
          hex[posx][posy] == INT32_MAX) {
        hex[posx][posy] = hex[x][y] + 1;
        q.push({posx, posy});
      }
    }
  }
}

int32_t main() {
  while (true) {
    int32_t t, n;
    cin >> t >> n;
    if (t == 0 && n == 0) break;

    array<array<int32_t, 200>, 200> hex;
    for (uint32_t i = 0; i < hex.size(); i++) {
      for (uint32_t j = 0; j < hex[0].size(); j++) {
        hex[i][j] = INT32_MAX;
      }
    }

    for (uint32_t i = 0; i < n; i++) {
      int32_t x, y;
      cin >> x >> y;
      hex[x + 100][y + 100] = -1;
    }
    int32_t x, y;
    cin >> x >> y;
    wfs(hex, x + 100, y + 100);

    uint32_t count = 0;
    for (uint32_t i = 0; i < hex.size(); i++) {
      for (uint32_t j = 0; j < hex[0].size(); j++) {
        if (0 <= hex[i][j] && hex[i][j] <= t) {
          count++;
        }
      }
    }

    cout << count << endl;
  }

  return 0;
}
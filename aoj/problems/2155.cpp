#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct packet_t {
  uint32_t t;
  uint32_t s;
  uint32_t d;

  bool operator<(const packet_t &packet) { return t < packet.t; }
};

int32_t main() {
  while (true) {
    uint32_t N, M;
    cin >> N >> M;
    if (N == 0) break;

    vector<packet_t> packets;
    for (uint32_t i = 0; i < M; i++) {
      uint32_t t, s, d;
      cin >> t >> s >> d;
      packet_t p({t, s, d});
      packets.push_back(p);
    }

    sort(packets.begin(), packets.end());
    vector<bool> infected(N + 1);
    infected[1] = true;
    for (uint32_t i = 0; i < packets.size(); i++) {
      if (infected[packets[i].s]) {
        infected[packets[i].d] = true;
      }
    }

    uint32_t count = 0;
    for (uint32_t i = 1; i <= N; i++) {
      if (infected[i]) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}

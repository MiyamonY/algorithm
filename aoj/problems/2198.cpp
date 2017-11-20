#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main() {
  while (true) {
    uint32_t N;
    cin >> N;
    if (N == 0) break;

    vector<pair<double, string>> seeds;
    for (uint32_t _ = 0; _ < N; _++) {
      string L;
      double P, A, B, C, D, E, F, S, M;
      cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;
      double time = (A + B + C + D + E) + (D + E) * (M - 1);
      double efficiency = -(M * F * S - P) / time;
      seeds.push_back({efficiency, L});
    }

    sort(seeds.begin(), seeds.end());

    for (auto iter = seeds.begin(); iter < seeds.end(); iter++) {
      cout << iter->second << endl;
    }
    cout << "#" << endl;
  }
  return 0;
}
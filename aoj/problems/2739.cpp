#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main() {
  int32_t N, M, T;
  cin >> N >> M >> T;

  vector<int32_t> times;
  for (uint32_t i = 0; i < N; i++) {
    int32_t time;
    cin >> time;
    times.push_back(time - M);
    times.push_back(time + M);
  }

  int32_t count = times[0] - 0;
  for (uint32_t i = 1; i < times.size() - 1; i += 2) {
    if (times[i + 1] - times[i] >= 0) {
      count += times[i + 1] - times[i];
    }
  }

  if (T - times[times.size() - 1] >= 0) {
    count += T - times[times.size() - 1];
  }

  cout << count << endl;

  return 0;
}
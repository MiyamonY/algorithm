#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int32_t main() {
  while (true) {
    uint32_t N, Q;
    cin >> N >> Q;
    if (N == 0 && Q == 0) break;

    vector<tuple<uint32_t, uint32_t, string>> years;
    for (uint32_t _ = 0; _ < N; _++) {
      string name;
      uint32_t base_year, western_year;
      cin >> name >> base_year >> western_year;
      years.push_back(make_tuple(western_year, base_year, name));
    }

    for (uint32_t _ = 0; _ < Q; _++) {
      uint32_t year;
      cin >> year;
      bool found = false;
      for (auto iter = years.begin(); iter < years.end(); iter++) {
        uint32_t western_year = get<0>(*iter);
        uint32_t base_year = get<1>(*iter);
        uint32_t start_year = western_year + 1 - base_year;
        if (start_year <= year && year <= western_year) {
          found = true;
          cout << get<2>(*iter) << " " << year - start_year + 1 << endl;
          break;
        }
      }
      if (!found) {
        cout << "Unknown" << endl;
      }
    }
  }

  return 0;
}
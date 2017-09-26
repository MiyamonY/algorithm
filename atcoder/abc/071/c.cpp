#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<uint64_t> lines;
  for (uint32_t _ = 0; _ < N; _++) {
    uint64_t line;
    cin >> line;
    lines.push_back(line);
  }

  sort(lines.begin(), lines.end());

  uint64_t width_found = false;
  uint64_t width = 0;
  uint64_t height = 0;

  while (!lines.empty()) {
    uint64_t line = lines.back();
    if (!width_found) {
      if (width == line) {
        width_found = true;
      } else {
        width = line;
      }
    } else {
      if (height == line) {
        break;
      } else {
        height = line;
      }
    }
    lines.pop_back();
  }

  cout << width * height << endl;

  return 0;
}

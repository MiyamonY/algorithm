#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
#define SIZE 100001
static uint64_t array[SIZE];

int32_t main()
{
  uint64_t N;
  cin >> N;

  for (uint64_t i = 0; i < N; i++) {
    cin >> array[i];
  }

  sort(array, array + N);

  uint64_t counter = 0;
  uint64_t old = 0;
  uint64_t same_val = 0;
  for (uint64_t i = 0; i < N; i++) {
    if (array[i] == old) {
      same_val++;
    } else {
      if (same_val % 2 == 1) {
        counter++;
      }
      old = array[i];
      same_val = 1;
    }
  }

  if (same_val % 2 == 1) {
    counter++;
  }

  cout << counter << endl;
  return 0;
}

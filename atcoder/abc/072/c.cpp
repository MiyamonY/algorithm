#include <cstdint>
#include <iostream>

using namespace std;
#define COUNTER_SIZE 100000

static uint32_t counter[COUNTER_SIZE];

int32_t main()
{
  uint32_t N;
  cin >> N;
  for(uint32_t i = 0; i < N; i++){
    uint32_t val;
    cin >> val;
    if(val > 0){
      counter[val-1]++;
    }
    counter[val]++;
    counter[val+1]++;
  }

  uint32_t max_count = 0;
  for(uint32_t i = 0; i < COUNTER_SIZE; i++){
    max_count = max(max_count, counter[i]);
  }

  cout << max_count << endl;

  return 0;
}

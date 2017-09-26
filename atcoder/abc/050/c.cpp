#include <iostream>
#include <stdint.h>

using namespace std;

#define MOD 1000000007
#define SIZE 100000

static uint32_t nums[SIZE];

int32_t main()
{
  uint32_t N;
  cin >> N;
  for(uint32_t i = 0; i < N; i++){
    uint32_t n;
    cin >> n;
    nums[n]++;
  }

  uint64_t count;
  if(N % 2 == 1){
    if(nums[0] == 1){
      count = 1;
    } else{
      count = 0;
    }
  } else{
    count = 1;
  }

  for(uint32_t i = 1; i < N; i++){
    if(nums[i] == 2){
      count *= 2;
    } else if (nums[i] == 0){
      count *= 1;
    } else{
      count = 0;
    }
    count %= MOD;
  }

  cout << count << endl;

  return 0;
}

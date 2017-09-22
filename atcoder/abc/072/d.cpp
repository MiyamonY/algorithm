#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<uint32_t> array;

int32_t main()
{
  uint32_t N;
  cin >> N;

  array.push_back(0);
  for(uint32_t i = 0; i< N; i++){
    uint32_t val;
    cin >> val;
    array.push_back(val);
  }

  uint32_t count = 0;
  for(uint32_t i = 1; i < array.size(); i++){
    if(array[i] == i){
      swap(array[i], array[i+1]);
      count++;
    }
  }

  if(array[array.size() - 1] == N){
    count++;
  }

  cout << count << endl;

  return 0;
}

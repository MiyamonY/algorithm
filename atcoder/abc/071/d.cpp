#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

#define MOD 1000000007

enum status_t {
  Start,
  Vertical,
  Horizontal,
};

int32_t main()
{
  uint32_t N;
  cin >> N;

  string str1, str2;
  cin >> str1;
  cin >> str2;

  status_t status = Start;
  uint32_t index = 0;
  uint64_t count = 1;
  while(index < N){
    if(str1[index] == str2[index]){
      if(status == Start){
        count *= 3;
      } else if (status == Vertical){
        count *= 2;
      } else {
        count *= 1;
      }
      status = Vertical;
      index++;
    } else {
      if(status == Start){
        count *= 6;
      } else if (status == Vertical){
        count *= 2;
      } else {
        count *= 3;
      }
      status = Horizontal;
      index += 2;
    }
    count %= MOD;
  }

  count %= MOD;

  cout << count << endl;

  return 0;
}

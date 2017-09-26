#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;
static vector<uint32_t> Ts;
int32_t main()
{
  uint32_t N;
  cin >> N;

  for(uint32_t i = 0; i < N ; i++){
    int32_t t;
    cin >> t;
    Ts.push_back(t);
  }

  uint32_t M;
  cin >> M;
  for(uint32_t i = 0; i < M; i++){
    uint32_t p, m;
    cin >> p >> m;
    p--;
    uint32_t count = 0;
    for(uint32_t i = 0; i < Ts.size();i++){
      if(i == p){
        count += m;
      } else{
        count += Ts[i];
      }
    }
    cout << count << endl;
  }

  return 0;
}

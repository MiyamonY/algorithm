#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
  while(true){
    unsigned int n;
    cin >> n;

    if(n == 0) break;

    unsigned int min_val = UINT32_MAX;
    unsigned int max_val = 0;
    unsigned int count = 0;
    for(unsigned int i = 0; i < n; i++){
      unsigned int val;
      cin >> val;
      min_val = min(val, min_val);
      max_val = max(val, max_val);
      count += val;
    }
    cout << (count - min_val - max_val) / (n -2) << endl;
  }
  
  return 0;
}
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t X, t;
  cin >> X >> t;

  if(X < t){
    cout << 0 << endl;
  } else {
    cout << X - t << endl;
  }

  return 0;
}

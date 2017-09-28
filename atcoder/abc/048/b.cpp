#include <iostream>
#include <stdint.h>

using namespace std;

int32_t main()
{
  uint64_t a, b, x;
  cin >> a >> b >> x;

  if (a == 0) {
    cout << b / x + 1 << endl;
  } else {
    cout << b / x - (a - 1) / x << endl;
  }

  return 0;
}

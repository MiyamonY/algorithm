#include <iostream>
#include <stdint.h>

using namespace std;

int32_t main()
{
  int32_t x, a, b;
  cin >> x >> a >> b;

  if (abs(x - a) < abs(x - b)) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }

  return 0;
}

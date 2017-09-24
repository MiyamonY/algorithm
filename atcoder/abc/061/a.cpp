#include <iostream>
#include <stdint.h>

using namespace std;

int32_t main()
{
  int32_t A, B, C;

  cin >> A >> B >> C;

  if ((A <= C) && (C <= B)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

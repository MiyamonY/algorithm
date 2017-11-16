///
// File:  2424.cpp
// Author: ymiyamoto
//
// Created on Thu Nov 16 21:38:19 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  uint32_t Q;
  cin >> Q;

  for (uint32_t _ = 0; _ < Q; _++) {
    string n;
    cin >> n;

    uint32_t count = 0;
    while (n.size() > 1) {
      count++;
      int32_t maxval = 0;
      for (uint32_t i = 1; i < n.size(); i++) {
        string n1 = n.substr(0, i);
        string n2 = n.substr(i, n.size() - i);
        maxval = max(maxval, stoi(n1) * stoi(n2));
      }
      if (n == to_string(maxval)) {
        count = -1;
        break;
      } else {
        n = to_string(maxval);
      }
    }
    cout << count << endl;
  }
  return 0;
}

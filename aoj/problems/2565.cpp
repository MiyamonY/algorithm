///
// File:  2565.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 26 23:04:35 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    int32_t n;
    cin >> n;

    if (n == 0) break;

    vector<string> signals(n + 1);
    for (int32_t i = 1; i <= n; i++) {
      cin >> signals[i];
    }

    bool invalid = false;
    int64_t xodd = INT32_MAX;
    int64_t xeven = INT32_MIN;
    for (int32_t i = 1; i <= n; i++) {
      if (i + 1 <= n && signals[i] == signals[i + 1]) {
        invalid = true;
      }

      if (signals[i] != "x") {
        if (i % 2 == 1) {
          int64_t s = stoll(signals[i]);
          if (i - 1 >= 1 && signals[i - 1] != "x" && s >= stoll(signals[i - 1])) {
            invalid = true;
          }
          if (i + 1 <= n && signals[i + 1] != "x" && s >= stoll(signals[i + 1])) {
            invalid = true;
          }
        } else {
          int64_t s = stoll(signals[i]);
          if (i - 1 >= 1 && signals[i - 1] != "x" && s <= stoll(signals[i - 1])) {
            invalid = true;
          }
          if (i + 1 <= n && signals[i + 1] != "x" && s <= stoll(signals[i + 1])) {
            invalid = true;
          }
        }
      } else {
        if ((i - 1 >= 1 && signals[i - 1] == "x") || (i + 1 <= n && signals[i + 1] == "x")) {
          invalid = true;
        } else {
          if (i % 2 == 1) {
            int64_t x1 = i - 1 >= 1 ? stoll(signals[i - 1]) : INT64_MAX;
            int64_t x2 = i + 1 <= n ? stoll(signals[i + 1]) : INT64_MAX;
            xodd = min(xodd, min(x1, x2) - 1);
          } else {
            int64_t x1 = i - 1 >= 1 ? stoll(signals[i - 1]) : INT64_MIN;
            int64_t x2 = i + 1 <= n ? stoll(signals[i + 1]) : INT64_MIN;
            xeven = max(xeven, max(x1, x2) + 1);
          }
        }
      }
    }
    if (invalid) {
      cout << "none" << endl;
    } else if (xodd == xeven) {
      cout << xodd << endl;
    } else if (xodd < xeven) {
      cout << "none" << endl;
    } else {
      cout << "ambiguous" << endl;
    }
  }
  return 0;
}

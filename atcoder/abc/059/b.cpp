///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 16:04:29 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  string A, B;
  cin >> A;
  cin >> B;

  if (A.size() > B.size()) {
    cout << "GREATER" << endl;
    return 0;
  } else if (A.size() < B.size()) {
    cout << "LESS" << endl;
    return 0;
  } else {
    for (uint32_t i = 0; i < A.size(); i++) {
      if (A[i] > B[i]) {
        cout << "GREATER" << endl;
        return 0;
      } else if (A[i] < B[i]) {
        cout << "LESS" << endl;
        return 0;
      }
    }
    cout << "EQUAL" << endl;
    return 0;
  }
}

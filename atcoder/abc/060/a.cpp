///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 29 22:37:02 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string A, B, C;
  cin >> A >> B >> C;

  if ((A[A.size() - 1] == B[0]) && (B[B.size() - 1] == C[0])) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;

  return 0;
}

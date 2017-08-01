///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 19:34:16 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string O, E;
  cin >> O;
  cin >> E;

  for (uint32_t i = 0; i < E.size(); i++) {
    cout << O[i] << E[i];
  }

  if (O.size() > E.size()) {
    cout << O[O.size() - 1];
  }

  cout << endl;

  return 0;
}

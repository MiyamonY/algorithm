///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Dec  3 21:00:01 2017
//
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()

{
  int32_t N, A, B;
  cin >> N >> A >> B;
  cout << min(N * A, B) << endl;

  return 0;
}

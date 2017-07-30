///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 09:58:42 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

#define N 50

int32_t main()
{
  long long K;
  cin >> K;

  cout << N << endl;

  for (uint32_t i = 0; i <= N; i++) {
    if (i == (N - (K % N))) continue;
    if (i != 0) cout << " ";
    cout << i + (K / N);
  }
  cout << endl;

  return 0;
}

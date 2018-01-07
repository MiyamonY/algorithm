///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan  7 21:15:48 2018
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<int32_t> mochi(N);
  for (uint32_t i = 0; i < N; i++) {
    cin >> mochi[i];
  }

  sort(mochi.begin(), mochi.end());
  int32_t dia = -1;
  int32_t count = 0;
  for (uint32_t i = 0; i < mochi.size(); i++) {
    if (dia != mochi[i]) {
      dia = mochi[i];
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

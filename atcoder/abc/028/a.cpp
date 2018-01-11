///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 11 21:21:30 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  if (N <= 59) {
    cout << "Bad" << endl;
  } else if (N <= 89) {
    cout << "Good" << endl;
  } else if (N <= 99) {
    cout << "Great" << endl;
  } else {
    cout << "Perfect" << endl;
  }
  return 0;
}

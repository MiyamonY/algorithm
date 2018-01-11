///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 11 21:22:51 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  string S;
  cin >> S;

  map<char, int32_t> m;
  m['A'] = m['B'] = m['C'] = m['D'] = m['E'] = m['F'] = 0;
  for (auto c : S) {
    m[c] += 1;
  }

  cout << m['A'] << " " << m['B'] << " " << m['C'] << " " << m['D'] << " " << m['E'] << " " << m['F'] << endl;
  return 0;
}

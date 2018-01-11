///
//  Author : Author
// Created On : Mon Dec 18 2017
//  File : a.cpp
//
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main() {
  char X, Y;
  cin >> X >> Y;
  if (X == Y) {
    cout << "=" << endl;
  } else if (X < Y) {
    cout << "<" << endl;
  } else {
    cout << ">" << endl;
  }

  return 0;
}

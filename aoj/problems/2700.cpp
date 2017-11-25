///
// File:  2700.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 26 02:25:16 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int32_t main()
{
  while (true) {
    uint32_t n;
    cin >> n;
    if (n == 0) break;

    uint32_t max_len = 0;
    vector<string> codes;
    for (uint32_t i = 0; i < n; i++) {
      string str;
      cin >> str;

      string code = "";
      for (uint32_t j = 0; j < str.size(); j++) {
        if (j == 0) {
          code += str[j];
        } else {
          char prev = str[j - 1];
          if (prev == 'a' || prev == 'i' || prev == 'u' || prev == 'e' || prev == 'o') {
            code += str[j];
          }
        }
      }
      codes.push_back(code);
      max_len = max(max_len, (uint32_t)code.size());
    }

    int32_t min_k = -1;
    for (uint32_t k = 1; k <= max_len; k++) {
      vector<string> codes2;
      for (uint32_t i = 0; i < codes.size(); i++) {
        string code = codes[i];
        if (code.size() < k) {
          codes2.push_back(code);
        } else {
          codes2.push_back(code.substr(0, k));
        }
      }

      bool is_same = false;
      for (uint32_t i = 0; i < codes2.size(); i++) {
        for (uint32_t j = i + 1; j < codes2.size(); j++) {
          if (codes2[i] == codes2[j]) {
            is_same = true;
            break;
          }
        }
      }

      if (!is_same) {
        min_k = k;
        break;
      }
    }
    cout << min_k << endl;
  }
  return 0;
}

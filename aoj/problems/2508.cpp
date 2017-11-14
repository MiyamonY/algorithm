#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string str1(
    {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU"
     "VWXYZ"});
const string str2(
    {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstu"
     "vwxyz"});

int32_t main() {
  while (true) {
    uint32_t n = 0;
    cin >> n;
    if (n == 0) break;
    vector<uint32_t> keys;
    for (uint32_t i = 0; i < n; i++) {
      uint32_t key;
      cin >> key;
      keys.push_back(key);
    }

    string list;
    cin >> list;
    uint32_t key_index = 0;
    for (uint32_t i = 0; i < list.size(); i++) {
      char val;
      if ('A' <= list[i] && list[i] <= 'Z') {
        val = str1[str1.find(list[i], 26) - keys[key_index]];
      } else {
        val = str2[str2.find(list[i], 26) - keys[key_index]];
      }
      cout << val;
      key_index++;
      key_index %= keys.size();
    }
    cout << endl;
  }

  return 0;
}
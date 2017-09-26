#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;
#define SIZE 26
static bool chars[SIZE];

int32_t main()
{
  string str;
  cin >> str;

  for (uint32_t i = 0; i < str.size(); i++) {
    chars[(int)str[i] - 'a'] = true;
  }

  for (uint32_t i = 0; i < SIZE; i++) {
    if (!chars[i]) {
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }

  cout << "None" << endl;

  return 0;
}

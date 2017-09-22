#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  for(uint32_t i = 0; i < str.size(); i++){
    if((i % 2) == 0){
      cout << str[i];
    }
  }

  cout << endl;

  return 0;
}

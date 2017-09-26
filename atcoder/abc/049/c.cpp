#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <string>

using namespace std;

static string str;
static string str1 = "dream";
static string str2 = "dreamer";
static string str3 = "erase";
static string str4 = "eraser";

int32_t main()
{
  cin >> str;

  reverse(str.begin(), str.end());

  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  reverse(str3.begin(), str3.end());
  reverse(str4.begin(), str4.end());

  uint32_t index = 0;
  while(index < str.size()){

    if(str2.compare(str.substr(index, str2.size())) == 0){
      index += str2.size();
    } else if(str4.compare(str.substr(index, str4.size())) == 0){
      index += str4.size();
    } else if(str1.compare(str.substr(index, str1.size())) == 0){
      index += str1.size();
    } else if(str3.compare(str.substr(index, str3.size())) == 0){
      index += str3.size();
    } else{
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}

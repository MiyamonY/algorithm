#include <iostream>
#include <stdint.h>

using namespace std;

int32_t main()
{
  char e;

  cin >> e;
  if(e == 'a' || e == 'i' || e == 'u' || e == 'e' || e == 'o'){
    cout << "vowel" << endl;
  } else{
    cout << "consonant" << endl;
  }

  return 0;
}

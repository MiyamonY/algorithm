#include <iostream>
#include <stdint.h>

using namespace std;

int32_t main()
{
  int32_t A, B;
  char op;
  cin >> A >> op >> B;

  if(op =='+'){
    cout << A + B << endl;
  } else{
    cout << A - B << endl;
  }

  return 0;
}

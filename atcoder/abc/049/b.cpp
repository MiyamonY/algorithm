#include <iostream>
#include <stdint.h>

using namespace std;
#define SIZE 100
static char bitmap[SIZE][SIZE];

int32_t main()
{
  uint32_t H, W;
  cin >> H >> W;
  for(uint32_t i = 0; i < H; i++){
    for(uint32_t j = 0; j < W; j++){
      cin >> bitmap[i][j];
      cout << bitmap[i][j];
    }
    cout << endl;
    for(uint32_t j = 0; j < W; j++){
      cout << bitmap[i][j];
    }
    cout << endl;
  }

  return 0;
}

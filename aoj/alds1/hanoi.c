#include <stdio.h>

void TowersOfHanoi(int n, char frompeg, char topeg, char auxpeg){
  if(n == 1){
    printf("Move disk 1 to peg %c to peg %c", frompeg, topeg);
    return ;
  }

  TowersOfHanoi(n - 1, frompeg, auxpeg, topeg);

  printf("\nMove disk %d from peg to %c to peg %c\n", n, frompeg, topeg);

  TowersOfHanoi(n - 1, auxpeg, topeg, frompeg);

  return ;
}

int main(void){

  TowersOfHanoi(4, 'A', 'B', 'C');

  return 0;
}

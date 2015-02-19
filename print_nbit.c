#include <stdio.h>

char A[] = "2222";

void binary(int n){
  if(n < 1){
    printf("%s\n", A);
  }else{
    A[n - 1] = '0';
    binary(n - 1);
    A[n - 1] = '1';
    binary(n -1);
  }
  return;
}

int main(void){
  binary(4);

  return 0;
}

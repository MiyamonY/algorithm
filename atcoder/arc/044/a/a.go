package main

import (
	"fmt"
	"strconv"
)

func is_prime(n int) bool{
	if n <= 1 {
		return false
	}

	for i:=2; i*i <= n; i++{
		if n % i == 0{
			return false
		}
	}
	return true
}

func is_prime_like(n string) bool{
	switch n[len(n)-1]{
	case '0','2','4','5','6','8':
		return false
	}

	sum :=0
	for i:= range n{
		sum += int(n[i]-'0')
	}
	return !(sum % 3 == 0)
}

func main(){
	var N int
	fmt.Scan(&N)

	if is_prime(N){
		fmt.Println("Prime")
	} else {
		if N != 1 && is_prime_like(strconv.Itoa(N)){
			fmt.Println("Prime")
		} else {
			fmt.Println("Not Prime")
		}
	}
}

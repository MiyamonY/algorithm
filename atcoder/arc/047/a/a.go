package main

import (
	"fmt"
)

func main(){
	var N, L int
	var S string
	fmt.Scan(&N, &L)
	fmt.Scan(&S)

	count := 0
	num := 1
	for i := range(S){
		switch S[i]{
		case '-':
			num--
		case '+':
			num++
		}
		if num > L{
			count++
			num = 1
		}
	}

	fmt.Println(count)
}

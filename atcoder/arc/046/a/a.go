package main

import (
	"fmt"
)

func main(){
	var N int
	fmt.Scan(&N)
	N--

	num := (N % 9) + 1
	rep := N / 9 + 1

	for i := 0; i < rep; i++{
		fmt.Print(num)
	}
	fmt.Println()
}

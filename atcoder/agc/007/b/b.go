///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat May 12 19:14:32 2018
//
package main

import (
	"fmt"
)

var N int
var arr []int

func main() {
	fmt.Scan(&N)

	arr = make([]int, N+1)
	for i := 1; i <= N; i++ {
		var p int
		fmt.Scan(&p)
		arr[p] = i
	}

	for i := 1; i <= N; i++ {
		if i != 1 {
			fmt.Print(" ")
		}
		fmt.Print(i * N)
	}
	fmt.Println()

	for i := 1; i <= N; i++ {
		if i != 1 {
			fmt.Print(" ")
		}
		fmt.Print(N*(N-i) + arr[i])
	}
	fmt.Println()
}

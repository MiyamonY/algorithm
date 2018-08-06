///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 10:25:58 2018
//
package main

import (
	"fmt"
)

var D, J []int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	D = make([]int, 7)
	J = make([]int, 7)
	for i := range D {
		fmt.Scan(&D[i])
	}
	count := 0
	for i := range J {
		fmt.Scan(&J[i])
		count += max(D[i], J[i])
	}

	fmt.Println(count)
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri Apr 27 10:58:33 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int
var A []int

func main() {
	fmt.Scan(&N)

	A = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	sort.Ints(A)

	score := 0
	for i := len(A) - 1; i >= 0; i -= 2 {
		score += A[i]
	}

	fmt.Println(score)
}

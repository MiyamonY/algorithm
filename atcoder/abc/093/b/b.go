///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Apr  7 21:04:38 2018
//
package main

import (
	"fmt"
)

var A, B, K int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&A, &B, &K)

	for i := A; i < min(B+1, A+K); i++ {
		fmt.Println(i)
	}

	for i := max(A+K, B-K+1); i <= B; i++ {
		fmt.Println(i)
	}
}

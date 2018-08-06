///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jun  3 20:58:42 2018
//
package main

import (
	"fmt"
)

var N int
var P []int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N)
	P = make([]int, N+1)
	Q := make([]int, N+1)
	for i := 1; i < len(P); i++ {
		fmt.Scan(&P[i])
		Q[P[i]] = i
	}

	m := 0
	dp := make([]int, N+1)
	for i := 1; i < len(P); i++ {
		dp[i] = dp[Q[P[i]-1]] + 1
		if m < dp[i] {
			m = dp[i]
		}
	}

	fmt.Println(N - m)
}

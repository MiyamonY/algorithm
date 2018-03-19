///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Mar 14 22:54:17 2018
//
package main

import (
	"fmt"
)

var N int
var ps []int

func main() {
	fmt.Scan(&N)

	ps = make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&ps[i])
	}

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, N*100+1)
	}

	dp[0][0] = 1
	for i := 1; i <= N; i++ {
		for p := range dp[i] {
			if p-ps[i] >= 0 && dp[i-1][p-ps[i]] > 0 {
				dp[i][p] += dp[i-1][p-ps[i]]
			} else {
				dp[i][p] += dp[i-1][p]
			}
		}
	}

	count := 0
	for i := range dp[N] {
		if dp[N][i] > 0 {
			count++
		}
	}

	fmt.Println(count)
}

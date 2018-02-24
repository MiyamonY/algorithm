///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat Feb 24 18:11:43 2018
//
package main

import (
	"fmt"
)

func main() {
	var N, A int
	fmt.Scan(&N, &A)

	cards := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&cards[i])
	}

	dp := make([][][]int64, N+1)
	for i := range dp {
		dp[i] = make([][]int64, N+1)
		for j := range dp[i] {
			dp[i][j] = make([]int64, 2501)
		}
	}

	dp[0][0][0] = 1
	for i := 1; i <= N; i++ {
		for j := 0; j <= N; j++ {
			for k := 0; k <= 2500; k++ {
				if 0 <= j-1 && 0 <= k-cards[i] {
					dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-cards[i]]
				} else {
					dp[i][j][k] = dp[i-1][j][k]
				}
			}
		}
	}

	var count int64 = 0
	for i := 1; i <= N; i++ {
		count += dp[N][i][A*i]
	}

	fmt.Println(count)
}

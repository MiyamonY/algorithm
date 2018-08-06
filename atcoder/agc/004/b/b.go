///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun May  6 12:41:16 2018
//
package main

import (
	"fmt"
)

var N, x int64
var arr []int64

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N, &x)
	arr = make([]int64, N)
	for i := range arr {
		fmt.Scan(&arr[i])
	}

	dp := make([][]int64, N)
	for i := range dp {
		dp[i] = make([]int64, N)
	}
	for i := range dp[0] {
		dp[0][i] = arr[i]
	}

	var ans int64 = 1 << 60
	for k := int64(0); k < N; k++ {
		costs := int64(0)
		for i := int64(0); i < N; i++ {
			if k > 0 {
				dp[k][i] = min(dp[k-1][i], arr[(i-k+N)%N])
			}
			costs += dp[k][i]
		}
		ans = min(ans, x*k+costs)
	}

	fmt.Println(ans)
}

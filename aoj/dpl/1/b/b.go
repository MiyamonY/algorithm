///
// File:  b.go
// Author: ymiyamoto
//
// Created on Wed Mar 14 22:33:11 2018
//
package main

import (
	"fmt"
)

type item struct {
	v, w int
}

var N, W int
var items []item

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &W)

	items = make([]item, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&items[i].v, &items[i].w)
	}

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, W+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	dp[0][0] = 0
	for i := 1; i <= N; i++ {
		item := items[i]
		for w := 0; w <= W; w++ {
			if w-item.w >= 0 && dp[i-1][w-item.w] != -1 {
				dp[i][w] = max(dp[i-1][w], dp[i-1][w-item.w]+item.v)
			} else {
				dp[i][w] = dp[i-1][w]
			}
		}
	}

	max_val := 0
	for i := range dp[N] {
		max_val = max(max_val, dp[N][i])
	}

	fmt.Println(max_val)
}

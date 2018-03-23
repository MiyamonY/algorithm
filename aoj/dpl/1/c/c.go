///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri Mar 23 21:12:19 2018
//
package main

import (
	"fmt"
)

var N, W int

type item struct {
	v, w int
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &W)

	items := make([]item, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&items[i].v, &items[i].w)
	}

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, W+1)
	}

	for i := range items {
		v := items[i].v
		w := items[i].w
		for j := 0; j <= W; j++ {
			s := 0
			if 0 <= j-w {
				s = dp[i+1][j-w] + v
			}
			dp[i+1][j] = max(dp[i][j], s)
		}
	}

	m := 0
	for i := range dp[N] {
		m = max(m, dp[N][i])
	}

	fmt.Println(m)
}

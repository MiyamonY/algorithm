///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri Mar 23 20:57:07 2018
//
package main

import (
	"fmt"
)

var N, M int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &M)
	dp := make([][][]int, 100+1)
	for i := range dp {
		dp[i] = make([][]int, 100+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, 100+1)
		}
	}

	for i := 0; i < N; i++ {
		var a, b, c, w int
		fmt.Scan(&a, &b, &c, &w)
		dp[a][b][c] = max(dp[a][b][c], w)
	}

	for i := 0; i <= 100; i++ {
		for j := 0; j <= 100; j++ {
			for k := 0; k <= 100; k++ {
				dp[i][j][k] = max(dp[i][j][k], max(dp[max(0, i-1)][j][k], max(dp[i][max(0, j-1)][k], dp[i][j][max(0, k-1)])))
			}
		}
	}

	for i := 0; i < M; i++ {
		var x, y, z int
		fmt.Scan(&x, &y, &z)
		fmt.Println(dp[x][y][z])
	}
}

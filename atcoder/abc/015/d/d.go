///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat Mar 24 00:03:10 2018
//
package main

import (
	"fmt"
)

var W, N, K int

type image struct {
	A, B int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&W, &N, &K)

	images := make([]image, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&images[i].A, &images[i].B)
	}

	dp := make([][][]int, N+1)
	for i := range dp {
		dp[i] = make([][]int, N+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, N*100)
			for k := range dp[i][j] {
				dp[i][j][k] = 1 << 30
			}
		}
	}
	dp[0][0][0] = 0
	for n := range images {
		A := images[n].A
		B := images[n].B
		for k := 0; k < N; k++ {
			for b := 0; b < len(dp[n][k]); b++ {
				dp[n+1][k][b] = min(dp[n+1][k][b], dp[n][k][b])
				if 0 <= b-B {
					dp[n+1][k+1][b] = min(dp[n+1][k+1][b], dp[n][k][b-B]+A)
				}
			}
		}
	}

	m := 0
	for k := 0; k <= K; k++ {
		for b := 0; b < len(dp[N][k]); b++ {
			if dp[N][k][b] <= W {
				m = max(m, b)
			}
		}
	}

	fmt.Println(m)
}

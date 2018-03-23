///
// File:  2502.go
// Author: ymiyamoto
//
// Created on Sat Mar 24 00:44:45 2018
//
package main

import (
	"fmt"
)

type phrase struct {
	s, l, p int
}

const melody_len int = 393

var n, m int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&n)

	phrases := make([]phrase, n)
	max_count := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&phrases[i].s, &phrases[i].l, &phrases[i].p)
		max_count += phrases[i].l
	}

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, melody_len+1)
	}

	for i := range phrases {
		s := phrases[i].s
		l := phrases[i].l
		p := phrases[i].p
		for j := range dp[i] {
			for k := s; k <= l; k++ {
				if 0 <= j-k {
					dp[i+1][j] = max(dp[i+1][j], max(dp[i][j], dp[i+1][j-k]+p))
				} else {
					dp[i+1][j] = max(dp[i+1][j], dp[i][j])
				}
			}
		}
	}

	fmt.Scan(&m)
	var invalid bool
	var points []int
	for i := 0; i < m; i++ {
		var m int
		fmt.Scan(&m)
		if dp[n][m] == 0 {
			invalid = true
		}
		points = append(points, dp[n][m])
	}

	if invalid {
		fmt.Println(-1)
	} else {
		for _, p := range points {
			fmt.Println(p)
		}
	}
}

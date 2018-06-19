///
// File:  b.go
// Author: ymiyamoto
//
// Created on Mon Jun 18 17:17:48 2018
//
package main

import (
	"fmt"
)

var S string

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&S)

	dp := make([][][]int, len(S)+1)
	for i := range dp {
		dp[i] = make([][]int, len(S)+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, len(S)+1)
			for k := range dp[i][j] {
				dp[i][j][k] = 1 << 30
			}
		}
	}

	dp[0][0][0] = 0
	for i := 0; i < len(S); i++ {
		for j := 0; j < len(S); j++ {
			for k := 0; k < len(S); k++ {
				if dp[i][j][k] != 1<<30 {
					if S[i] == '(' {
						dp[i+1][j][k+1] = min(dp[i+1][j][k+1], dp[i][j][k])
						if k > 0 {
							dp[i+1][i][k-1] = min(dp[i+1][i][k-1], dp[i][j][k]+1)
						}
					} else {
						dp[i+1][i][k+1] = min(dp[i+1][i][k+1], dp[i][j][k]+1)
						if k > 0 {
							dp[i+1][j][k-1] = min(dp[i+1][j][k-1], dp[i][j][k])
						}
					}

				}
			}
		}
	}

	// for i := range dp {
	// 	fmt.Println(dp[i])
	// }

	ans := 1 << 30
	for i := range dp[len(S)] {
		ans = min(ans, dp[len(S)][i][0]+i)
	}
	fmt.Println(ans)
}

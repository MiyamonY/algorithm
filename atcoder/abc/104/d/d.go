// Package main provides
//
// File:  d.go
// Author: ymiyamoto
//
// Created on Mon Aug  6 23:20:43 2018
//
package main

import "fmt"

const MOD int = 1e9 + 7

var S string

func main() {
	fmt.Scan(&S)

	dp := make([][]int, len(S)+1)
	for i := range dp {
		dp[i] = make([]int, 4)
	}

	dp[len(S)][0] = 0
	dp[len(S)][1] = 0
	dp[len(S)][2] = 0
	dp[len(S)][3] = 1

	for i := len(S) - 1; i >= 0; i-- {
		dp[i][3] = dp[i+1][3]
		dp[i][2] = dp[i+1][2]
		dp[i][1] = dp[i+1][1]
		dp[i][0] = dp[i+1][0]

		if S[i] == '?' {
			dp[i][3] = 3 * dp[i+1][3]
			dp[i][2] = 3*dp[i+1][2] + dp[i+1][3]
			dp[i][1] = 3*dp[i+1][1] + dp[i+1][2]
			dp[i][0] = 3*dp[i+1][0] + dp[i+1][1]
		} else if S[i] == 'A' {
			dp[i][0] = dp[i+1][0] + dp[i+1][1]
		} else if S[i] == 'B' {
			dp[i][1] = dp[i+1][1] + dp[i+1][2]
		} else if S[i] == 'C' {
			dp[i][2] = dp[i+1][2] + dp[i+1][3]
		}

		for j := range dp[i] {
			dp[i][j] %= MOD
		}
	}

	fmt.Println(dp[0][0])
}

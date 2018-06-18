///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jun 17 01:30:42 2018
//
package main

import (
	"fmt"
)

var T string

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&T)

	dp := make([][]int, len(T)+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	dp[0][1] = -1
	for i := 1; i <= len(T); i++ {
		if T[i-1] == '?' {
			dp[i][0] = dp[i-1][1] + 1
			dp[i][1] = dp[i-1][0] + 1
		} else if T[i-1] == '2' {
			dp[i][0] = 0
			dp[i][1] = dp[i-1][0] + 1
		} else if T[i-1] == '5' {
			dp[i][0] = dp[i-1][1] + 1
			dp[i][1] = -1
		} else {
			dp[i][0] = 0
			dp[i][1] = -1
		}
	}
	//fmt.Println(dp)
	ans := 0
	for i := range dp {
		ans = max(ans, max(dp[i][0], dp[i][1]))
	}
	fmt.Println((ans / 2) * 2)
}

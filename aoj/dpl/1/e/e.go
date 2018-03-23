///
// File:  e.go
// Author: ymiyamoto
//
// Created on Thu Mar 22 21:22:19 2018
//
package main

import (
	"fmt"
)

var s1, s2 string

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func main() {
	fmt.Scan(&s1)
	fmt.Scan(&s2)

	dp := make([][]int, len(s1)+1)
	for i := range dp {
		dp[i] = make([]int, len(s2)+1)
	}

	for i := range dp {
		dp[i][0] = i
	}
	for j := range dp[0] {
		dp[0][j] = j
	}

	for i := range s1 {
		for j := range s2 {
			dist := 1
			if s1[i] == s2[j] {
				dist = 0
			}
			dp[i+1][j+1] = min(dp[i][j+1]+1, min(dp[i+1][j]+1, dp[i][j]+dist))
		}
	}

	fmt.Println(dp[len(s1)][len(s2)])
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Mar  7 22:15:30 2018
//
package main

import (
	"fmt"
)

var n, m int

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	fmt.Scan(&n, &m)
	arr := make([]int, m)

	for i := 0; i < m; i++ {
		fmt.Scan(&arr[i])
	}

	dp := make([]int, n+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = 1 << 30
	}
	dp[0] = 0
	for i := 0; i < len(dp); i++ {
		for _, val := range arr {
			if 0 <= i-val {
				dp[i] = min(dp[i], dp[i-val]+1)
			}
		}
	}

	fmt.Println(dp[n])
}

///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sun Jun 10 21:06:08 2018
//
package main

import (
	"fmt"
	"sort"
)

var N int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(a, b int) int {
	ans := 1
	for i := 0; i < b; i++ {
		ans *= a
	}
	return ans
}

func main() {
	fmt.Scan(&N)

	arr := []int{1, pow(6, 1), pow(6, 2), pow(6, 3), pow(6, 4), pow(6, 5), pow(6, 6), pow(6, 7), pow(9, 1), pow(9, 2), pow(9, 3), pow(9, 4), pow(9, 5), pow(9, 6)}
	sort.Ints(arr)

	dp := make([]int, N+1)
	for i := range dp {
		dp[i] = 1 << 30
	}
	dp[0] = 0
	for i := range dp {
		for j := range arr {
			if i-arr[j] >= 0 {
				dp[i] = min(dp[i], dp[i-arr[j]]+1)
			}
		}
	}

	fmt.Println(dp[N])
}

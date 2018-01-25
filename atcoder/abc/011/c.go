///
// File:  c.go
// Author: ymiyamoto
//
// Created on Thu Jan 25 22:18:50 2018
//
package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	var i1, i2, i3 int
	fmt.Scan(&i1, &i2, &i3)

	dp := make([]int, 301)
	for i := 0; i < len(dp); i++ {
		dp[i] = 1 << 30
	}
	dp[0] = 0

	for i := 0; i <= 300; i++ {
		if dp[i] == 1<<30 {
			continue
		}

		for _, s := range []int{1, 2, 3} {
			next := i + s
			if next <= 300 && next != i1 && next != i2 && next != i3 {
				dp[next] = min(dp[i]+1, dp[next])
			}
		}
	}

	if dp[N] <= 100 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

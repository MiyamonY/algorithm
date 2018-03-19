///
// File:  e.go
// Author: ymiyamoto
//
// Created on Mon Mar 19 19:31:01 2018
//
package main

import (
	"fmt"
	"strconv"
)

var n string
var D int
var mod int = 1e9 + 7

func main() {
	fmt.Scan(&D, &n)

	dp := make([][][]int, len(n)+1)
	for i := range dp {
		dp[i] = make([][]int, 2)
		for j := range dp[i] {
			dp[i][j] = make([]int, D)
		}
	}

	dp[0][0][0] = 1
	for i := 0; i < len(n); i++ {
		for less := 0; less <= 1; less++ {
			for d := 0; d < D; d++ {
				if less == 1 {
					for k := 0; k < 10; k++ {
						dp[i+1][1][(d+k)%D] += dp[i][1][d]
						dp[i+1][1][(d+k)%D] %= mod
					}
				} else {
					m, _ := strconv.Atoi(string(n[i]))
					for k := 0; k <= m; k++ {
						if k == m {
							dp[i+1][0][(d+k)%D] += dp[i][0][d]
							dp[i+1][0][(d+k)%D] %= mod
						} else {
							dp[i+1][1][(d+k)%D] += dp[i][0][d]
							dp[i+1][1][(d+k)%D] %= mod
						}
					}
				}
			}
		}
	}

	count := 0
	for i := range dp[len(n)] {
		count += dp[len(n)][i][0]
		count %= mod
	}

	fmt.Println(count - 1)
}

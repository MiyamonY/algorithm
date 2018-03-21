///
// File:  d.go
// Author: ymiyamoto
//
// Created on Thu Mar 22 01:03:08 2018
//
package main

import (
	"fmt"
)

var N string

func main() {
	fmt.Scan(&N)

	dp := make([][][]int64, len(N)+1)
	for i := range dp {
		dp[i] = make([][]int64, 2)
		for j := range dp[i] {
			dp[i][j] = make([]int64, len(N)+1)
		}
	}

	dp[0][0][0] = 1
	for n := 0; n < len(N); n++ {
		m := int(N[n] - '0')
		for less := 0; less <= 1; less++ {
			for num1 := 0; num1 < len(N); num1++ {
				if less == 1 {
					for v := 0; v <= 9; v++ {
						if v == 1 {
							dp[n+1][less][num1+1] += dp[n][less][num1]
						} else {
							dp[n+1][less][num1] += dp[n][less][num1]
						}
					}
				} else { // less == 0
					for v := 0; v <= m; v++ {
						if v == m {
							if v == 1 {
								dp[n+1][0][num1+1] += dp[n][0][num1]
							} else {
								dp[n+1][0][num1] += dp[n][0][num1]
							}
						} else {
							if v == 1 {
								dp[n+1][1][num1+1] += dp[n][0][num1]
							} else {
								dp[n+1][1][num1] += dp[n][0][num1]
							}
						}
					}
				}
			}
		}
	}

	var count int64
	for less := 0; less <= 1; less++ {
		for num1 := 1; num1 < len(dp[len(N)][less]); num1++ {
			count += int64(num1) * dp[len(N)][less][num1]
		}
	}

	fmt.Println(count)
}

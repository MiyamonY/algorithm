///
// File:  d.go
// Author: ymiyamoto
//
// Created on Mon Mar 19 20:47:03 2018
//
package main

import (
	"fmt"
	"strconv"
)

var A, B string

func invalids(n string) int64 {
	dp := make([][][]int64, len(n)+1)

	for i := range dp {
		dp[i] = make([][]int64, 2)
		for j := range dp[i] {
			dp[i][j] = make([]int64, 2)
		}
	}

	dp[0][0][0] = 1
	for i := 0; i < len(n); i++ {
		for less := 0; less <= 1; less++ {
			for invalid := 0; invalid <= 1; invalid++ {
				if less == 1 {
					if invalid == 1 {
						dp[i+1][1][1] += dp[i][1][1] * 10
					} else {
						for v := 0; v < 10; v++ {
							if v == 4 || v == 9 {
								dp[i+1][1][1] += dp[i][1][0]
							} else {
								dp[i+1][1][0] += dp[i][1][0]
							}
						}
					}
				} else {
					m, _ := strconv.Atoi(string(n[i]))
					for k := 0; k <= m; k++ {
						if invalid == 1 {
							if k < m {
								dp[i+1][1][1] += dp[i][0][1]
							} else {
								dp[i+1][0][1] += dp[i][0][1]
							}
						} else {
							if k < m {
								if k == 4 || k == 9 {
									dp[i+1][1][1] += dp[i][0][0]
								} else {
									dp[i+1][1][0] += dp[i][0][0]
								}
							} else {
								if k == 4 || k == 9 {
									dp[i+1][0][1] += dp[i][0][0]
								} else {
									dp[i+1][0][0] += dp[i][0][0]
								}
							}
						}
					}
				}
			}
		}
	}

	return dp[len(n)][0][1] + dp[len(n)][1][1]
}

func main() {
	fmt.Scan(&A, &B)

	var has_4_or_9 int64
	for i := range A {
		if A[i] == '4' || A[i] == '9' {
			has_4_or_9 = 1
		}
	}

	fmt.Println(invalids(B) - invalids(A) + has_4_or_9)
}

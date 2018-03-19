///
// File:  d.go
// Author: ymiyamoto
//
// Created on Thu Mar 15 23:04:46 2018
//
package main

import (
	"fmt"
)

var N int
var D int64

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)
	fmt.Scan(&D)

	J, K, L := 0, 0, 0
	for J = 0; ; J++ {
		if D%2 == 0 {
			D /= 2
		} else {
			break
		}
	}

	for K = 0; ; K++ {
		if D%3 == 0 {
			D /= 3
		} else {
			break
		}
	}

	for L = 0; ; L++ {
		if D%5 == 0 {
			D /= 5
		} else {
			break
		}
	}
	if D != 1 {
		fmt.Println(0)
		return
	}

	dp := make([][][][]float64, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([][][]float64, J+1)
		for j := range dp[i] {
			dp[i][j] = make([][]float64, K+1)
			for k := range dp[i][j] {
				dp[i][j][k] = make([]float64, L+1)
			}
		}
	}

	dp[0][0][0][0] = 1
	for i := 0; i < N; i++ {
		for j := 0; j <= J; j++ {
			for k := 0; k <= K; k++ {
				for l := 0; l <= L; l++ {
					for m := 1; m <= 6; m++ {
						switch m {
						case 1:
							dp[i+1][j][k][l] += dp[i][j][k][l] / 6
						case 2:
							dp[i+1][min(J, j+1)][k][l] += dp[i][j][k][l] / 6
						case 3:
							dp[i+1][j][min(K, k+1)][l] += dp[i][j][k][l] / 6
						case 4:
							dp[i+1][min(J, j+2)][k][l] += dp[i][j][k][l] / 6
						case 5:
							dp[i+1][j][k][min(L, l+1)] += dp[i][j][k][l] / 6
						case 6:
							dp[i+1][min(J, j+1)][min(K, k+1)][l] += dp[i][j][k][l] / 6
						}
					}
				}
			}
		}
	}

	fmt.Println(dp[N][J][K][L])
}

///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun May 20 12:45:59 2018
//
package main

import (
	"fmt"
)

const MOD int64 = 1e9 + 7

var H, W, A, B int64
var dp []int64

func pow(n, m int64) int64 {
	if m == 0 {
		return 1
	} else if m%2 == 0 {
		ret := pow(n, m/2) % MOD
		return (ret * ret) % MOD
	} else {
		return (n * pow(n, m-1)) % MOD
	}
}

func comb(n, k int64) int64 {
	return (((dp[n] * pow(dp[k], MOD-2)) % MOD) * pow(dp[n-k], MOD-2)) % MOD
}

func main() {
	fmt.Scan(&H, &W, &A, &B)

	dp = make([]int64, H+W+1)
	dp[0] = 1
	for i := 1; i < len(dp); i++ {
		dp[i] = (int64(i) * dp[i-1]) % MOD
	}

	var ans int64
	for i := B + 1; i <= W; i++ {
		ans += (comb(H-A+i-2, i-1) * comb(A+W-i-1, A-1)) % MOD
	}

	fmt.Println(ans % MOD)
}

///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jan 21 15:29:52 2018
//
package main

import "fmt"

const mod = 10007

var dp []int = make([]int, 1000001)

func tribonacchi(n int) int {
	if n > 3 {
		if t_n_1 := dp[n-1]; t_n_1 == 0 {
			t_n_1 = tribonacchi(n-1) % mod
			dp[n-1] = t_n_1
		}
		dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
	}
	return dp[n]
}

func main() {
	for i := 1; i <= 1000000; i++ {
		dp[i] = 0
	}
	dp[3] = 1

	var n int
	fmt.Scan(&n)
	fmt.Println(tribonacchi(n) % mod)
}

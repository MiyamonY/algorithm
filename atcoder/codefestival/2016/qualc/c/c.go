///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat May 26 17:04:42 2018
//
package main

import (
	"fmt"
)

const MOD int64 = 1e9 + 7

var N int
var T, A []int64

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)
	T = make([]int64, N)
	A = make([]int64, N)

	for i := range T {
		fmt.Scan(&T[i])
	}

	for i := range A {
		fmt.Scan(&A[i])
	}

	dp := make([]int64, N)
	for i := range T {
		if i != 0 {
			if T[i] != T[i-1] {
				dp[i] = 1
			} else {
				dp[i] = T[i]
			}
		} else {
			dp[i] = 1
		}

		if dp[i] == 1 && A[i] < T[i] {
			dp[i] = 0
		}
	}

	dp2 := make([]int64, N)
	for i := len(A) - 1; i >= 0; i-- {
		if i != len(A)-1 {
			if A[i] != A[i+1] {
				dp2[i] = 1
			} else {
				dp2[i] = A[i]
			}
		} else {
			dp2[i] = 1
		}
		if dp2[i] == 1 && T[i] < A[i] {
			dp2[i] = 0
		}
	}

	//fmt.Println(dp)
	//fmt.Println(dp2)

	ans := int64(1)
	for i := range dp {
		ans *= min(dp[i], dp2[i])
		ans %= MOD
	}
	fmt.Println(ans)
}

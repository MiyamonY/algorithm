///
// File:  b.go
// Author: ymiyamoto
//
// Created on Thu May 10 21:06:51 2018
//
package main

import (
	"fmt"
)

var N, K int
var arr []int64

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &K)

	arr = make([]int64, N)
	for i := range arr {
		fmt.Scan(&arr[i])
	}

	acc := make([]int64, N+1)
	acc2 := make([]int64, N+1)
	for i := range arr {
		acc[i+1] = acc[i] + arr[i]
		acc2[i+1] = acc2[i] + max(0, arr[i])
	}

	ans := int64(0)
	for i := 1; i+K-1 < len(acc); i++ {
		val := max(0, acc[i+K-1]-acc[i-1])
		if i > 0 {
			val += acc2[i-1] - acc2[0]
		}
		val += acc2[len(acc2)-1] - acc2[i+K-1]
		ans = max(ans, val)
	}
	fmt.Println(ans)
}

///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Mar 11 21:36:29 2018
//
package main

import (
	"fmt"
)

var N, K int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N, &K)

	count := 0
	for b := 1; b <= N; b++ {

		count += (N/b)*max(0, (b-1)-K+1) + max(0, (N%b)-K+1)
		if K == 0 {
			count--
		}
	}

	fmt.Println(count)
}

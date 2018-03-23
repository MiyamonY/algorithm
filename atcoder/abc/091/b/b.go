///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Mar 24 02:09:26 2018
//
package main

import (
	"fmt"
)

var N, M int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&N)

	blues := map[string]int{}
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		blues[s]++
	}
	fmt.Scan(&M)

	reds := map[string]int{}
	for i := 0; i < M; i++ {
		var s string
		fmt.Scan(&s)
		reds[s]++
	}

	m := 0
	for k, v := range blues {
		m = max(m, v-reds[k])
	}
	fmt.Println(max(0, m))
}

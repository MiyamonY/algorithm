///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Mar  1 21:56:03 2018
//
package main

import (
	"fmt"
)

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var N int
	fmt.Scan(&N)
	arr := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}

	m := 1 << 30
	for i := 0; i < (1 << uint(N)); i++ {
		a, b := 0, 0
		for j := 0; j < N; j++ {
			if i&(1<<uint(j)) == 0 {
				a += arr[j]
			} else {
				b += arr[j]
			}
		}
		m = min(m, max(a, b))
	}
	fmt.Println(m)
}

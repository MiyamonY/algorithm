///
// File:  b.go
// Author: ymiyamoto
//
// Created on Mon Apr  2 23:54:41 2018
//
package main

import (
	"fmt"
)

var N int
var A []int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)

	A := make([]int, N)
	count := 0
	num := 0
	for range A {
		var n int
		fmt.Scan(&n)
		if n == 0 {
			count += num / 2
			num = 0
		} else {
			num += n
		}
	}

	count += num / 2
	fmt.Println(count)
}

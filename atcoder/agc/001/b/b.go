///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  9 16:58:59 2018
//
package main

import "fmt"

var N, X int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func f(a, b int) int {
	if a < b {
		return f(b, a)
	} else if a == b {
		return a
	}
	n := max((a-b)/b, 1)
	return 2*n*b + f(a-n*b, b)
}

func main() {
	fmt.Scan(&N, &X)

	fmt.Println(N + f(X, N-X))
}

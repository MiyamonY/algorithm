///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 20:13:18 2018
//
package main

import (
	"fmt"
)

var N, M, L int
var P, Q, R int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func num(a, b, c int) int {
	return (N / a) * (M / b) * (L / c)
}

func main() {
	fmt.Scan(&N, &M, &L)
	fmt.Scan(&P, &Q, &R)

	fmt.Println(max(num(P, Q, R), max(num(P, R, Q), max(num(Q, P, R), max(num(Q, R, P), max(num(R, P, Q), num(R, Q, P)))))))
}

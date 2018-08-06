///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May  5 10:23:24 2018
//
package main

import (
	"fmt"
)

var N, A, B int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N, &A, &B)
	fmt.Println(B*min(5, N) + A*(N-min(5, N)))
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr  8 19:35:01 2018
//
package main

import (
	"fmt"
)

var Q, H, S, D int
var N int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&Q, &H, &S, &D)
	fmt.Scan(&N)

	num := N / 2
	cost := num * min(8*Q, min(4*H, min(2*S, D)))
	num = N % 2
	cost += num * min(4*Q, min(2*H, S))

	fmt.Println(cost)
}

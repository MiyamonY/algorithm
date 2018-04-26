///
// File:  b.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 09:52:29 2018
//
package main

import (
	"fmt"
)

var N, X int
var ms []int

func main() {
	fmt.Scan(&N, &X)
	ms = make([]int, N)

	total := 0
	min := 1 << 30
	for i := range ms {
		fmt.Scan(&ms[i])
		total += ms[i]
		if ms[i] < min {
			min = ms[i]
		}
	}
	fmt.Println(N + (X-total)/min)
}

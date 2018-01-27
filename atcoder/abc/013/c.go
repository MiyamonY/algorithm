///
// File:  c.go
// Author: ymiyamoto
//
// Created on Fri Jan 26 01:26:59 2018
//
package main

import (
	"fmt"
)

const EPS = 10e-6

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func more_than(a, b int64) int64 {
	return (a + b) / b
}

func main() {
	var N, H int64
	fmt.Scan(&N, &H)

	var A, B, C, D, E int64
	fmt.Scan(&A, &B, &C, &D, &E)

	min_cost := int64(1 << 62)
	for i := int64(0); i <= N; i++ {
		var j int64
		if H+B*i-(N-i)*E <= 0 {
			if (N-i)*E-H-B*i < 0 {
				j = 0
			} else {
				j = more_than((N-i)*E-H-B*i, D+E)
			}

			if j+i <= N {
				min_cost = min(min_cost, A*i+C*j)
			}
		}
		min_cost = min(min_cost, A*i+C*j)
	}

	fmt.Println(min_cost)
}

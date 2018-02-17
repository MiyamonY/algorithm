///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Feb 17 23:10:16 2018
//
package main

import (
	"fmt"
)

func main() {
	var N int
	var A, B float64
	fmt.Scan(&N, &A, &B)

	min := float64(1 << 31)
	max := 0.0
	total := 0.0
	for i := 0; i < N; i++ {
		var S float64
		fmt.Scan(&S)
		if S < min {
			min = S
		}
		if max < S {
			max = S
		}
		total += S
	}

	if max-min != 0 {
		P := B / (max - min)
		Q := A - P*total/float64(N)
		fmt.Printf("%.10f %.10f\n", P, Q)
	} else {
		fmt.Println(-1)
	}
}

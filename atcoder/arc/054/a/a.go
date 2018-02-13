///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Feb 13 21:54:52 2018
//
package main

import (
	"fmt"
)

func min(a, b float64) float64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var L, X, Y, S, D float64
	fmt.Scan(&L, &X, &Y, &S, &D)

	var dist, rdist float64

	if S < D {
		dist = D - S
		rdist = L - D + S
	} else {
		dist = L - S + D
		rdist = S - D
	}

	if Y > X {
		fmt.Printf("%.10f\n", min(dist/(Y+X), rdist/(Y-X)))
	} else {
		fmt.Printf("%.10f\n", dist/(Y+X))
	}
}

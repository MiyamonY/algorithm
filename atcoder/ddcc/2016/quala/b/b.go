///
// File:  b.go
// Author: ymiyamoto
//
// Created on Fri Jun  8 00:12:24 2018
//
package main

import (
	"fmt"
	"math"
)

var R float64
var N, M int

func max(a, b float64) float64 {
	if a < b {
		return b
	}
	return a
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Scan(&R, &N, &M)

	lengths := make([]float64, N)
	for i := range lengths {
		alpha := 2 * R / float64(N) * float64(i)
		if alpha <= R {
			alpha = R - alpha
		} else {
			alpha -= R
		}
		lengths[i] = 2 * math.Sqrt(R*R-alpha*alpha)
	}

	ans := 0.0
	for i := 1; i <= N+M-1; i++ {
		var v float64
		if 1 <= i && i <= N-1 {
			v = lengths[i]
		}
		var w float64
		if 1 <= i-M && i-M <= N-1 {
			w = lengths[i-M]
		}
		ans += max(v, w)
	}

	fmt.Printf("%.10f\n", ans)
}

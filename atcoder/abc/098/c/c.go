///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sat May 26 21:32:03 2018
//
package main

import (
	"fmt"
)

var N int
var S string

func main() {
	fmt.Scan(&N, &S)
	w := make([]int, N)
	e := make([]int, N)

	for i := range S {
		if S[i] == 'E' {
			w[i] += 1
		}
		if i != 0 {
			w[i] += w[i-1]
		}
	}

	for i := len(S) - 1; i >= 0; i-- {
		if S[i] == 'W' {
			e[i] += 1
		}
		if i != len(S)-1 {
			e[i] += e[i+1]
		}
	}

	min := 1 << 30
	for i := range w {
		var a, b int
		if 0 <= i-1 {
			a = w[i-1]
		}
		if i+1 < len(w) {
			b = e[i+1]
		}

		n := N - 1 - (a + b)
		if n < min {
			min = n
		}
	}

	fmt.Println(min)
}

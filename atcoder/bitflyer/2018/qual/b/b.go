///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 21:10:31 2018
//
package main

import "fmt"

var A, B, N int
var X string

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
func main() {
	fmt.Scan(&A, &B, &N)

	fmt.Scan(&X)

	for i := range X {
		switch X[i] {
		case 'S':
			A--
		case 'C':
			B--
		case 'E':
			if A < B {
				B--
			} else if A > B {
				A--
			} else {
				A--
			}
		}
	}

	fmt.Println(max(A, 0))
	fmt.Println(max(B, 0))
}

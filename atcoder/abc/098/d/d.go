///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat May 26 21:59:20 2018
//
package main

import (
	"fmt"
)

var N int
var A []int64

func main() {
	fmt.Scan(&N)

	A = make([]int64, N)
	for i := range A {
		fmt.Scan(&A[i])
	}

	var count int64
	l, r := 0, 0
	var acc int64
	for l < len(A) {
		for r < len(A) && acc^A[r] == acc+A[r] {
			acc += A[r]
			count++
			r++
		}
		acc ^= A[l]
		l++
		count += int64(r - l)
	}

	fmt.Println(count)
}

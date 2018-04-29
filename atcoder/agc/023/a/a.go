///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 21:02:42 2018
//
package main

import (
	"fmt"
)

var N int
var A []int

func main() {
	fmt.Scan(&N)

	A = make([]int, N)
	for i := range A {
		fmt.Scan(&A[i])
		if i > 0 {
			A[i] += A[i-1]
		}
	}
	count := 0
	m := map[int]int{}
	for i := len(A) - 1; i >= 0; i-- {
		a := A[i]
		if a == 0 {
			count++
		}
		count += m[a]
		m[a]++
	}

	fmt.Println(count)
}

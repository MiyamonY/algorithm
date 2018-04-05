///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr  5 19:20:40 2018
//
package main

import (
	"fmt"
)

var N, P int

func pow2(n int) int64 {
	ret := int64(1)
	for i := 0; i < n; i++ {
		ret *= 2
	}
	return ret
}

func main() {
	fmt.Scan(&N, &P)

	evens := 0
	odds := 0
	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		if A%2 == 0 {
			evens++
		} else {
			odds++
		}
	}

	if evens == N {
		if P == 0 {
			fmt.Println(pow2(N))
		} else {
			fmt.Println(0)
		}
	} else {
		fmt.Println(pow2(N - 1))
	}
}

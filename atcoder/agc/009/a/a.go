///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr  1 18:40:53 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	A := make([]int, N)
	B := make([]int, N)

	for i := range A {
		fmt.Scan(&A[i])
		fmt.Scan(&B[i])
	}

	count := 0
	for i := len(A) - 1; i >= 0; i-- {
		var n int
		if A[i]+count == 0 {
			n = 0
		} else {
			n = (A[i]+count-1)/B[i] + 1
		}

		count += n*B[i] - (A[i] + count)
	}
	fmt.Println(count)
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Apr  3 01:13:14 2018
//
package main

import (
	"fmt"
)

var N, A, B int

func main() {
	fmt.Scan(&N, &A, &B)
	if B < A {
		fmt.Println(0)
		return
	}
	if A != B && N == 1 {
		fmt.Println(0)
		return
	}

	fmt.Println(A + (N-1)*B - ((N-1)*A + B) + 1)
}

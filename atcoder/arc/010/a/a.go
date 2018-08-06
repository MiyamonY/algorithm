///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 18 21:13:21 2018
//
package main

import (
	"fmt"
)

var N, M, A, B int

func main() {
	fmt.Scan(&N, &M, &A, &B)
	for i := 0; i < M; i++ {
		if N <= A {
			N += B
		}

		var c int
		fmt.Scan(&c)
		N -= c
		if N < 0 {
			fmt.Println(i + 1)
			return
		}
	}

	fmt.Println("complete")
}

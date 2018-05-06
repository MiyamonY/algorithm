///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun May  6 11:55:12 2018
//
package main

import (
	"fmt"
)

var N, A, B, C, D int

func main() {
	fmt.Scan(&N, &A, &B, &C, &D)

	for m := 0; m < N; m++ {
		if (N-1-m)*C-m*D <= B-A && B-A <= (N-1-m)*D-m*C {
			fmt.Println("YES")
			return
		}
	}

	fmt.Println("NO")
}

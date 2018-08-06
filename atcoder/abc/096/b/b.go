///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat May  5 21:01:31 2018
//
package main

import (
	"fmt"
)

var A, B, C, K int

func pow2(n int) int {
	if n == 0 {
		return 1
	} else {
		return 2 * pow2(n-1)
	}
}

func main() {
	fmt.Scan(&A, &B, &C)
	fmt.Scan(&K)

	ans := 0
	if A < B {
		if B < C {
			ans = A + B + C*pow2(K)
		} else {
			ans = A + B*pow2(K) + C
		}
	} else {
		if A < C {
			ans = A + B + C*pow2(K)

		} else {
			ans = A*pow2(K) + B + C
		}
	}
	fmt.Println(ans)
}

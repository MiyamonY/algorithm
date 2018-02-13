///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Feb 13 21:21:36 2018
//
package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var A, B, K, L int
	fmt.Scan(&A, &B, &K, &L)

	fmt.Println(min(min(A*K, ((K/L)+1)*B), (K/L)*B+(K-L*(K/L))*A))
}

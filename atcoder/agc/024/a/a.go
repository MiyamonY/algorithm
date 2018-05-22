///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue May 22 22:13:49 2018
//
package main

import (
	"fmt"
)

var A, B, C, K int64

func main() {
	fmt.Scan(&A, &B, &C, &K)
	if K%2 == 0 {
		fmt.Println(A - B)
	} else {
		fmt.Println(B - A)
	}
}

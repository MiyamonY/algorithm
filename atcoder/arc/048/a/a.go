///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Feb 15 00:09:13 2018
//
package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	if 0 < A {
		fmt.Println(B - A)
	} else if A < 0 && 0 < B {
		fmt.Println(B - 1 - A)
	} else {
		fmt.Println(B - A)
	}
}

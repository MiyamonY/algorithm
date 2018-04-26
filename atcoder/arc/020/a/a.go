///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 21:11:17 2018
//
package main

import (
	"fmt"
)

var A, B int

func abs(a int) int {
	if 0 < a {
		return a
	}
	return -a
}

func main() {
	fmt.Scan(&A, &B)
	if abs(A) == abs(B) {
		fmt.Println("Draw")
	} else if abs(A) < abs(B) {
		fmt.Println("Ant")
	} else {
		fmt.Println("Bug")
	}
}

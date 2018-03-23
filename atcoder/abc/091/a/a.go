///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Mar 24 02:08:24 2018
//
package main

import (
	"fmt"
)

var A, B, C int

func main() {
	fmt.Scan(&A, &B, &C)

	if C <= A+B {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

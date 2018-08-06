///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri Jun  8 00:09:40 2018
//
package main

import "fmt"

var A, B, C float64

func main() {
	fmt.Scan(&A, &B, &C)

	fmt.Println(C * B / A)
}

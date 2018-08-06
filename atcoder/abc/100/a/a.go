///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Jun 16 23:14:44 2018
//
package main

import "fmt"

var A, B int

func main() {
	fmt.Scan(&A, &B)

	if A <= 8 && B <= 8 {
		fmt.Println("Yay!")
		return
	}
	fmt.Println(":(")
}

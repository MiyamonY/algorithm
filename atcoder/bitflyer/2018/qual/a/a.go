///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Jun  2 21:09:07 2018
//
package main

import "fmt"

var A, B int

func main() {
	fmt.Scan(&A, &B)

	var i int
	for i = 1; B*i <= A; i++ {
	}

	fmt.Println((i - 1) * B)
}

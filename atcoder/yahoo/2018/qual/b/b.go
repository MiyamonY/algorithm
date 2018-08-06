///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat Jun  9 19:53:07 2018
//
package main

import "fmt"

var X, K int

func main() {
	fmt.Scan(&X, &K)

	Y := 1
	for i := 0; i < K; i++ {
		Y *= 10
	}
	if X < Y {
		fmt.Println(Y)
	} else {
		fmt.Println(((X + Y) / Y) * Y)
	}
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Apr 18 21:03:19 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	ans := 0.0
	for i := 0; i < N; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		ans += float64(a*b) * 1.05
	}
	fmt.Println(int(ans))
}

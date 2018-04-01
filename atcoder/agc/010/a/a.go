///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Apr  1 19:07:52 2018
//
package main

import (
	"fmt"
)

var N int
var A []int

func main() {
	fmt.Scan(&N)

	A = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	count := 0
	for i := range A {
		if A[i]%2 == 1 {
			count++
		}
	}

	if count%2 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

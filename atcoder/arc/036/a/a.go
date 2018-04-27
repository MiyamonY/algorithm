///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 00:21:44 2018
//
package main

import (
	"fmt"
)

var N, K int
var a []int

func main() {
	fmt.Scan(&N, &K)
	a = make([]int, N)

	for i := range a {
		fmt.Scan(&a[i])
		if i >= 2 {
			count := a[i] + a[i-1] + a[i-2]
			if count < K {
				fmt.Println(i + 1)
				return
			}
		}
	}
	fmt.Println(-1)
}

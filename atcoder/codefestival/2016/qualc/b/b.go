///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sat May 26 17:48:59 2018
//
package main

import (
	"fmt"
)

var K, T int

func main() {
	fmt.Scan(&K, &T)
	a := make([]int, T)
	max := 0
	for i := range a {
		fmt.Scan(&a[i])
		if max < a[i] {
			max = a[i]
		}
	}

	n := max - 1
	if 0 < n-(K-max) {
		fmt.Println(n - (K - max))
	} else {
		fmt.Println(0)
	}
}

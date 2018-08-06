///
// File:  b.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 21:27:38 2018
//
package main

import (
	"fmt"
)

var N int
var as, bs []int

func main() {
	fmt.Scan(&N)
	as = make([]int, N)

	ops := 0
	for i := range as {
		fmt.Scan(&as[i])
		ops -= as[i]
	}

	bs = make([]int, N)
	for i := range bs {
		fmt.Scan(&bs[i])
		ops += bs[i]
	}

	count := 0
	for i := range as {
		if bs[i] > as[i] {
			count += ((bs[i] - as[i]) + 1) / 2
		}
	}

	if count <= ops {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

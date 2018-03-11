///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sun Mar 11 21:29:42 2018
//
package main

import (
	"fmt"
)

var N, M int64

func main() {
	fmt.Scan(&N, &M)

	var count int64
	if N == 1 && M == 1 {
		count = 1
	} else if N == 1 {
		count = M - 2
	} else if M == 1 {
		count = N - 2
	} else {
		count = (N - 2) * (M - 2)
	}
	fmt.Println(count)
}

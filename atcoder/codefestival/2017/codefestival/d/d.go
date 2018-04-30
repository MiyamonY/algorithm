///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sat Apr 28 18:47:33 2018
//
package main

import (
	"fmt"
)

var N, M int64

func gcd(a, b int64) int64 {
	if b > a {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	fmt.Scan(&N, &M)

	fmt.Println(M - gcd(N, M))
}

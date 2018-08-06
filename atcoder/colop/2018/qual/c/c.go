///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sun Jun  3 16:55:31 2018
//
package main

import "fmt"

var A, B int64

func gcd(a, b int64) int64 {
	if b > a {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func rec(i int64, arr []int64) int64 {
	if i > B {
		return 1
	}

	var invalid, has2, has3 bool
	for _, v := range arr {
		if v%2 == 0 {
			has2 = true
		}
		if v%3 == 0 {
			has3 = true
		}
		if gcd(i, v) != 1 {
			invalid = true
		}
	}

	if invalid || (has2 && i%2 == 0) || (has3 && i%3 == 0) {
		return rec(i+1, arr)
	}
	return rec(i+1, append(arr, i)) + rec(i+1, arr)
}

func main() {
	fmt.Scan(&A, &B)

	fmt.Println(rec(A, []int64{}))
}

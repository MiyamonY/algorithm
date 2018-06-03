///
// File:  b.go
// Author: ymiyamoto
//
// Created on Sun Jun  3 20:26:10 2018
//
package main

import "fmt"

var N, X int
var S string

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N, &X, &S)
	T := make([]int, N)
	ans := 0
	for i := range S {
		fmt.Scan(&T[i])
		if S[i] == '0' {
			ans += T[i]
		} else {
			ans += min(T[i], X)
		}
	}
	fmt.Println(ans)
}

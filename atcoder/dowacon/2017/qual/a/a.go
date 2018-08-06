///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Jun 18 17:07:49 2018
//
package main

import "fmt"

var n, a, b int

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	fmt.Scan(&n, &a, &b)
	fmt.Println(max(a+b-n, 0))
}

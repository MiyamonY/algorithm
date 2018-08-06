///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Apr 17 21:25:30 2018
//
package main

import (
	"fmt"
)

var N int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&N)

	fmt.Println(min((N/10+1)*100, (N/10)*100+(N%10)*15))
}

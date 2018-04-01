///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri Mar 30 07:33:26 2018
//
package main

import (
	"fmt"
)

var x, y int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&x, &y)

	count := 1 << 30
	if x <= y {
		count = min(count, y-x)
	}
	if -x <= y {
		count = min(count, y+x+1)
	}
	if x <= -y {
		count = min(count, -y-x+1)
	}
	if -x <= -y {
		count = min(count, -y+x+2)
	}

	fmt.Println(count)
}

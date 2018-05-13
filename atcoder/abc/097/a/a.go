///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun May 13 15:33:53 2018
//
package main

import (
	"fmt"
)

var a, b, c, d int

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Scan(&a, &b, &c, &d)
	if abs(a-c) <= d {
		fmt.Println("Yes")
		return
	} else if abs(a-b) <= d && abs(b-c) <= d {
		fmt.Println("Yes")
		return
	}
	fmt.Println("No")
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Fri Mar 30 07:49:32 2018
//
package main

import (
	"fmt"
)

var x, y, z int

func is_even(x int) bool {
	return x%2 == 0
}

func calc(a, b, c int) int {
	if a < b {
		if b < c {
			return a * b
		} else {
			return c * a
		}
	} else {
		if a < c {
			return a * b
		} else {
			return b * c
		}
	}
}

func main() {
	fmt.Scan(&x, &y, &z)
	if is_even(x) || is_even(y) || is_even(z) {
		fmt.Println(0)
	} else {
		fmt.Println(calc(x, y, z))
	}
}

///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr 30 16:15:46 2018
//
package main

import (
	"fmt"
)

var n int

func is_prime(a int) bool {
	if a == 1 {
		return false
	}
	for i := 2; i*i <= a; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Scan(&n)

	if is_prime(n * (n + 1) / 2) {
		fmt.Println("WANWAN")
	} else {
		fmt.Println("BOWWOW")
	}
}

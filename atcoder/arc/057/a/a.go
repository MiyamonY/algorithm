///
// File:  a.go
// Author: ymiyamoto
//
// Created on Tue Feb 13 21:31:09 2018
//
package main

import (
	"fmt"
)

func main() {
	var A, K int64
	fmt.Scan(&A, &K)

	if K == 0 {
		fmt.Println(2*1000000000000 - A)
		return
	}

	money := A
	count := 0
	for {
		if money >= 2*1000000000000 {
			break
		}
		money = 1 + (K+1)*money
		count++
	}

	fmt.Println(count)
}

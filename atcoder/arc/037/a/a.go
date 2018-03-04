///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sun Mar  4 20:42:57 2018
//
package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	count := 0
	for i := 0; i < N; i++ {
		var m int
		fmt.Scan(&m)
		if m < 80 {
			count += 80 - m
		}
	}

	fmt.Println(count)
}

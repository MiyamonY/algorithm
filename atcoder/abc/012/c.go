///
// File:  c.go
// Author: ymiyamoto
//
// Created on Thu Jan 25 22:59:12 2018
//
package main

import (
	"fmt"
)

func main() {
	total := 0
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			total += i * j
		}
	}

	var N int
	fmt.Scan(&N)

	diff := total - N

	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			if diff == i*j {
				fmt.Printf("%d x %d\n", i, j)
			}
		}
	}
}

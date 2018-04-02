///
// File:  b.go
// Author: ymiyamoto
//
// Created on Mon Apr  2 23:49:05 2018
//
package main

import (
	"fmt"
)

var N, M int

func main() {
	fmt.Scan(&N, &M)
	boxes := make([]int, N)
	reds := make([]bool, N)

	for i := range boxes {
		boxes[i] = 1
	}
	reds[0] = true
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		boxes[x]--
		boxes[y]++
		if reds[x] {
			reds[y] = true
		}
		if boxes[x] == 0 {
			reds[x] = false
		}
	}

	count := 0
	for i := range reds {
		if reds[i] {
			count++
		}
	}

	fmt.Println(count)
}

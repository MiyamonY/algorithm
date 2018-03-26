///
// File:  d.go
// Author: ymiyamoto
//
// Created on Sun Mar 25 21:33:43 2018
//
package main

import (
	"fmt"
)

var A, B int

func main() {
	fmt.Scan(&A, &B)
	A--
	B--

	square := make([][]string, 100)
	for i := range square {
		square[i] = make([]string, 100)
		for j := range square[i] {
			if j < 50 {
				square[i][j] = "#"
			} else {
				square[i][j] = "."
			}
		}
	}

	r, c := 0, 0
	for i := 0; i < A; i++ {
		square[r][c] = "."
		r += 2
		if 100 <= r {
			r = 0
			c += 2
		}
	}

	r, c = 0, 51
	for j := 0; j < B; j++ {
		square[r][c] = "#"
		r += 2
		if 100 <= r {
			r = 0
			c += 2
		}
	}

	fmt.Println(100, 100)
	for i := range square {
		for j := range square[i] {
			fmt.Print(square[i][j])
		}
		fmt.Println()
	}
}

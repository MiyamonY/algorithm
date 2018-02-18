///
// File:  c.go
// Author: ymiyamoto
//
// Created on Sun Feb 18 21:09:17 2018
//
package main

import (
	"fmt"
)

func main() {
	c := make([]int, 9)
	for i := 0; i < 9; i++ {
		fmt.Scan(&c[i])
	}

	for a1 := -1000; a1 <= 1000; a1++ {
		invalid := false
		b1 := c[0] - a1
		b2 := c[1] - a1
		b3 := c[2] - a1

		a2 := c[3] - b1
		if c[4]-b2 != a2 {
			invalid = true
		}
		if c[5]-b3 != a2 {
			invalid = true
		}

		a3 := c[6] - b1
		if c[7]-a3 != b2 {
			invalid = true
		}
		if c[8]-a3 != b3 {
			invalid = true
		}

		if !invalid {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")

	return
}

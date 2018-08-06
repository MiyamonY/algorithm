///
// File:  a.go
// Author: ymiyamoto
//
// Created on Mon Apr 30 16:34:50 2018
//
package main

import (
	"fmt"
)

var N, A, B int

func main() {
	fmt.Scan(&N, &A, &B)

	turn := true
	for 0 < N {
		if turn {
			if A <= N {
				N -= A
			} else {
				N = 0
			}
		} else {
			if B <= N {
				N -= B
			} else {
				N = 0
			}
		}
		if N == 0 {
			if turn {
				fmt.Println("Ant")
			} else {
				fmt.Println("Bug")
			}
			return
		}
		turn = !turn
	}
}

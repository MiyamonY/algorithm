///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr  5 20:22:53 2018
//
package main

import (
	"fmt"
)

var N int
var A []int

const (
	inc  = 0
	dec  = 1
	none = 2
)

func main() {
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	count := 0
	state := none
	for i := 1; i < len(A); i++ {
		if A[i-1] < A[i] {
			if state == dec {
				state = none
				count++
			} else if state == none {
				state = inc
			}
		} else if A[i-1] > A[i] {
			if state == inc {
				state = none
				count++
			} else if state == none {
				state = dec
			}
		}
	}

	fmt.Println(count + 1)
}

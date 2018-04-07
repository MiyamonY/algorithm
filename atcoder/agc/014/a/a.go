///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr  5 20:29:45 2018
//
package main

import (
	"fmt"
)

var A, B, C int

func main() {
	fmt.Scan(&A, &B, &C)
	if A%2 == 0 && A == B && B == C {
		fmt.Println(-1)
		return
	}

	count := 0
	for {
		if A%2 == 1 || B%2 == 1 || C%2 == 1 {
			break
		}
		A, B, C = B/2+C/2, A/2+C/2, A/2+B/2
		count++
	}
	fmt.Println(count)
}

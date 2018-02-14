///
// File:  a.go
// Author: ymiyamoto
//
// Created on Wed Feb 14 20:57:26 2018
//
package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scan(&S)

	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)

	for i := range S {
		if i == A || i == B || i == C || i == D {
			fmt.Print("\"")
		}
		fmt.Print(string(S[i]))
	}
	if D == len(S) {
		fmt.Print("\"")
	}

	fmt.Println()
}

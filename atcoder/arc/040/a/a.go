///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 22:55:18 2018
//
package main

import (
	"fmt"
)

var N int
var S []string

func main() {
	fmt.Scan(&N)
	S = make([]string, N)

	var takahashi, aoki int
	for i := range S {
		fmt.Scan(&S[i])
		for j := range S[i] {
			if S[i][j] == 'R' {
				takahashi++
			} else if S[i][j] == 'B' {
				aoki++
			}
		}
	}

	if takahashi == aoki {
		fmt.Println("DRAW")
	} else if takahashi < aoki {
		fmt.Println("AOKI")
	} else {
		fmt.Println("TAKAHASHI")
	}
}

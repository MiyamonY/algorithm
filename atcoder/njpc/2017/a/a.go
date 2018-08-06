///
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat May 12 10:21:26 2018
//
package main

import (
	"fmt"
)

var L int
var S string

func main() {
	fmt.Scan(&L, &S)

	for i := range S {
		if i < L {
			fmt.Print(string(S[i]))
		}
	}
	fmt.Println()
}

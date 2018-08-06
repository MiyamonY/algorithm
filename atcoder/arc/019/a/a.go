///
// File:  a.go
// Author: ymiyamoto
//
// Created on Thu Apr 26 21:06:20 2018
//
package main

import (
	"fmt"
)

var S string

func main() {
	fmt.Scan(&S)

	for i := range S {
		switch S[i] {
		case 'O', 'D':
			fmt.Print(0)
		case 'I':
			fmt.Print(1)
		case 'Z':
			fmt.Print(2)
		case 'S':
			fmt.Print(5)
		case 'B':
			fmt.Print(8)
		default:
			fmt.Print(string(S[i]))
		}
	}
	fmt.Println()
}
